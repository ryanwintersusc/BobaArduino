#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX

#define pump 12 // pin 13 flickers at startup, so not safe to use with relay
                // check this out: https://forum.arduino.cc/index.php?topic=117895.0
#define tilt 11
#define kettle 10

int firmness = 0;
int honey = 0;

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
}

void loop() {
    digitalWrite(pump,HIGH);//turn on honey pump
    delay(3000);//Change this!
    digitalWrite(pump,LOW);//turn off honey pump
    delay(3000);
  
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

    firmness = incomingByte/10;
    honey = incomingByte % 10;

    digitalWrite(kettle, HIGH);//Turn on Kettle
    //delay(3000);//Change this!
    digitalWrite(kettle, LOW);//Turn off kettle

    digitalWrite(tilt, HIGH);//Tilt on motor to tilt
    //delay(3000);//Change this!
    digitalWrite(tilt,LOW);//turn off motor to tilt

    //delay(3000);//time to settle
    
    // have not gotten this part to work correctly yet
    // seems like bluetooth always responding with '51'
    // and I do not know what that means
    digitalWrite(pump,HIGH);//turn on honey pump
    delay(honey*1000);//Change this!
    digitalWrite(pump,LOW);//turn off honey pump

  }
}
