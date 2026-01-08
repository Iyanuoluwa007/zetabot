#include <WiFi.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "Base64.h"
#include "esp_camera.h"
#define CAMERA_MODEL_AI_THINKER // Has PSRAM


#define FIREBASE_HOST "zeta-bot-default-rtdb.firebaseio.com"  //Firebase Project
#define FIREBASE_AUTH "WhAQQpO9rOGHFWHLyCRUYfoWC8dXPDskkLJC0IaD" //Firebase Auth Token
#include "FirebaseESP32.h"


#define ssid "Netflix"  //WiFi SSID
#define password "123qwerty"  //WiFi Password


void startCameraServer();


// Set web server port number to 80
WiFiServer server(80);

FirebaseData firebaseData;

// GPIO Setting
extern int gpLb =  12; // Left 1 on Pin 12
extern int gpLf = 13; // Left 2 on Pin 13
extern int gpRb = 15; // Right 1 on Pin 15
extern int gpRf = 14; // Right 2 on Pin 14
extern int gpLed =  4; // Light on Pin 4(Inbuilt)


//Set your Static IP address
IPAddress local_IP(192, 168, 137, 180);
// Set your Gateway IP address
IPAddress gateway(192, 168, 137, 1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8); // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional


void setup() {
  Serial.begin(9600);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.write(".\n");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Serial.write("Wifi Connected\n");


  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  //drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_CIF);

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
  server.begin();



  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);


  pinMode(gpLb, OUTPUT); //Left Backward
  pinMode(gpLf, OUTPUT); //Left Forward
  pinMode(gpRb, OUTPUT); //Right Forward
  pinMode(gpRf, OUTPUT); //Right Backward
  pinMode(gpLed, OUTPUT); //Light

  //initialize
  digitalWrite(gpLb, LOW);
  digitalWrite(gpLf, LOW);
  digitalWrite(gpRb, LOW);
  digitalWrite(gpRf, LOW);
  digitalWrite(gpLed, LOW);


}

