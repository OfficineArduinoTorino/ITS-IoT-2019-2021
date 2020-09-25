#include <Adafruit_NeoPixel.h>
#define LED_PIN 3
#define LED_COUNT 20
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

/*##################################### CONF DI MQTT ######################################*/

#define BROKER_IP    "192.168.1.57"
#define DEV_NAME     "mqttdevice"
#define MQTT_USER    "test"
#define MQTT_PW      "test"
const char ssid[] = "TIM-19640501";
const char pass[] = "gstSYZuwdfIaAwnVq5knVcaj";

/*############################### FINE CONFIGUURAZIONE MQTT ####################*/

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

WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0;

int mode = 0; // Questa variabile controlla il colore

/* ##################### Funzioni connessione  ############################*/

void connect() {
 Serial.print("Controllo Wi-Fi...");
 while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");
   delay(1000);
 }
 Serial.print("\nConnessione alla rete...");
 while (!client.connect(DEV_NAME, MQTT_USER, MQTT_PW)) {
   Serial.print(".");
   delay(1000);
 }
 Serial.println("\nCollegato correttamente!");
 client.subscribe("/controllo"); //SUBSCRIBE TO TOPIC /controllo
 Serial.println("\nTopic collegato!");
}

void messageReceived(String &topic, String &payload) {
 Serial.println("incoming: " + topic + " - " + payload);
 if(payload == "off")
  mode = 0;
 else 
   if (payload == "red"){
    Serial.println("red");
    mode = 1;
   }
    else
      if(payload == "green"){
        Serial.println("red");
        mode = 2;
      }
        else
          if(payload == "blue"){
            Serial.println("red");
            mode = 3;
          }
            else {
              Serial.println("white"); 
              mode = 4;
            }
            
}


/* ################### La lampada ############## */

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS
  Serial.begin(115200);
  Serial.println("\nAvvio/Reset lampada");
  WiFi.begin(ssid, pass);
  client.begin(BROKER_IP, 1883, net);
  client.onMessage(messageReceived);
  mode = 4; //Inizializziamo a bianco
  connect();
}

void loop() {
    client.loop();
    client.onMessage(messageReceived);
    switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0));    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   0,   0));    // Red
          break;
        case 2:
          colorWipe(strip.Color(  0, 255,   0));    // Green
          break;
        case 3:
          colorWipe(strip.Color(  0,   0, 255));    // Blue
          break;
        case 4:
          colorWipe(strip.Color(  255,  255, 255));    // White
          break;
    }
}


void colorWipe(uint32_t color) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
  }
}
