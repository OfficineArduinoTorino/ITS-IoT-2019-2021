void messageReceived(String &topic, String &payload) {
  print_name(0, 20, "reading...");
  print_text(0, 20, intro);
 // Serial.println("incoming: " + topic + " - " + payload);
  JSONVar myObject = JSON.parse(payload);
  //Serial.println(JSON.typeof(myObject));

  delay(1000);

  if (myObject.hasOwnProperty("name")) {
    Serial.print("myObject[\"name\"] = ");
    user = myObject["name"];
    print_text(20, 60, user);
    Serial.println(myObject["name"]);
  }

  if (myObject.hasOwnProperty("status")) {
    Serial.print("myObject[\"status\"] = ");

    Serial.println((const char*) myObject["status"]);
    //   Serial.println(myObject["status"]);

  }

  if (myObject.hasOwnProperty("pin")) {
    Serial.print("myObject[\"pin\"] = ");

    Serial.println((int) myObject["pin"]);
  }

  if (myObject.hasOwnProperty("color")) {
    Serial.print("myObject[\"color\"] = ");

    Serial.println((const char*) myObject["color"]);
  }

  if (topic == "/ITS") {
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

  }
}
