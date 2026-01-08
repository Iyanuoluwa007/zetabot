
#include <FirebaseESP8266.h>
#include  <ESP8266WiFi.h>


#define ssid "Netflix"  //WiFi SSID
#define password "123qwerty"  //WiFi Password
#define FIREBASE_HOST "zeta-bot-default-rtdb.firebaseio.com"       //Firebase Project URL Remove "https:" , "\" and "/"
#define FIREBASE_AUTH "WhAQQpO9rOGHFWHLyCRUYfoWC8dXPDskkLJC0IaD"      //Firebase Auth Token

FirebaseData firebaseData;

//If using Relay Module
int Device_1 = D6; //initialize D6 Pin


void setup() {
  
 Serial.begin(9600);
   WiFi.begin (ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    pinMode(Device_1,OUTPUT);//initialize the Device OUTPUT  
    
}

void loop() {
  
  if (Firebase.get(firebaseData,"/A1/D1")) {
    if (firebaseData.dataType() == "string") {
      String De1 = firebaseData.stringData();
          if (De1=="1"){
              digitalWrite(Device_1,HIGH); //Device1 is ON
          }
          else if (De1=="0"){
              digitalWrite(Device_1,LOW);//Device1 if OFF
            }}}

  }
