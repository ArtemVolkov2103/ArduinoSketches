#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводом

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(3); //канал М2 на Motor Shield — задний правый 
 
// Создаем объект для сервопривода 
Servo myservo; 
  
void setup() { 
   // Выбираем пин к которому подключен сервопривод 
   myservo.attach(10); // или 10, если воткнули в крайний разъём 
   // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
   myservo.write(0);  
   // Пауза 5 секунд 
   delay(5000);   
}

void loop() { 
//Устанавливаем скорость 100% (0-255) 
motor1.setSpeed(100); 
motor2.setSpeed(100); 
  
// Задаем направление движение 
// FORWARD - вперед 
// BACKWARD - назад 
// RELEASE - стоп 
  
// Движение вперед в течении 5 секунд с поворотом сервы на угол 90 градусов 
motor1.run(FORWARD); 
motor2.run(FORWARD); 
myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 
  
motor1.run(RELEASE); 
motor2.run(RELEASE); 
delay(3000); 

// Поворот вправо в течении 2 секунд с поворотом сервы на угол 180 градусов

motor1.run(FORWARD); 
motor2.run(BACKWARD);  
myservo.write(180); // Поворот сервы на угол 180 градусов 
delay(1000);

motor1.run(RELEASE); 
motor2.run(RELEASE); 
delay(3000); 

// Движение назад в течении 5 секунд с поворотом сервы на угол 90 градусов 
motor1.run(BACKWARD); 
motor2.run(BACKWARD);
myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 
  
motor1.run(RELEASE); 
motor2.run(RELEASE); 
delay(3000); 
  
//Поворот влево в течении 2 секунд с поворотом сервы на угол 0 градусов

motor1.run(BACKWARD); 
motor2.run(FORWARD); 
myservo.write(0); // Поворот сервы на угол 0 градусов 
delay(1000); 
  
// Остановка двигателей на 3 секунды с поворотом сервы на угол 90 градусов 
motor1.run(RELEASE); 
motor2.run(RELEASE); 
myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 
}
