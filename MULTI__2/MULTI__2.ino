 #include <Wire.h>
#include <Multiservo.h>

Multiservo Lbedro; // Создаем объект для сервопривода,даем имя
Multiservo Lkoleno;
Multiservo Lstupnya;
Multiservo Rbedro; // Создаем объект для сервопривода,даем имя
Multiservo Rkoleno;
Multiservo Rstupnya;

int del_Lbedro = 200;
int del_Lstupnya = 300;   // DELAY

int X  ;               // Создаем переменную для сохранения режима работы 
int Y = 80;           // УГОЛ ПЕРВЫЙ
int Z = 60; // УГОЛ ВТОРОЙ
int S; int T = 160; int M = 10;

void motion (int X  ,int Y,int Z);  //САМОДЕЛЬНАЯ ФУНКЦИЯ,МОЖНО НАЗВАТЬ "int motion"
                                  //МОЖЕТ ОДНОВРЕМЕННО УПРАВЛЯТЬ ВРАЩЕНИЯМИ СЕРВОВ
void setup (void) {
  Wire.begin();
  Lbedro.attach(10);
  Lkoleno.attach(8);
  Lstupnya.attach(6);
  Rbedro.attach(5);
  Rkoleno.attach(3);
  Rstupnya.attach(1);// ПОДКЛЮЧЕН К 12-му ПИНУ
  
}
                                                    // void motion (X,Y,Z);
void loop (void){
delay(2000  );

for (X = Y ; X >Z  ; X = X - 1)
    { 
      Lbedro.write(X);  //Lbedro.write(Lbedro_array[X]);
      delay(del_Lbedro); 
     } 
  for (X = Z ; X < Y ; X = X + 1)
    { 
      Lbedro.write(X);
      delay(del_Lbedro);
     } 
   
}
