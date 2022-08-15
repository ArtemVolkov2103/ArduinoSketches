
#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводом

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(3); //канал М2 на Motor Shield — задний правый

  
// Создаем объект для сервопривода 
Servo myservo; 

const int Trig = 2; 
const int Echo = 4; 


void setup() 
{   
  // Выбираем пин к которому подключен сервопривод 
   myservo.attach(10); // или 10, если воткнули в крайний разъём 
   // Поворачиваем сервопривод в положение 90 градусов при каждом включении 
   myservo.write(90);  
   
   
   
 

Serial.begin(9600); 
}

unsigned int time_us=0;

unsigned int distance_sm=0;


 void loop() {
//Устанавливаем скорость 100% (0-255) 
motor1.setSpeed(255); 
motor2.setSpeed(255);


pinMode(Trig, OUTPUT); 
pinMode(Echo, INPUT); 
 
 
digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
delayMicroseconds(100); // Удерживаем 10 микросекунд 
digitalWrite(Trig, LOW); // Затем убираем 
time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
distance_sm=time_us/58; // Пересчитываем в сантиметры 
Serial.println(distance_sm); // Выводим на порт

if (distance_sm<25) // Если расстояние менее 50 сантиметром 
{ 
 motor1.run(BACKWARD); 
 motor2.run(BACKWARD);
delay(1000);


} 
else 
{ 
motor1.run(FORWARD); 
motor2.run(FORWARD);
delay(1000);
} 
  

}
