#include <AFMotor.h>

AF_DCMotor motor(4);

void setup() {
 
 

  motor.setSpeed(200);
 
  motor.run(выпуск);
}

void loop() {
  uint8_t i;
  
 
  
  motor.run(поступательный);
  for (i=0; i<255; i++) { // x++;увеличивает значение x на единицу и возвращает старое значение x

    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {// уменьшает значение x на единицу и возвращает старое значение x

    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(обратно);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("технология");
  motor.run(выпуск);
  delay(1000);
}
