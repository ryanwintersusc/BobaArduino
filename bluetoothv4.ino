#define pump   12 // pin 13 flickers at startup, so not safe to use with relay
                  // check this link: https://forum.arduino.cc/index.php?topic=117895.0
#define kettle 10
#define tilt1  4
#define tilt2  3

char data;

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(tilt1, OUTPUT);
  pinMode(tilt2, OUTPUT);
  pinMode(kettle, OUTPUT);

  // Initialize outputs to off state
  // pump active LOW, not HIGH
  digitalWrite(pump, HIGH); 
  digitalWrite(tilt1, LOW); 
  digitalWrite(tilt2, LOW); 
  digitalWrite(kettle, LOW);
  
  Serial.begin(9600);
}

// This works!
void loop() {
  
  if (Serial.available() > 0) {
    data = Serial.read();
    
    // First, send 'p', 't', or 'k', for pump, tilt, or kettle
    // Then, send 0-9 as char, multiply by 1000 for delay
    // subtracting '0' from char gives int value
    // while loop blocks until next char received (0-9)
    switch(data) {
      case 'p':
        while(!Serial.available()) {}
        data = Serial.read();
        
        digitalWrite(pump, LOW);
        delay( (data - '0')*1000 );
        digitalWrite(pump, HIGH);
        delay(1000);
        break;
        
      case 't':
//        while(!Serial.available()) {}
//        data = Serial.read();

        // tilts forward
        digitalWrite(tilt1, HIGH);
        digitalWrite(tilt2, LOW);
        delay(2000);
        digitalWrite(tilt1, LOW);
        delay(2000);

        // tilts backward
        digitalWrite(tilt2, HIGH);
        digitalWrite(tilt1, LOW);
        delay(2000);
        digitalWrite(tilt2, LOW);
        delay(2000);
        break;
        
      case 'k':
        while(!Serial.available()) {}
        data = Serial.read();
        
        digitalWrite(kettle, HIGH);
        delay( (data - '0')*1000 );
        digitalWrite(kettle, LOW);
        delay(1000);
        break;
    }
     
  }
    
}
  
