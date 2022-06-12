 // ТУТ 2 ШАГОВЫХ МОТОРА РИСУЮТ КВАДРАТ

#include <AFMotor.h>


AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

void setup() {

motor1.setSpeed(200); // 
motor2.setSpeed(200); // 

}
void loop() {
motor1.step(70, FORWARD, MICROSTEP);
delay(2000);
motor2.step(70, FORWARD, MICROSTEP);
delay(2000);
motor1.step(70, BACKWARD, MICROSTEP);
delay(2000);
motor2.step(70, BACKWARD, MICROSTEP);
delay(6000);
}
