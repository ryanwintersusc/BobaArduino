#define tilt1 3
#define tilt2 4

void setup() {
  //pinMode(tilt1, OUTPUT);
  pinMode(tilt2, OUTPUT);

  // Initialize outputs to off state
  // pump active LOW, not HIGH
  //digitalWrite(tilt1, LOW); 
  digitalWrite(tilt2, LOW); 
}

void loop() {
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
  delay(1000);

  while (1) {}
}
  
