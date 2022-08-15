 #include <Wire.h>
#include <Multiservo.h>

Multiservo Lbedro; // Создаем объект для сервопривода,даем имя
Multiservo Lkoleno;
Multiservo Lstupnya;
Multiservo Rbedro; // Создаем объект для сервопривода,даем имя
Multiservo Rkoleno;
Multiservo Rstupnya;

// Массив для хранения углов поворота сервопривода (шаг 1 градус) 
const int  Lbedro_array[41]={ 
  60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60};  
  const int  Lkoleno_array[41]={ 
  80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80};  
  const int  Lstupnya_array[50]={
  100,102,105,107,110,112,115,117,120,122,125,127,130,132,135,137,140,142,145,147,150,152,155,157,160,157,155,152,150,147,145,142,140,137,135,132,130,127,125,122,120,117,115,112,110,107,105,102,100};
  const int  Rstupnya_array[50]={
  160,157,155,152,150,147,145,142,140,137,135,132,130,127,125,122,120,117,115,112,110,107,105,102,100,102,105,107,110,112,115,117,120,122,125,127,130,132,135,137,140,142,145,147,150,152,155,157,160};
    
int Lbedro_int;// Создаем переменную для сохранения режима работы 
int Lkoleno_int;
int Lstupnya_int;
int Rbedro_int;// Создаем переменную для сохранения режима работы 
int Rkoleno_int;
int Rstupnya_int;
int del_Lbedro = 100;
int del_Lstupnya = 150;

void setup (void) {
  Wire.begin();
  Lbedro.attach(10);
  Lkoleno.attach(8);
  Lstupnya.attach(6);
  Rbedro.attach(5);
  Rkoleno.attach(3);
  Rstupnya.attach(0);
}

void loop (void){
for (Lbedro_int = 20 ; Lbedro_int > 1 ; Lbedro_int = Lbedro_int - 1)
    { 
      Lbedro.write(Lbedro_array[Lbedro_int]);
      Lkoleno.write(Lkoleno_array[Lbedro_int]);//потому что номера позиции углов уже поменял ввеху программы
      Rbedro.write(Lkoleno_array[Lbedro_int]);
      Rkoleno.write(Lbedro_array[Lbedro_int]);
      delay(del_Lbedro); 
     } 
{
  for (Lstupnya_int = 1 ; Lstupnya_int < 25 ; Lstupnya_int = Lstupnya_int + 1)
  {
  Lstupnya.write(Lstupnya_array[Lstupnya_int]); 
  Rstupnya.write(Rstupnya_array[Lstupnya_int]); 
    delay(del_Lstupnya);
    }
  for (Lbedro_int = 1 ; Lbedro_int < 20 ; Lbedro_int = Lbedro_int + 1)
    { 
      Lbedro.write(Lbedro_array[Lbedro_int]);
      Lkoleno.write(Lkoleno_array[Lbedro_int]);//потому что номера позиции углов уже поменял ввеху программы
      Rbedro.write(Lkoleno_array[Lbedro_int]);
      Rkoleno.write(Lbedro_array[Lbedro_int]);
      delay(del_Lbedro);
     } 
     for (Lstupnya_int = 25 ; Lstupnya_int > 1 ; Lstupnya_int = Lstupnya_int - 1)
  {
  Lstupnya.write(Lstupnya_array[Lstupnya_int]); 
  Rstupnya.write(Rstupnya_array[Lstupnya_int]); 
    delay(del_Lstupnya);
       
    }}}
