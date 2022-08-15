#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводом
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый 

// Создаем объект для сервопривода 
Servo myservo; 

 // Пины, используемые ультразвуковым дальномером 
const int vTrig = 2; 
const int vEcho = 4; 
// Переменные, для хранения данных с дальномера 
unsigned int vtime_us=0; 
unsigned int vdistance_sm=0; 
// Минимальное расстояние в сантиметрах, при котором нужно искать новый маршрут движения 
const int vmindistance = 30;


  
void setup() { 
   // Выбираем пин к которому подключен сервопривод 
   myservo.attach(9); // или 10, если воткнули в крайний разъём 
   // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
   myservo.write(0);    
}

void loop() { 
//Устанавливаем скорость 100% (0-255) 
motor1.setSpeed(255); 
motor2.setSpeed(255); 
 
  
// Задаем направление движение 
// FORWARD - вперед 
// BACKWARD - назад 
// RELEASE - стоп 
  
// Движение вперед в течении 5 секунд с поворотом сервы на угол 90 градусов 
myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 
  
// Поворот вправо в течении 2 секунд с поворотом сервы на угол 180 градусов

 
myservo.write(180); // Поворот сервы на угол 180 градусов 
delay(1000);

// Движение назад в течении 5 секунд с поворотом сервы на угол 90 градусов 

myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 
  
//Поворот влево в течении 2 секунд с поворотом сервы на угол 0 градусов

myservo.write(0); // Поворот сервы на угол 0 градусов 
delay(1000); 
  
// Остановка двигателей на 3 секунды с поворотом сервы на угол 90 градусов 

myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(1000); 

myservo.write(180); // Поворот сервы на угол 180 градусов 
motor1.run(FORWARD); 
  motor2.run(FORWARD); 
delay(1000);
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  delay(1000);
    motor1.run(BACKWARD); 
  motor2.run(BACKWARD);
delay(1000);
 motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  delay(1000);
}
