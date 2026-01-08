#include "LiquidCrystal_I2C.h"
#include <SPI.h> // to read from serial pin
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String message = String("Oke Iyanuoluwa E.");
String message2 = String("Mat No:- 1701326/17BD005101");
int length;
int length2;

int pin1 = 5; //D2
int pin2 = 6;
int pin3 = 7;
int pin4 = 8;
int pin5 = 9;
int pin6 = 10;

String Dir; //Direction of wheels

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;

void setup()
{

  motor1.attach(pin1);
  motor2.attach(pin2);
  motor3.attach(pin3);
  motor4.attach(pin4);
  motor5.attach(pin5);
  motor6.attach(pin6);


  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  length = message.length();
  length2 = message2.length();


}

void loop()
{

  for (int i = 0; i < length; i++)
  {
    ClearRow(0);
    lcd.print(message.substring(i, i + 15));
    delay(500);
  }
  for (int i = 0; i < length2; i++)
  {
    ClearRow(1);
    lcd.print(message2.substring(i, i + 15));
    delay(500);
  }


    lcd.clear();
    lcd.setCursor(0,0);   //Column 2 & Row 0
    lcd.print("Moving:- ");
    delay(1000);

    if(Serial.available() >0){
      Dir = Serial.read();
      lcd.clear();
      lcd.setCursor(0,1);   //Column 2 & Row 0
      lcd.print(Dir);
      delay(1000);
    }
}
void ClearRow(int rowNum)
{
  lcd.setCursor(0, rowNum);
  lcd.print("                 ");
  lcd.setCursor(0, rowNum);
}
 
  /*

  motor1.write(0);
  delay(5000);
  motor1.write(90);
  delay(5000);
  motor1.write(0);
  delay(5000);
  motor1.write(180);
  delay(5000);
  motor1.write(0);
  delay(5000);

  motor2.write(0);
  delay(5000);
  motor2.write(90);
  delay(5000);
  motor2.write(0);
  delay(5000);
  motor2.write(180);
  delay(5000);
  motor2.write(0);
  delay(5000);


  motor3.write(0);
  delay(5000);
  motor3.write(90);
  delay(5000);
  motor3.write(0);
  delay(5000);
  motor3.write(180);
  delay(5000);
  motor3.write(0);
  delay(5000);

  motor4.write(0);
  delay(5000);
  motor4.write(90);
  delay(5000);
  motor4.write(0);
  delay(5000);
  motor4.write(180);
  delay(5000);
  motor4.write(0);
  delay(5000);

  motor5.write(0);
  delay(5000);
  motor5.write(90);
  delay(5000);
  motor5.write(0);
  delay(5000);
  motor5.write(180);
  delay(5000);
  motor5.write(0);
  delay(5000);


  motor6.write(0);
  delay(5000);
  motor6.write(90);
  delay(5000);
  motor6.write(0);
  delay(5000);
  motor6.write(180);
  delay(5000);
  motor6.write(0);
  delay(5000);
 */
