/**************************************************************************/
/*!
    This example will wait for any ISO14443A card or tag, and
    depending on the size of the UID will attempt to read from it.

    If the card has a 4-byte UID it is probably a Mifare
    Classic card, and the following steps are taken:

    - Authenticate block 4 (the first block of Sector 1) using
      the default KEYA of 0XFF 0XFF 0XFF 0XFF 0XFF 0XFF
    - If authentication succeeds, we can then read any of the
      4 blocks in that sector (though only block 4 is read here)

    If the card has a 7-byte UID it is probably a Mifare
    Ultralight card, and the 4 byte pages can be read directly.
    Page 4 is read by default since this is the first 'general-
    purpose' page on the tags.

    To enable debug message, define DEBUG in PN532/PN532_debug.h
*/
/**************************************************************************/

#define BROKER_IP    "broker.hivemq.com"
#define DEV_NAME     "mqttdevice"
#define MQTT_USER    ""
#define MQTT_PW      ""


const char ssid[] = "wifi-network";
const char pass[] = "wifi-password";


#include <MQTT.h>

#ifdef ARDUINO_SAMD_MKRWIFI1010
#include <WiFiNINA.h>
#elif ARDUINO_SAMD_MKR1000
#include <WiFi101.h>
#elif ESP8266
#include <ESP8266WiFi.h>
#else
#error unknown board
#endif

#include <Arduino_JSON.h>

WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0;

// Oled Screen Stuff

// U8g2lib reference: https://github.com/olikraus/u8g2/wiki/u8g2reference

#include <U8g2lib.h>  // Install the U8g2 by searching it by name in the Library Manager.
// Documentation: https://github.com/olikraus/u8g2/wiki/u8g2reference

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(             U8G2_R0,
    /* clock=*/ SCL,
    /* data=*/  SDA,
    /* reset=*/ U8X8_PIN_NONE);


String intro = "swipe cards";
String user = "";


void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(DEV_NAME, MQTT_USER, MQTT_PW)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nconnected!");
  client.subscribe("/ITS"); //SUBSCRIBE TO TOPIC /hello
}





#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include "PN532.h"

PN532_SPI pn532spi(SPI, 10);
PN532 nfc(pn532spi);
#elif 1
#include <PN532_HSU.h>
#include <PN532.h>

PN532_HSU pn532hsu(Serial1);
PN532 nfc(pn532hsu);
#else
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);
#endif


void setup(void) {
  u8g2.begin();
  u8g2.setDisplayRotation(U8G2_R2);   // 180 degree clockwise rotation

  u8g2.setFont(u8g2_font_tenthinnerguys_t_all); // Find more fonts at https://github.com/olikraus/u8g2/wiki/fntlistall
  // They are listed by font height in pixels.
  u8g2.clearBuffer(); // clean the display
  Serial.begin(115200);
  Serial.println("Hello!");
  u8g2.setFont(u8g2_font_helvB18_tf);
  u8g2.drawStr(20, 30, "Hello World!");
  u8g2.sendBuffer();

  WiFi.begin(ssid, pass);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  //
  // MQTT brokers usually use port 8883 for secure connections.
  client.begin(BROKER_IP, 1883, net);
  client.onMessage(messageReceived);
  connect();

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Waiting for an ISO14443A Card ...");
  print_text(0, 20, intro);
}


