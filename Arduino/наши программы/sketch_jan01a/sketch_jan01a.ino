 #include <Wire.h>
#include <Multiservo.h>

Multiservo Lbedro; // Создаем объект для сервопривода,даем имя
Multiservo Lkoleno;
Multiservo Lstupnya;
Multiservo Rbedro; // Создаем объект для сервопривода,даем имя
Multiservo Rkoleno;
Multiservo Rstupnya;

int del_Lbedro = 100;
int del_Lstupnya = 150;   // DELAY

int X;            
int Y;            
int Z=80; int H=60;//УГЛЫ БЕДЕР                
int S;
int L;
int M=156; int N=104;//УГЛЫ СТУПНИ

//void motion (int X  ,int Y,int Z);  //САМОДЕЛЬНАЯ ФУНКЦИЯ,МОЖНО НАЗВАТЬ "int motion"
                                  //МОЖЕТ ОДНОВРЕМЕННО УПРАВЛЯТЬ ВРАЩЕНИЯМИ СЕРВОВ
void setup (void) {
  Wire.begin();
  Lbedro.attach(10);
  Lkoleno.attach(8);
  Lstupnya.attach(6);
  Rbedro.attach(5);
  Rkoleno.attach(3);
  Rstupnya.attach(1);//
  
  Lbedro.write(70);
  Lkoleno.write(70);
  Rbedro.write(70);
  Rkoleno.write(70);
  Lstupnya.write(130); 
  Rstupnya.write(130);
 delay(2000);  }
 
//void motion (X,Y,Z);
void loop (void){

for (X=Z,Y=H ; X>H,Y<Z ; X = X - 1,Y = Y + 1)
    { 
      Lbedro.write(Y);
      Lkoleno.write(X);
      Rbedro.write(X);
      Rkoleno.write(Y);  
      delay(del_Lbedro); 
     } 
{
  for (S=M, L=N; S > N,L<M ; S = S - 1, L = L + 1)
  {
  Lstupnya.write(S); 
  Rstupnya.write(L); 
    delay(del_Lstupnya);
    }
for (X=Z,Y=H ; X>H,Y<Z; X = X - 1,Y = Y + 1)
    { 
      Lbedro.write(X);
      Lkoleno.write(Y);
      Rbedro.write(Y);
      Rkoleno.write(X);
      delay(del_Lbedro);
     } 
     for (S=M,L=N ; S > N, L < M ; S = S - 1, L = L + 1)
  {
  Lstupnya.write(L); 
  Rstupnya.write(S); 
    delay(del_Lstupnya);
       
    }}}
