#include <SoftwareSerial.h>
#include <Wire.h>
#include <Multiservo.h>

Multiservo servo1;
Multiservo servo2;
Multiservo servo3;

const int Trig1 = 50; //№1
const int Echo1= 52;
unsigned int time_us1=0;
unsigned int distance1=0;


bool statusServo2 = HIGH;// статус автомата

void setup(void)
{
  Wire.begin();
  Serial.begin(9600);
  servo1.attach(1);
  servo2.attach(2);
  servo3.attach(3);
  pinMode(Trig1, OUTPUT);
  pinMode(Echo1, INPUT);
}

void loop(void)
 {
  ultrasonik(distance1);
  if (distance1<30)
   { flag( 90,90,90 );}
  else
   { flag( 20,20,20 );}
   delay(500);
 }

void flag (int a, int b, int c)
  {
    servo1.write(a);
    servo2.write(b);
    servo3.write(c);
  }
int ultrasonik ( int distance1)
  {
   digitalWrite(Trig1, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trig1, LOW); // Удерживаем 10 микросекунд 
   time_us1=pulseIn(Echo1, HIGH);
   distance1=time_us1/58; // Пересчитываем в сантиметры 
   Serial.println(distance1); // Выводим на порт
   //return distance1;
   
  }
