#include <Servo.h>   // Подключаем библиотеку для сервоприводом
// Создаем объект для сервопривода 

Servo Pservo; 
Servo Lservo;
Servo Zservo;
 void setup() { 
   // Выбираем пин к которому подключен сервопривод 
   Pservo.attach(2);
  Lservo.attach(5);
  Zservo.attach(7);
   // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
   Pservo.write(73);  
   Lservo.write(70);  
   Zservo.write(10);  
   // Пауза 5 секунд 
delay(5000);    
}

void loop() { 
Pservo.write(73); // Поворот сервы на угол 90 градусов 
delay(20000); 
Lservo.write(70); // Поворот сервы на угол 90 градусов 
delay(20000);
Zservo.write(10); // Поворот сервы на угол 90 градусов 
delay(20000);

} 
