#include <Multiservo.h>
#include <Wire.h>

Multiservo levPerPle;
Multiservo levPerLok;

Multiservo praPerPle;
Multiservo praPerLok;

Multiservo levZadPle;
Multiservo levZadLok;

Multiservo praZadPle;
Multiservo praZadlok;


int nahPle = 73;//начальное положение для плеч
int nahLok = 135;// начальное положение для локтей

int a=135;
int b=73;
int c=73;
int d=135;
int e=135;
int f=73;
int g=73;
int h=135;
int del=100;



void setup() {
    Wire.begin();
levPerPle.attach(10);
levPerLok.attach(3);

praPerPle.attach(6);
praPerLok.attach(5);


levZadPle.attach(1);
levZadLok.attach(8);

praZadPle.attach(12);
praZadlok.attach(14);

Serial.begin(9600);

shaganie(nahLok,nahPle,nahPle,nahLok,nahLok,nahPle,nahPle,nahLok);

}


void shaganie(byte a,byte b,byte c,byte d,byte e,byte f,byte g,byte h){

levPerLok.write(a);
levPerPle.write(b);

praPerPle.write(c);
praPerLok.write(d);

levZadLok.write(f);
levZadPle.write(e);

praZadPle.write(g);
praZadlok.write(h);

//Serial.println(a,b,c,d,e,f,g,h);
}



void loop() {

   a-20;
  shaganie(a,b,c,d,e,f,g,h); 
for(int i=0; i<20; i+1)  
{
  c--;
  f--;
  g--;
  b++;
  
  if (i=20)
  a+20;
shaganie(a,b,c,d,e,f,g,h);
//delay(del);
}
delay(1000);

h=h-20;
for(int i; i<20; i+2){
  g+2;
  
  if(i=20)
  h=h+20;
  shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

d=d-20;
for(int i; i<20; i++){
  c++;
  
  if(i=20)
  d=d+20;
  shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

e=e-20;
for(int i; i<20; i++){
  f++;
  b--;
  c--;
  g--;
  
  if(i=20)
  e=e+20;
  shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

h=h-20;
for(int i; i<20; i++){
  g++;
  
  if(i=20)
  h=h+20;
  shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

}
