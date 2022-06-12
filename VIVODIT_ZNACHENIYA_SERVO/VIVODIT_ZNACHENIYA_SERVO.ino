#include <Servo.h>

Servo myserva;
int abc;
int cba;

void setup() {
myserva.attach(9);

Serial.begin(9600);
}

void loop() {
if (Serial.available()){
 abc=Serial.parseInt();
 
 myserva.write(abc);
 Serial.println(abc);
}
}
