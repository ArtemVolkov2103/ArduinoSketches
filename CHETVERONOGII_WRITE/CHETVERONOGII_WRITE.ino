#include <Multiservo.h>
#include <Wire.h>

Multiservo FR_S;//НАЗЫВАЮ СЕРВЫ 
Multiservo FR_L;// ПЕРЕДНИЕ 
Multiservo FL_S; 
Multiservo FL_L; 

Multiservo BR_S; //ЗАДНИЕ
Multiservo BR_L; 
Multiservo BL_S; 
Multiservo BL_L; 

int del = 20;
int US=135;//УГОЛ ДЛЯ ВСЕХ СТУПНЕЙ
int UL=73;//УГОЛ ДЛЯ ВСЕХ ЛОКТЕЙ
int X;
int Y;
int Z=40;
int H=100;

void setup(void) {
  Wire.begin();
  FR_S.attach(5);//
  FR_L.attach(6);//
  FL_S.attach(3);//
  FL_L.attach(10);//
                //ПОДКЛЮЧАЮ СЕРВЫ К ПИНАМ
  BR_S.attach(14);//
  BR_L.attach(12);//
  BL_S.attach(1);//
  BL_L.attach(8);//

  FR_S.write(US);
  FR_L.write(UL);
  FL_S.write(US);
  FR_L.write(UL);
              //УСТАНАВЛИВАЮ НА ОПР. УГЛЫ
  BR_S.write(US);
  BR_L.write(UL);
  BL_S.write(US);
  BL_L.write(UL);
}
void motoin(X,Y) {
  FR_S.write(Y);
  FR_L.write(X);
  FL_S.write(Y);
  FR_L.write(X);
  BR_S.write(Y);
  BR_L.write(X);
  BL_S.write(Y);
  BL_L.write(X);

}


void loop(void) {
 for (X=H; X>Z; X=X-1){
     FR_S.write(US-20);
 FR_L.write(X);
      delay(del);}
     FR_S.write(US);

  for (X=H; X>Z; X=X-1){
     FL_S.write(US-20);
 FL_L.write(X);
      delay(del);}
    FL_S.write(US);

 for (X=H; X>Z; X=X-1){ 
     BR_S.write(US-20);
 BR_L.write(X);
      delay(del);}
    BR_S.write(US);

  for (X=H; X>Z; X=X-1){
     BL_S.write(US-20);
 BL_L.write(X);
     delay(del);}
    BL_S.write(US);
 
   for (X=Z; X<H; X=X+1){
      FR_S.write(US);
  FR_L.write(X);
      FL_S.write(US);
  FL_L.write(X);
      BR_S.write(US);
  BR_L.write(X);
      BL_S.write(US);
  BL_L.write(X);
     delay(del);
  }

 // FR_S.write(US-50);//ХОДЬБА ПЕРЕДНЕЙ ЛАПОЙ  delay(del);FR_L.write(UL+20);delay(del);FR_S.write(US);delay(del);FR_L.write(UL);delay(2000);
}
