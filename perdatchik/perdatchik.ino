#include <RCSwitch.h>

#define axis_Z A3    // Ось Z (кнопка джойстика) подключена к Digital 2
 
int value_Z = 0;    // Переменные для хранения значений осей
 
RCSwitch mySwitch = RCSwitch();

void setup() {
    mySwitch.enableTransmit(2);
    pinMode(axis_Z, INPUT);    // Задаем как вход
    Serial.begin(9600);
}

void loop() {

   value_Z = analogRead(axis_Z);   // Считываем цифровое значение оси Z (кнопка)
  //value_Z = value_Z ^ 1;           // Инвертируем значение  
    mySwitch.send(value_Z, 12);
    Serial.println(value_Z );
   delay(1);
}
