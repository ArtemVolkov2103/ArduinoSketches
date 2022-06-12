#include <AFMotor.h>

const int analogPin = 10;
const int analogPin2 = 9;
const int analogPin3 = 8;


void setup() {
  Serial.begin(9600);   // Скорость работы порта
  Serial.println("Z-Line Sensor Test"); // Выводим текст
  Serial.println();                             // Пустая строка 
}

void loop() {
  int analogValue = analogRead(analogPin);
  int analogValue2 = analogRead(analogPin2);
  int analogValue3 = analogRead(analogPin3);
 

 
   if (analogValue2>=300){// черный 700-300
                           //белый 299-1
                           
      Serial.println("LINE");
      Serial.println("*****************"); 

    }
   else{
       Serial.print(analogValue);
       Serial.println("Left");   
       Serial.print(analogValue2);
       Serial.println("Centr");     
       Serial.print(analogValue3);
       Serial.println("Right");  
       Serial.println("////////////////////////////////////");       
  // Выводим значения
  delay(3000);
}}
