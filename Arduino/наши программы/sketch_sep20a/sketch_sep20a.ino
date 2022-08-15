#include <Servo.h> //используем библиотеку для работы с сервоприводом

Servo Vservo; //объявляем переменную servo типа Servo
Servo servo;
Servo 6servo; 
Servo 7servo;
void setup() //процедура setup

{

2servo.attach(0); //привязываем привод к порту 10
3servo.attach(1);
6servo.attach(4); //привязываем привод к порту 10
7servo.attach(5);
}

void loop() //процедура loop

{

2servo.write(10); //ставим вал под 0
3servo.write(13);
6servo.write(10); //ставим вал под 0
7servo.write(13);
delay(1000); //ждем 2 секунды

2servo.write(13); //ставим вал под 180
3servo.write(10);
6servo.write(13); //ставим вал под 180
7servo.write(10);
delay(1000); //ждем 2 секунды

}
