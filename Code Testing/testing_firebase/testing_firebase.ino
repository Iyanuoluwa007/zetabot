const char* ssid = "Netflix";
const char* password = "123qwerty";

#include "FirebaseESP32.h"
FirebaseData firebaseData;


String FIREBASE_HOST = "zeta-bot-default-rtdb.firebaseio.com";
String FIREBASE_AUTH = "WhAQQpO9rOGHFWHLyCRUYfoWC8dXPDskkLJC0IaD";

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.reconnectWiFi(true);
Firebase.setMaxRetry(firebaseData, 3);
Firebase.setMaxErrorQueue(firebaseData, 30);
Firebase.enableClassicRequest(firebaseData, true);


extern int gpLed =  4; // Light

int pin = 2;

void setup() {

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  pinMode(gpLed, OUTPUT);
  pinMode(pin, OUTPUT);

  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");

}


digitalWrite(gpLed, LOW);
digitalWrite(pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lightening button
  if (Firebase.get(firebaseData, "/9")) {
    if (firebaseData.dataType() == "string") {
      String De1 = firebaseData.stringData();
      if (De1 == "9") {
        digitalWrite(gpLed, HIGH); //Light is ON
      }
      else if (De1 == "3") {
        digitalWrite(gpLed, LOW); //Light if OFF
      }
    }
  }

    // Lightening button
  if (Firebase.get(firebaseData, "/4")) {
    if (firebaseData.dataType() == "string") {
      String De1 = firebaseData.stringData();
      if (De1 == "4") {
        digitalWrite(gpLed, HIGH); //Light is ON
      }
      else if (De1 == "5") {
        digitalWrite(gpLed, LOW); //Light if OFF
      }
    }
  }


}
