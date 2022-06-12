#include <Multiservo.h>
#include <Wire.h>

Multiservo PrPerBedro;
Multiservo PrPerKol;
Multiservo PrPerStupnya;

Multiservo PrSredStupnya;
Multiservo PrSredBedro;

Multiservo PrZadBegro;
Multiservo PrZadKol;
Multiservo PrZadStupnya;

Multiservo LevZadBedro;
Multiservo LevZadKol;
Multiservo LevZadStupnya;

Multiservo LevSredBedro;
Multiservo LevSredStupnya;

Multiservo LevPerBedro;
Multiservo LevPerKol;
Multiservo LevPerStupnya;

int nahBedro = 1250;// 90 градусов
int nahKol = 750;//  градусов
int nahStupSred = 850;
int del=5;

int x=750;
int y=1250;

int a=y;
int b=x;
int c=x;
int d=y;
int e=800;
int f=y;
int g=x;
int h=x;
int u=y;
int j=x;
int k=x;
int m=y;
int n=950;
int o=y;
int p=x;
int r=x;

void setup(void) {//
  Wire.begin();
  PrPerStupnya.attach(6); // Выбираем пин к которому подключен сервопривод
  PrPerKol.attach(7);
  PrPerBedro.attach(8);
  
  
  PrSredStupnya.attach(4);
  PrSredBedro.attach(5);
  
  
  PrZadBegro.attach(2);
  PrZadKol.attach(1);
  PrZadStupnya.attach(0);
  
  
  LevZadBedro.attach(15);
  LevZadKol.attach(16);
  LevZadStupnya.attach(17);
  
  
  LevSredBedro.attach(12);
  LevSredStupnya.attach(13);
  
  LevPerBedro.attach(11);
  LevPerKol.attach(10);
  LevPerStupnya.attach(9);
  
shaganie(nahBedro,nahKol,nahKol,nahStupSred,nahBedro,nahKol,nahKol,nahKol,nahBedro,nahKol,nahKol,nahBedro,nahStupSred,nahBedro,nahKol,nahKol);
}

void shaganie(int a,int b,int c,int d,int e,int f,int g,int h,int u,int j,int k,int m,int n,int o,int p,int r){  // процедура
 PrPerBedro.writeMicroseconds(a);
 PrPerKol.writeMicroseconds(b);
 PrPerStupnya.writeMicroseconds(c);

 PrSredBedro.writeMicroseconds(d);
 PrSredStupnya.writeMicroseconds(e);

 PrZadBegro.writeMicroseconds(f);
 PrZadKol.writeMicroseconds(g);
 PrZadStupnya.writeMicroseconds(h);

 LevZadBedro.writeMicroseconds(u);
 LevZadKol.writeMicroseconds(j);
 LevZadStupnya.writeMicroseconds(k);

 LevSredBedro.writeMicroseconds(m);
 LevSredStupnya.writeMicroseconds(n);

 LevPerBedro.writeMicroseconds(o);
 LevPerKol.writeMicroseconds(p);
 LevPerStupnya.writeMicroseconds(r);
       
}
 
void loop() { // void loop(void)  не работает,дергается
/*shaganie(y,x,x,y,x,y,x,x,y,x,x,y,x,y,x,x);

 a=y;
 b=x;
 c=x;
 d=y;
 e=x;
 f=y;
 g=x;
 h=x;
 u=y;
 j=x;
 k=x;
 m=y;
 n=x;
 o=y;
 p=x;
r=x;*/

for (int i=0; i <= 100; i++){ //ЦИКЛ №1
      b=b-2; //подьем ноги
      c=c-1;
      e=e+2;
      g=g-2;
      h=h-1;     

      j=j+2;
      k=k+1;
      n=n-1;
      p=p+2;
      r=r+1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}




for (int i=0; i <= 80; i++){ //ЦИКЛ №2
 a=a+1;
 f=f+1;
 m=m-1;
 
 d=d-1;
 u=u+1;
 o=o+1;
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}
for (int i=0; i <= 100; i++){ //ЦИКЛ №1
      b=b+2; //опускаем ноги ноги
      c=c+1;
      e=e-2;
      g=g+2;
      h=h+1;           
      j=j-2;
      k=k-1;
      n=n+1;
      p=p-2;
      r=r-1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 80; i++){ //ЦИКЛ №2
 a=a-1;
 f=f-1;
 m=m+1;
 
 d=d+1;
 u=u-1;
 o=o-1;
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}

}
