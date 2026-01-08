#include "LiquidCrystal_I2C.h"
#include <SPI.h> // to read from serial pin
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>

String message0 = String("HELLO, I'M ZETABOT");
String message1 = String("Oke Iyanuoluwa Enoch");
String message2 = String("Mat No:- 1701326/17BD005101");
String message4 = String("Connecting to network ...");


int length0;
int length1;
int length2;
int length4;

String Dir;

int pin1 = 5; // 5 - 10
int pin2 = 6;
int pin3 = 7;
int pin4 = 8;
int pin5 = 9;
int pin6 = 10;

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;



void setup()
{

  Serial.begin(2000000);

  // Servo Setup
  motor1.attach(pin1);
  motor2.attach(pin2);
  motor3.attach(pin3);
  motor4.attach(pin4);
  motor5.attach(pin5);
  motor6.attach(pin6);



  // Lcd
  lcd.init();
  lcd.backlight();
  length0 = message0.length();
  length1 = message1.length();
  length2 = message2.length();
  length4 = message4.length();  

  // Connecting and connected Message
    for (int i = 0; i < length4; i++){
    ClearRow(0);
    lcd.print(message4.substring(i, i + 15));
    
    delay(500);
  }

// Wifi Connected Message
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wifi Connected");
    delay(800);
    
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

}

void loop()
{
  // Forward Message
  if (Serial.available() >0) {
    if (Serial.read() == 51) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moving Forward");
    delay(500);
    }}

  // Backward Message
    if (Serial.available() >0) {
    if (Serial.read() == 52) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moving Backward");
    delay(500);
    }}

  // Left Message  
  if (Serial.available() >0) {
    if (Serial.read() == 53) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moving Left");
    delay(500);
    }}

  // Right Message
  if (Serial.available() >0) {
    if (Serial.read() == 54) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moving Right");
    delay(500);
    }}

  // Stop Message
  if (Serial.available() >0) {
    if (Serial.read() == 55) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Moving Stopped");
    delay(500);
    }}

}

void ClearRow(int rowNum)
{
  lcd.setCursor(0, rowNum);
  lcd.print("                 ");
  lcd.setCursor(0, rowNum);
}
