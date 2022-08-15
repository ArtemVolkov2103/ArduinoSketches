// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый 
int i;
int del=10;
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(250); 
  motor2.setSpeed(250); 
    motor1.run(RELEASE);
      motor2.run(RELEASE);
 
}

void loop() {
    
        motor1.run(FORWARD); 
      motor2.run(FORWARD); 
  for (i=0; i<255; i++) {
 motor1.setSpeed(i);
      motor2.setSpeed(i); 
       delay(del);
 }
 
  for (i=255; i!=0; i--) {
 motor1.setSpeed(i);
      motor2.setSpeed(i);    delay(del);
 }
  
  Serial.print("tock");

       motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
  for (i=0; i<255; i++) {
    motor1.setSpeed(i);
      motor2.setSpeed(i);  
  
    delay(del);
 }
 
  for (i=255; i!=0; i--) {
 motor1.setSpeed(i);
      motor2.setSpeed(i);     delay(del);
 }
  

  Serial.print("tech");
motor1.run(FORWARD); 
      motor2.run(FORWARD);
  delay(1000);
}
