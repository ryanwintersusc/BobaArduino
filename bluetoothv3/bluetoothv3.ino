#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX

#define pump 12 // pin 13 flickers at startup, so not safe to use with relay
                // check this out: https://forum.arduino.cc/index.php?topic=117895.0
#define tilt 11
#define kettle 10

// for motor delays
int honey = 0;
int firmness = 0;

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(tilt, OUTPUT);
  pinMode(kettle, OUTPUT);

  // Initialize outputs
  // pump and tilt are both active LOW, not HIGH
  digitalWrite(pump, HIGH); 
  digitalWrite(tilt, HIGH);
  digitalWrite(kettle, LOW);
  
  Serial.begin(9600);
  mySerial.begin(9600);

  digitalWrite(tilt, LOW);
  delay(1000);
  digitalWrite(tilt, HIGH);
}

void loop() {
  
  int oldByte = -1;
  int incomingByte = 0;
  
  if (Serial.available() > 0) {
    char data;
    //data = Serial.read();

    //works
    incomingByte = mySerial.read();//this line alone works
    //end works
    if (incomingByte != oldByte) {
      //Serial.print(incomingByte+5,HEX);
      //This comes through as the ascii value of the number, so 0 becomes 48, 3 becomes 51 etc.
      Serial.print(3, DEC);//https://www.arduino.cc/reference/en/language/functions/communication/serial/print/
      oldByte = incomingByte;
    }
  }
  
  int firmness = incomingByte/10;

//  digitalWrite(kettle, HIGH);//Turn on Kettle
//  //delay(3000);//Change this!
//  digitalWrite(kettle, LOW);//Turn off kettle
//
//  digitalWrite(tilt, HIGH);//Tilt on motor to tilt
//  //delay(3000);//Change this!
//  digitalWrite(tilt,LOW);//turn off motor to tilt

  //delay(3000);//time to settle

//  if (incomingByte != 0) {
//    honey = incomingByte % 10;
//    digitalWrite(pump, LOW); //turn on honey pump
//    delay(1000); //Change this!
//    digitalWrite(pump, HIGH); //turn off honey pump
//    delay(1000);
//  }

  
}