void loop() {
  // Lightening button
  if (Firebase.get(firebaseData, "/ZetaBot/LightButton")) {
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



  // Angle
  if (Firebase.get(firebaseData, "/ZetaBot/Angle")) {
    if (firebaseData.dataType() == "string") {
      String De101 = firebaseData.stringData();
      if (De101 == "\"1\"") {
        Serial.write("1\n");
      }
      else if (De101 == "\"2\"") {
        Serial.write("2\n");
      }
      else if (De101 == "\"5\"") {
        Serial.write("5\n");
      }
    }
  }


  // Forward
  if (Firebase.get(firebaseData, "/ZetaBot/UpButton")) {
    if (firebaseData.dataType() == "string") {
      String De2 = firebaseData.stringData();
      if (De2 == "8") {
        digitalWrite(gpRf, HIGH); //Forward
        digitalWrite(gpRb, LOW); //Forward
        digitalWrite(gpLf, HIGH); //Forward
        digitalWrite(gpLb, LOW); //Forward
        Serial.write("Forward\n");
      }
     else if (De2 == "0"){
        digitalWrite(gpRf, LOW); //Forward STOP
        digitalWrite(gpRb, LOW); 
        digitalWrite(gpLf, LOW); 
        digitalWrite(gpLb, LOW); 
     }
     }
    }
  


  // Backward
  if (Firebase.get(firebaseData, "/ZetaBot/DownButton")) {
    if (firebaseData.dataType() == "string") {
      String De3 = firebaseData.stringData();
      if (De3 == "2") {
        digitalWrite(gpRf, LOW); //Backward
        digitalWrite(gpRb, HIGH); //Backward
        digitalWrite(gpLf, LOW); //Backward
        digitalWrite(gpLb, HIGH); //Backward
        Serial.write("Backward\n");
      }
        else if (De3 == "0"){
        digitalWrite(gpRf, LOW); //Backward STOP
        digitalWrite(gpRb, LOW); 
        digitalWrite(gpLf, LOW); 
        digitalWrite(gpLb, LOW); 
     }
    }
  }

  // Left
  if (Firebase.get(firebaseData, "/ZetaBot/LeftButton")) {
    if (firebaseData.dataType() == "string") {
      String De4 = firebaseData.stringData();
      if (De4 == "4") {
        digitalWrite(gpRf, HIGH); //Left
        digitalWrite(gpRb, LOW); //Left
        digitalWrite(gpLf, LOW); //Left
        digitalWrite(gpLb, LOW); //Left
        Serial.write("Left\n");
      }
        else if (De4 == "0"){
        digitalWrite(gpRf, LOW); //Forward STOP
        digitalWrite(gpRb, LOW); 
        digitalWrite(gpLf, LOW); 
        digitalWrite(gpLb, LOW); 
     }
    }
  }

  // Right
  if (Firebase.get(firebaseData, "/ZetaBot/RightButton")) {
    if (firebaseData.dataType() == "string") {
      String De5 = firebaseData.stringData();
      if (De5 == "6") {
        digitalWrite(gpRf, LOW); //Right
        digitalWrite(gpRb, LOW); //Right
        digitalWrite(gpLf, HIGH); //Right
        digitalWrite(gpLb, LOW); //Right
        Serial.write("Right\n");
      }
        else if (De5 == "0"){
        digitalWrite(gpRf, LOW); //Forward STOP
        digitalWrite(gpRb, LOW); 
        digitalWrite(gpLf, LOW); 
        digitalWrite(gpLb, LOW); 
     }
    }
  }



  // Stop
  if (Firebase.get(firebaseData, "/ZetaBot/Stop")) {
    if (firebaseData.dataType() == "string") {
      String De6 = firebaseData.stringData();
      if (De6 == "5") {
        digitalWrite(gpRf, LOW); //Right
        digitalWrite(gpRb, LOW); //Right
        digitalWrite(gpLf, LOW); //Right
        digitalWrite(gpLb, LOW); //Right
        Serial.write("Stop\n");
      }
    }
  }


  // Servo 1
  if (Firebase.get(firebaseData, "/ZetaBot/RightRollDown")) {
    if (firebaseData.dataType() == "string") {
      String De7 = firebaseData.stringData();
      if (De7 == "16") {
        Serial.write("16\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftRollDown")) {
    if (firebaseData.dataType() == "string") {
      String De8 = firebaseData.stringData();
      if (De8 == "17") {
        Serial.write("17\n");
      }
    }
  }



  // Servo 2
  if (Firebase.get(firebaseData, "/ZetaBot/RightPitchDown")) {
    if (firebaseData.dataType() == "string") {
      String De9 = firebaseData.stringData();
      if (De9 == "18") {
        Serial.write("18\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftPitchDown")) {
    if (firebaseData.dataType() == "string") {
      String De10 = firebaseData.stringData();
      if (De10 == "19") {
        Serial.write("19\n");
      }
    }
  }


  // Servo 3
  if (Firebase.get(firebaseData, "/ZetaBot/RightGripDown")) {
    if (firebaseData.dataType() == "string") {
      String De11 = firebaseData.stringData();
      if (De11 == "20") {
        Serial.write("20\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftGripDown")) {
    if (firebaseData.dataType() == "string") {
      String De12 = firebaseData.stringData();
      if (De12 == "21") {
        Serial.write("21\n");
      }
    }
  }



  // Servo 4
  if (Firebase.get(firebaseData, "/ZetaBot/RightElbowDown")) {
    if (firebaseData.dataType() == "string") {
      String De13 = firebaseData.stringData();
      if (De13 == "22") {
        Serial.write("22\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftElbowDown")) {
    if (firebaseData.dataType() == "string") {
      String De14 = firebaseData.stringData();
      if (De14 == "23") {
        Serial.write("23\n");
      }
    }
  }




  // Servo 5
  if (Firebase.get(firebaseData, "/ZetaBot/RightShoulderDown")) {
    if (firebaseData.dataType() == "string") {
      String De15 = firebaseData.stringData();
      if (De15 == "24") {
        Serial.write("24\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftShoulderDown")) {
    if (firebaseData.dataType() == "string") {
      String De16 = firebaseData.stringData();
      if (De16 == "25") {
        Serial.write("25\n");
      }
    }
  }



  // Servo 6
  if (Firebase.get(firebaseData, "/ZetaBot/RightWaistDown")) {
    if (firebaseData.dataType() == "string") {
      String De17 = firebaseData.stringData();
      if (De17 == "26") {
        Serial.write("26\n");
      }
    }
  }

  if (Firebase.get(firebaseData, "/ZetaBot/LeftWaistDown")) {
    if (firebaseData.dataType() == "string") {
      String De18 = firebaseData.stringData();
      if (De18 == "27") {
        Serial.write("27\n");
      }
    }
  }

}
