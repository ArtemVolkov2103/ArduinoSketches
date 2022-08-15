void setup() {
Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}
char inByte;
void loop() {
if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if(inByte == 'r')   digitalWrite(LED_BUILTIN, HIGH);
    if(inByte == 'l')   digitalWrite(LED_BUILTIN, LOW);
    if(inByte == 'f')   digitalWrite(LED_BUILTIN, 128);

    //Serial.println(inByte);
    }
}
