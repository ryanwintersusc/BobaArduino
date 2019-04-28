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
    
    // receive 1, 2, or 3 and convert to int
    int firmness = atoi(data);

    // receive second char 
    while(!Serial.available()) {}
    data = Serial.read();
    
    // 0, 1, 2, or 3
    int honey = atoi(data);

    // MAIN control loop
    // turns on kettle
    digitalWrite(kettle, HIGH);
    delay((firmness*10000) + 190000);
    digitalWrite(kettle, LOW);

    // wait after turning off kettle
    delay(5000);

    // tilts forward
    digitalWrite(tilt1, HIGH);
    digitalWrite(tilt2, LOW);
    delay(4000);
    digitalWrite(tilt1, LOW);
    delay(1000);

    // tilts backward
    digitalWrite(tilt2, HIGH);
    digitalWrite(tilt1, LOW);
    delay(4000);
    digitalWrite(tilt2, LOW);

    // wait after tilting done
    delay(5000);
    
    digitalWrite(pump, LOW);
    delay(honey*2000);
    digitalWrite(pump, HIGH);
    delay(1000);
     
  }
    
}
  
