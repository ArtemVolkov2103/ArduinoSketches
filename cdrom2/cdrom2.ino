#include <AFMotor.h>
// Motor with 200 steps per rev (1.8 degree)
// to motor port #1 (M1 and M2)
AF_Stepper motor(200, 2);
void setup() {
// set up Serial library at 9600 bps
Serial.begin(9600);
Serial.println("Stepper test!");
motor.setSpeed(200); // 50 rpm
}
void loop() {
motor.step(102, FORWARD, MICROSTEP);
delay(1000);
motor.step(25, BACKWARD, MICROSTEP);
delay(1000);
motor.step(25, BACKWARD, MICROSTEP);
delay(1000);
motor.step(25, BACKWARD, MICROSTEP);
delay(1000);
motor.step(25, BACKWARD, MICROSTEP);
delay(1000);
}
