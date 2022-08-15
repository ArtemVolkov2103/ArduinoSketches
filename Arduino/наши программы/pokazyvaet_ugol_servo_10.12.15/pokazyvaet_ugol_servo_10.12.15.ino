#include <SoftwareSerial.h>
#include <Wire.h>
#include <Multiservo.h>

Multiservo Lbedro; // Создаем объект для сервопривода,даем имя

// Массив для хранения углов поворота сервопривода (шаг 1 градус) 
const int  Lbedro_array[41]={ 
  60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60};  
    
int Lbedro_int;// Создаем переменную для сохранения режима работы 

int val = 0;

int my_del = 500;

void setup (void) {
  Wire.begin();
  Lbedro.attach(12);
  Serial.begin(9600);              //  установка связи по serial
}

void loop (void){
for (Lbedro_int = 20 ; Lbedro_int > 1 ; Lbedro_int = Lbedro_int - 1)
    { 
      Lbedro.write(Lbedro_array[Lbedro_int]);
      val = Lbedro.read();
      Serial.print(val);
      delay(my_del);
         } 
    }
