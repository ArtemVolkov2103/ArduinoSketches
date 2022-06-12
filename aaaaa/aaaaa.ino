#include <AFMotor.h>
//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый
const int Trig = 40;
const int Echo = 41;

const int analogPin = 8;
const int analogPin2 = 9;
const int analogPin3 = 10;

int del=1000;


void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);   // Скорость работы порта
  Serial.println("Z-Line Sensor Test"); // Выводим текст
  Serial.println();
  // Пустая строка 
    motor1.setSpeed(250); 
  motor2.setSpeed(250); 
   /* motor1.run(RELEASE);
      motor2.run(RELEASE);
 */
}

unsigned int time_us=0;
unsigned int distance_sm=0;


void loop() {
  motor1.run(FORWARD); 

  digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
delayMicroseconds(10); // Удерживаем 10 микросекунд 
digitalWrite(Trig, LOW); // Затем убираем 
time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
distance_sm=time_us/58; // Пересчитываем в сантиметры 
Serial.println(distance_sm); // Выводим на порт

  
  int analogValue = analogRead(analogPin);
  int analogValue2 = analogRead(analogPin2);
  int analogValue3 = analogRead(analogPin3);
 
     /* Serial.print(analogValue);Serial.print(" "); 
      Serial.print(analogValue2);Serial.print(" "); 
      Serial.println(analogValue3); Serial.print(" ");  
      Serial.println(); */ 
   if (analogValue < 100 && analogValue2 > 200 && analogValue3 < 100){ 
     //БЕЛЫЙ--ЧЕРНЫЙ--БЕЛЫЙ
 motor1.run(FORWARD); 
      motor2.run(FORWARD);
        motor1.setSpeed(250); 
  motor2.setSpeed(250);  
   /* Serial.print("LINE");  
      Serial.println();  
 //delay(del);   */
       }
    
   else if(analogValue > 200 && analogValue2 < 100 && analogValue3 < 100){
     //ЧЕРНЫЙ--БЕЛЫЙ--БЕЛЫЙ
  motor1.run(FORWARD); 

      // delay(del);   
       }         
   
   else {

      motor2.run(FORWARD); 
      // delay(del);   
       }
   
   
}
