
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

String readString;
#define in1 14    //Connect in1 to pin 14
#define in2 15    //Connect in2 to pin 15
#define in3 13   //Connect in3 to pin 13
#define in4 12   //Connect in4 to pin 12
#define in5 4   //Connect in5 to pin 4 LED

void setup()
{
  Serial.begin(115200);

  // Bluetooth device name
  SerialBT.begin("ZetaBot");
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(in1, OUTPUT);      //Set in1 as an output
  pinMode(in2, OUTPUT);      //Set in2 as an output
  pinMode(in3, OUTPUT);      //Set in3 as an output
  pinMode(in4, OUTPUT);      //Set in4 as an output
  pinMode(in5, OUTPUT);        //Set pin 4 as an output

  digitalWrite(in1, LOW);     //Switch in1 off
  digitalWrite(in2, LOW);     //Swtich in2 off
  digitalWrite(in3, LOW);     //Switch in3 off
  digitalWrite(in4, LOW);     //Swtich in4 off
  digitalWrite(in5, LOW);       //Swtich Pin 4 off
}
void loop()
{
  while (SerialBT.available())   //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = SerialBT.read();    //Conduct a serial read
    if (c == '#') {
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
  if (readString.length() > 0)
  {
    SerialBT.println(readString);

    if (readString == "4") {
      digitalWrite(in1, 1); // RF 14
      digitalWrite(in2, 0); // RB 15
      digitalWrite(in3, 0); // LF 13
      digitalWrite(in4, 1); // LB 12
      Serial.write(53);
      delay(10);

    }
    else if (readString == "6") {
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      digitalWrite(in3, 1);
      digitalWrite(in4, 0);
      Serial.write(54);
      delay(10);

    }
    else if (readString == "8") {
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      digitalWrite(in3, 1);
      digitalWrite(in4, 0);
      Serial.write(51);
      delay(10);

    }
    else if (readString == "2") {
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      digitalWrite(in3, 0);
      digitalWrite(in4, 1);
      Serial.write(52);
      delay(10);


    }
    else if (readString == "5") {
      digitalWrite(in1, 0);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0);
      Serial.write(55);
      delay(10);


    }
    // Tank Light
    else if (readString == "9") {
      digitalWrite(in5, HIGH);
      delay(10);
    }
    else if (readString == "3") {
      digitalWrite(in5, LOW);
      delay(10);
    }

    // Arm
    // Servo 1 Roll Right
    else if (readString == "17") {
      Serial.write(31);
      delay(10);
    }
    // Servo 2 Roll Left
    else if (readString == "16") {
      Serial.write(32);
      delay(10);
    }

    // Servo 2 Pitch Right
    else if (readString == "19") {
      Serial.write(33);
      delay(10);
    }
    // Servo2 Pitch Left
    else if (readString == "18") {
      Serial.write(34);
      delay(10);
    }

    // Servo 3 Grip Right
    else if (readString == "21") {
      Serial.write(35);
      delay(10);
    }
    // Servo3 Grip Left
    else if (readString == "20") {
      Serial.write(36);
      delay(10);
    }

    // Servo 4 Elbow Right
    else if (readString == "23") {
      Serial.write(37);
      delay(10);
    }
    // Servo 4 Elbow Left
    else if (readString == "22") {
      Serial.write(38);
      delay(10);
    }

    // Servo 5 Shoulder Right
    else if (readString == "25") {
      Serial.write(39);
      delay(10);
    }
    // Servo 5 Shoulder Left
    else if (readString == "24") {
      Serial.write(40);
      delay(10);
    }

    // Servo 6 Waist Right
    else if (readString == "27") {
      Serial.write(41);
      delay(10);
    }
    // Servo 6 Waist Left
    else if (readString == "26") {
      Serial.write(42);
      delay(10);
    }


  }
  readString = "";
}
