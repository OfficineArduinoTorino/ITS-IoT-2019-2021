/* This example shows how to use MQTT on the main dev boards on the market
  HOW TO USE:
  under connect method, add your subscribe channels.
  under messageReceived (callback method) add actions to be done when a msg is received.
  to publish, call client.publish(topic,msg)
  in loop take care of using non-blocking method or it will corrupt.
  Alberto Perro & DG - Officine Innesto 2019

  Updated in order to be a go and return json communication example
  Node-RED to Arduino and back

  The payload from the Server is like this

  {
    "deviceID": "server",
    "check":"on",
    "name": "Pino",
    "status": "open",
    "pin": 2,
    "color": "red"
  }

  the client sends back evething plus is very own id.

  {
    "ID":"client",
    "ReceiverID":"server",
    "name":"Pino Daniele",
    "status":"open",
    "pin":2,"color":0
  }

*/

#define BROKER_IP    "ip-broker"
#define DEV_NAME     "mqttdevice"
#define MQTT_USER    ""
#define MQTT_PW      ""

const char ssid[] = "wifiNetwork";
const char pass[] = "wifiPassword";

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

String ID = "gate-1";

WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0;

#include <Arduino_JSON.h>

JSONVar Storage;
String jsonString = JSON.stringify(Storage);


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
  client.subscribe("/hello"); //SUBSCRIBE TO TOPIC /hello
}

void messageReceived(String &topic, String &payload) {

  // add the value of my property in the json I'm going to send back each second
  Storage["ID"] = ID;
  Serial.println("incoming: " + topic + " - " + payload);
  JSONVar myObject = JSON.parse(payload);
  //Serial.println(JSON.typeof(myObject));

  if (myObject.hasOwnProperty("deviceID")) {

    Serial.print("myObject[\"deviceID\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["ReceiverID"] = (const char*) myObject["deviceID"];

    Serial.println((const char*) myObject["deviceID"]);
  }

  if (myObject.hasOwnProperty("check")) {
    Serial.print("myObject[\"check\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["check"] = (const char*) myObject["check"];

    Serial.println((const char*) myObject["check"]);
  }

  if (myObject.hasOwnProperty("name")) {
    Serial.print("myObject[\"name\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["name"] = (const char*) myObject["name"];

    Serial.println((const char*) myObject["name"]);
  }

  if (myObject.hasOwnProperty("status")) {
    Serial.print("myObject[\"status\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["status"] = (const char*) myObject["status"];

    Serial.println((const char*) myObject["status"]);

    //   Serial.println(myObject["status"]);

  }

  if (myObject.hasOwnProperty("pin")) {
    Serial.print("myObject[\"pin\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["pin"] = (int) myObject["pin"];

    Serial.println((int) myObject["pin"]);
  }

  if (myObject.hasOwnProperty("color")) {
    Serial.print("myObject[\"color\"] = ");

    // add the value of my property in the json I'm going to send back each second
    Storage["color"] = (int) myObject["color"];

    Serial.println((const char*) myObject["color"]);
  }

  if (topic == "/hello") {
    if (String((const char*)myObject["status"]) == "open") {

      Serial.println("open");
      digitalWrite(LED_BUILTIN, HIGH);

    } else if (String((const char*)myObject["status"]) == "closed") {

      Serial.println("closed");
      digitalWrite(LED_BUILTIN, LOW);

    }


    if ((int) myObject["pin"] == 1) {

      Serial.println("open");
      digitalWrite(LED_BUILTIN, HIGH);

    } else if ((int) myObject["pin"] == 0) {

      Serial.println("closed");
      digitalWrite(LED_BUILTIN, LOW);

    }
    if (String((const char*)myObject["check"]) == "on") {


      client.publish("/hello", jsonString);

      Serial.println("on");
      //    Storage["check"] = (const char*) myObject["check"];
      Storage["check"] = "off";
    } else if (String((const char*)myObject["check"]) == "off") {

      Serial.println("off");

    }
  }


}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  pinMode(LED_BUILTIN, OUTPUT);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  //
  // MQTT brokers usually use port 8883 for secure connections.
  client.begin(BROKER_IP, 1884, net);
  client.onMessage(messageReceived);
  connect();
}
void loop() {
  
  client.loop();
  if (!client.connected()) {
    connect();
  }
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    //  client.publish("/hello", "world"); //PUBLISH TO TOPIC /hello MSG world

  }

  jsonString = JSON.stringify(Storage);

}
