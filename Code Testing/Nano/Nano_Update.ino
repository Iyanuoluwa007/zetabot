#include "LiquidCrystal_I2C.h"
#include <SPI.h> // to read from serial pin
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>
#include <SoftwareSerial.h>


String message0 = String("HELLO, I'M ZETABOT");
String message1 = String("Oke Iyanuoluwa Enoch");
String message2 = String("Mat No:- 1701326/17BD005101");
String message4 = String("Connecting ...");
String message5 = String("Bluetooth and Wifi Connected ");

int length0;
int length1;
int length2;
int length4;
int length5;

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
int speedDelay = 20;
int index = 0;
String dataIn = "";


void setup()
{

  Serial.begin(115200);

  // Lcd
  lcd.init();
  lcd.backlight();
  length0 = message0.length();
  length1 = message1.length();
  length2 = message2.length();
  length4 = message4.length();
  length5 = message5.length();


  // Introduction Message
  for (int i = 0; i < length0; i++)
  {
    ClearRow(0);
    lcd.print(message0.substring(i, i + 15));
    delay(500);
  }


  for (int i = 0; i < length1; i++)
  {
    ClearRow(0);
    lcd.print(message1.substring(i, i + 15));
    delay(500);
  }

  for (int i = 0; i < length2; i++)
  {
    ClearRow(1);
    lcd.print(message2.substring(i, i + 15));
    delay(500);
  }

  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(4);
  servo05.attach(3);
  servo06.attach(2);

  delay(20);

  // Send 90 degrees to servos before assembling servos

  // Robot arm initial position
  servo1PPos = 120; //65
  servo01.write(servo1PPos);
  delay(500);

  servo2PPos = 90; //70
  servo02.write(servo2PPos);
  delay(500);

  servo3PPos = 80; 
  servo03.write(servo3PPos);
  delay(500);


  servo4PPos = 20;
  servo04.write(servo4PPos);
  delay(500);

  servo5PPos = 120;
  servo05.write(servo5PPos);
  delay(500);

  servo6PPos = 10;
  servo06.write(servo6PPos);
  delay(500);


}

void loop()
{
  // Tank Messages
  // Forward Message
  if (Serial.available() > 0) {
    if (Serial.read() == 51) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moving Forward");
      delay(100);
    }
  }

  // Backward Message
  if (Serial.available() > 0) {
    if (Serial.read() == 52) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moving Backward");
      delay(100);
    }
  }

  // Left Message
  if (Serial.available() > 0) {
    if (Serial.read() == 53) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moving Left");
      delay(100);
    }
  }

  // Right Message
  if (Serial.available() > 0) {
    if (Serial.read() == 54) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moving Right");
      delay(100);
    }
  }

  // Stop Message
  if (Serial.available() > 0) {
    if (Serial.read() == 55) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moving Stopped");
      delay(100);
    }
  }

  // Arm Code
  // Roll
  if (Serial.available() > 0) {
    if (Serial.read() == 31) {
      servo1PPos = servo1PPos + 20;
      servo01.write(servo1PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Roll Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 32) {
      servo1PPos = servo1PPos - 20;
      servo01.write(servo1PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Roll Left");
    }
  }

  // Pitch
  if (Serial.available() > 0) {
    if (Serial.read() == 33) {
      servo2PPos = servo2PPos + 20;
      servo02.write(servo2PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pitch Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 34) {
      servo2PPos = servo2PPos - 20;
      servo02.write(servo2PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pitch Left");

    }
  }


 // Grip
  if (Serial.available() > 0) {
    if (Serial.read() == 35) {
      servo3PPos = servo3PPos + 20;
      servo03.write(servo3PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Grip Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 36) {
      servo3PPos = servo3PPos - 20;
      servo03.write(servo3PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Grip Left");
    }
  }


  // Elbow
  if (Serial.available() > 0) {
    if (Serial.read() == 37) {
      servo4PPos = servo4PPos + 20;
      servo04.write(servo4PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Elbow Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 38) {
      servo4PPos = servo4PPos - 20;
      servo04.write(servo4PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Elbow Left");
    }
  }

  // Shoulder
  if (Serial.available() > 0) {
    if (Serial.read() == 39) {
      servo5PPos = servo5PPos + 20;
      servo05.write(servo5PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Shoulder Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 40) {
      servo5PPos = servo5PPos - 20;
      servo05.write(servo5PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Shoulder Left");
    }
  }


  // Waist
  if (Serial.available() > 0) {
    if (Serial.read() == 41) {
      servo6PPos = servo6PPos + 20;
      servo06.write(servo6PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Waist Right");
    }
  }

  if (Serial.available() > 0) {
    if (Serial.read() == 42) {
      servo6PPos = servo6PPos - 20;
      servo06.write(servo6PPos);
      delay(10);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Waist Left");
    }
  }

}

void ClearRow(int rowNum)
{ lcd.setCursor(0, rowNum);
  lcd.print("                 ");
  lcd.setCursor(0, rowNum);
}
