#include <Multiservo.h>
#include <Wire.h>

Multiservo PrPerBedro;
Multiservo PrPerKol;
Multiservo PrPerStupnya;

Multiservo PrSredStupnya;
Multiservo PrSredKol;

Multiservo PrZadBegro;
Multiservo PrZadKol;
Multiservo PrZadStupnya;

Multiservo LevZadBedro;
Multiservo LevZadKol;
Multiservo LevZadStupnya;

Multiservo LevSredBedro;
Multiservo LevSredKol;

Multiservo LevPerBedro;
Multiservo LevPerKol;
Multiservo LevPerStupnya;

int nahBedro = 1250;
int nahKol = 2000;
int nahStupSred = 1000;
int del=50;

void setup() {
  Wire.begin();
  PrPerStupnya.attach(6);
  PrPerKol.attach(7);
  PrPerBedro.attach(8);
  
  
  PrSredStupnya.attach(5);
  PrSredBedro.attach(4);
  
  
  PrZadBegro.attach(2);
  PrZadKol.attach(1);
  PrZadStupnya.attach(0);
  
  
  LevZadBedro.attach(15);
  LevZadKol.attach(16);
  LevZadStupnya.attach(17);
  
  
  LevSredBedro.attach(12);
  LevSredKol.attach(13);
  
  LevPerBedro.attach(11);
  LevPerKol.attach(10);
  LevPerStupnya.attach(9);
}
void shaganie(int a,int b,int c,int d,int e,int f,int g,int h,int u,int j,int k,int m,int n,int o,int p,int r){  // процедура
 PrPerBedro.writeMicroseconds(a);
 PrPerKol.writeMicroseconds(b);
 PrPerStupnya.writeMicroseconds(c);

 PrSredStupnya.writeMicroseconds(d);
 PrSredBedro.writeMicroseconds(e);

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
       shaganie(nahBedro,nahKol,nahKol,nahStupSred,nahBedro,nahBedro,nahKol,nahKol,nahBedro,nahKol,nahKol,nahBedro,nahStupSred,nahBedro,nahKol,nahKol);

 
void loop() {

}
