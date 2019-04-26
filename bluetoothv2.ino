#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX

#define pump 13
#define tilt 12
#define kettle 11

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(tilt, OUTPUT);
  pinMode(kettle, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  digitalWrite(pump, HIGH);
  digitalWrite(tilt, LOW);
  digitalWrite(kettle, LOW);
}

void loop() {
  int oldByte = -1;
  if (Serial.available() > 0) {
    char data;
    //data = Serial.read();

    //works
    int incomingByte = mySerial.read();//this line alone works
    //end works
    if (incomingByte != oldByte) {
      //Serial.print(incomingByte+5,HEX);
      //This comes through as the ascii value of the number, so 0 becomes 48, 3 becomes 51 etc.
      Serial.print(3, DEC);//https://www.arduino.cc/reference/en/language/functions/communication/serial/print/
      oldByte = incomingByte;
    }



    switch (incomingByte)
    {
      case 0:
        digitalWrite(pump, HIGH);
        break;
      case 1:
        digitalWrite(pump, LOW);
        break;
      case 2:
        digitalWrite(tilt, HIGH);
        break;
      case 3:
        digitalWrite(tilt, LOW);
        break;
      case 4:
        digitalWrite(tilt, HIGH);
        break;
      case 5:
        digitalWrite(tilt, LOW);
        break;
      default:
        //digitalWrite(6,LOW);
        break;
    }
  }
}
