#define pump 12

void setup() {
  pinMode(pump, OUTPUT);

  // Initialize outputs to off state
  // pump active LOW, not HIGH
  digitalWrite(pump, HIGH);
}

void loop() {
  digitalWrite(pump, LOW);
  delay(2000);
  digitalWrite(pump, HIGH);
  delay(2000);
}
  
