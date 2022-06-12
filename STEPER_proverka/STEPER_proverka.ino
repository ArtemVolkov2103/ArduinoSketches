// не получилось двинуть мотор :(
#include <Stepper.h>

const int stepsPerRevolution = 200;  //64 для нашего мотора.

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  
  myStepper.setSpeed(500);  //до 700 
  }

void loop() {
  
  myStepper.step(200); //полный оборот 2050 примерно
  delay(3000);

 // myStepper.step(stepsPerRevolution);
  //delay(1000);
  //myStepper.step(-stepsPerRevolution);
  //delay(1000);

}

