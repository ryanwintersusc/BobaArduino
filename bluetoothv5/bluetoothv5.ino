#define pump   12 // pin 13 flickers at startup, so not safe to use with relay
                  // check this link: https://forum.arduino.cc/index.php?topic=117895.0
#define kettle 10
#define tilt1  3
#define tilt2  4

char data;

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(tilt2, OUTPUT);
  pinMode(kettle, OUTPUT);

  // Initialize outputs to off state
  // pump active LOW, not HIGH
  digitalWrite(pump, HIGH); 
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

    // tilt forward
    analogWrite(tilt1, 191);
    digitalWrite(tilt2, LOW);
    delay(5500);
    analogWrite(tilt1, 0);
    delay(1000);
  
    // tilt backward
    digitalWrite(tilt2, HIGH);
    analogWrite(tilt1, 0);
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
  
