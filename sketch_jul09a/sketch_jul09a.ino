void setup() {
  Serial.begin(115200);

}
int i = 0;
void loop() {
  static uint32_t tmr;
  for(i; i<200; i++)
  if(millis() - tmr >= 11) {
    Serial.println(i);
    tmr = millis();  // сброс таймера
  }

for(i; i>=200; i--)
  if(millis() - tmr >= 11) {    Serial.println(i);
    tmr = millis();  // сброс таймера
  }
}
