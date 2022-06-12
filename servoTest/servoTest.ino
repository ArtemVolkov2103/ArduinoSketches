#include <Servo.h>   // Подключаем библиотеку для сервоприводом
#include <SoftwareSerial.h>

#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire

// Создаем объект для сервопривода 

Multiservo myservo; 
int mas[] = {0, 90};
 void setup() { 
    Serial.begin(9600);

   // Выбираем пин к которому подключен сервопривод 
   myservo.attach(9, 540, 2400); 
   // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
   //myservo.write(0);  

   int StartPos[] = {2000, 2000, 1122, 1303, 1196, 982, 10000};
  /*
   * 1-1100 - 750  - 1200
   * 2-1100 - 1250 - 800
   * 3-1200 - 1000 - 1400
   * 5-1200 - 1400 - 1000
   * 6-1200 - 1400 - 1000
   * 7-1170 - 1000 - 1400
   * 8-1520
   * 9-1420
   */

   
}

//--------ВВЕСТИ НОМЕР И УГОЛ СЕРВОПРИВОДА в формате 9,2000,

void loop() { 
if (Serial.available() > 0) {
  String servo = Serial.readStringUntil(',');
  if(servo != ""){
            //here you could check the servo number
            int num = servo.toInt();
            myservo.attach(num); 
            String pos = Serial.readStringUntil(',');
            //Serial.println(pos);
            int int_pos=pos.toInt();
            myservo.writeMicroseconds(int_pos); 
        }
}
} 
