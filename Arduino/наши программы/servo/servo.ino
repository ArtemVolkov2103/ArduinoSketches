#include <Servo.h>   // Подключаем библиотеку для сервоприводом
// Создаем объект для сервопривода 
int X=1;
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
  


myservo.write(0); // Поворот сервы на угол 90 градусов 
delay(1000); 

myservo.write(180); // Поворот сервы на угол 180 градусов 

delay(3000);  

myservo.write(90); // Поворот сервы на угол 90 градусов 
delay(10000); 
} 
