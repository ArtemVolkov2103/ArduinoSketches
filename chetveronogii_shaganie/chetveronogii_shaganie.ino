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
int del=500;



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


void shaganie(int a,int b,int c,int d,int e,int f,int g,int h){

levPerLok.write(a);
levPerPle.write(b);

praPerPle.write(c);
praPerLok.write(d);

levZadLok.write(f);
levZadPle.write(e);

praZadPle.write(g);
praZadlok.write(h);


}



void loop() {

  a=a-20;
  //shaganie(a,b,c,d,e,f,g,h);
  
for(int i=0; i<=20; i++)//  надо i++)
                       //   i+1 не будет правильно работать   
{
  c=c-1;
  f=f-1;
  g=g-1;
  b=b+1;
  
  if (i=20){
   a=a+20;}
   //shaganie(a,b,c,d,e,f,g,h);
   delay(del);
 Serial.println(a);
           //Serial.println(с);

}

  h=h-20;
   Serial.println(h);

for(int i=0; i<=20; i++){
  g=g+1;
  
  if(i=20){
   h=h+20;}
  // shaganie(a,b,c,d,e,f,g,h);
   delay(del);
    

}

d=d-20;
 Serial.println(d); 
 
for(int i=0; i<=20; i++){
  c=c+1;
  
  if(i=20){
   d=d+20;}
   //shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

e=e-20;
//shaganie(a,b,c,d,e,f,g,h);

for(int i; i<=20; i++){
  f=f+1;
  b=b-1;
  c=c-1;
  g=g-1;
  
  if(i=20){
  e=e+20;}
  //shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

h=h-20;
for(int i; i<=20; i++){
  g++;
  
  if(i=20){
  h=h+20;}
  //shaganie(a,b,c,d,e,f,g,h);
delay(del);
}

}
