#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый 

void setup() {  
  // Пауза 5 секунд 
   delay(5000);   
}
  
void loop() { 
//Устанавливаем скорость (0-255) 
motor1.setSpeed(200);
motor2.setSpeed(200);
  
// Задаем направление движение 
// FORWARD - вперед 
// BACKWARD - назад 
// RELEASE - стоп 

  // Движение вперед в течении 5 секунд с поворотом сервы на угол 90 градусов 
motor1.run(FORWARD); 
motor2.run(FORWARD); 

delay(2000);

motor1.run(RELEASE); 
motor2.run(RELEASE);

delay(2000);

motor1.run(BACKWARD);

delay(2000); 

motor1.run(FORWARD);

delay(2000); 
}
