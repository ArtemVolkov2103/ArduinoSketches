void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop() {
    delay(1000);

  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(0, HIGH);
  digitalWrite(2, HIGH);

  delay(1000);
  
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);

}