void loop(void) {

  u8g2.clearBuffer(); // clean the display

  JSONVar readings;

  //print_name(0, 20 , user);
  //print_name(0, 20 , "swipe Cards");

   /* if (user == "") {
      print_text(20, 60, "Swipe Cards");


    } else {

      print_text(20, 60, user);

    }
    */
    delay(1000);
    u8g2.clearBuffer(); // clean the display

    Serial.println(user);
    readings["id"] = "Accesso 1";


    client.loop();
    if (!client.connected()) {
      connect();
    }

    //  if (millis() - lastMillis > 1000) {
    //    lastMillis = millis();
    //    client.publish("/hello", "world"); //PUBLISH TO TOPIC /hello MSG world
    //    }

    uint8_t success;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
    uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

    // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
    // 'uid' will be populated with the UID, and uidLength will indicate
    // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
    success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

    if (success > 0) {
      // Display some basic information about the card
      Serial.println("Found an ISO14443A card");
      Serial.print("  UID Length: "); Serial.print(uidLength, DEC); Serial.println(" bytes");
      Serial.print("  UID Value: ");
      nfc.PrintHex(uid, uidLength);

      Serial.println(uid[0], DEC);
      Serial.println(uid[0], HEX);



      Serial.println("");

      if (uidLength == 4)
      {
        // Code to String

        String code = String(uid[0]);
        code += String(uid[1]);
        code += String(uid[2]);
        code += String(uid[3]);


        print_text(0, 20, code);

        Serial.print("code = ");
        Serial.print(code);
        readings["lenght"] = uidLength;
        readings["tessera"] = code;
        String jsonString = JSON.stringify(readings);
        client.publish("/hello", jsonString);
        Serial.println(" - - - - - ");

        // We probably have a Mifare Classic card ...
        Serial.println("Seems to be a Mifare Classic card (4 byte UID)");

        // Now we need to try to authenticate it for read/write access
        // Try with the factory default KeyA: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
        Serial.println("Trying to authenticate block 4 with default KEYA value");
        uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

        // Start with block 4 (the first block of sector 1) since sector 0
        // contains the manufacturer data and it's probably better just
        // to leave it alone unless you know what you're doing
        success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);

        if (success)
        {
          Serial.println("Sector 1 (Blocks 4..7) has been authenticated");
          uint8_t data[16];

          // If you want to write something to block 4 to test with, uncomment
          // the following line and this text should be read back in a minute
          // data = { 'a', 'd', 'a', 'f', 'r', 'u', 'i', 't', '.', 'c', 'o', 'm', 0, 0, 0, 0};
          // success = nfc.mifareclassic_WriteDataBlock (4, data);

          // Try to read the contents of block 4
          success = nfc.mifareclassic_ReadDataBlock(4, data);

          if (success)
          {
            // Data seems to have been read ... spit it out
            Serial.println("Reading Block 4:");
            nfc.PrintHexChar(data, 16);
            Serial.println("");

            // Wait a bit before reading the card again
            delay(1000);
          }
          else
          {
            Serial.println("Ooops ... unable to read the requested block.  Try another key?");
          }
        }
        else
        {
          Serial.println("Ooops ... authentication failed: Try another key?");
        }
      }

      if (uidLength == 7)
      {
        // Code to String

        String code = String(uid[0]);
        code += String(uid[1]);
        code += String(uid[2]);
        code += String(uid[3]);
        code += String(uid[4]);
        code += String(uid[5]);
        code += String(uid[6]);

        print_name(0, 20, code);

        Serial.print("code = ");
        Serial.print(code);
        readings["lenght"] = uidLength;
        readings["tessera"] = code;
        String jsonString = JSON.stringify(readings);
        client.publish("/ITS", jsonString);
        Serial.println(" - - - - - ");


        u8g2.clearBuffer(); // clean the display
        // We probably have a Mifare Ultralight card ...
        Serial.println("Seems to be a Mifare Ultralight tag (7 byte UID)");

        // Try to read the first general-purpose user page (#4)
        Serial.println("Reading page 4");
        uint8_t data[32];
        success = nfc.mifareultralight_ReadPage (4, data);
        if (success)
        {
          // Data seems to have been read ... spit it out
          nfc.PrintHexChar(data, 4);
          Serial.println("");

          // Wait a bit before reading the card again
          delay(1000);
        }
        else
        {
          Serial.println("Ooops ... unable to read the requested page!?");
        }
      }
    }
  }
