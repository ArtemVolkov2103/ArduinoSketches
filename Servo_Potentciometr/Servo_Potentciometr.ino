#include <Servo.h> // подключение библиотеки Servo
#include <SoftwareSerial.h>
Servo servo1;
const int pinServo=8; // Пин для подключения сервопривода
const int POT=0; // Аналоговый вход A0 для подключения потенциометра
int valpot = 0; // переменная для хранения значения потенциометра
int angleServo = 0; // переменная для хранения угла поворота сервы
void setup()
{
// подключить переменную servo к выводу pinServo
servo1.attach(pinServo);
 Serial.begin(9600);
}
void loop()
{
valpot = analogRead(POT); // чтение данных потенциометра
// масштабируем значение к интервалу 0-180
angleServo=map(valpot,0,1023,0,110);
// поворот сервопривода на полученный угол
servo1.write(angleServo);
Serial.println(angleServo);
delay(15); // пауза для ожидания поворота сервопривода
}
