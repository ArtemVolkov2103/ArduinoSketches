#include <SoftwareSerial.h>

#include <Multiservo.h>
#include <Wire.h>


Multiservo StupnyaPRAV;
Multiservo StupnyaLEV;

Multiservo KolenoPRAV;
Multiservo KolenoLEV;

Multiservo BedroPRAV;
Multiservo BegroLEV;

Multiservo TazPRAV;
Multiservo TazLEV;

Multiservo KistPRAV; 
Multiservo KistLEV;
  
Multiservo LocotPRAV;  
Multiservo LocotLEV;
  
Multiservo PlechoPRAV;
Multiservo PlechoLEV;


int x=1250;
int y=1800;
 int a=x;
 int b=x;
 int c=x;
 int d=x;
  int e=y;
  int f=y;
 int g=x;
 int h=x;
            // руки
 int k=x;
 int l=x;
 int m=y;
 int n=x;
 int o=x;
 int p=y;

int del=1000;
void setup(void) {
                            
                              
  Serial.begin(9600);// Устанавливаем скорость передачи данных по кабелю 
  Wire.begin();
  
 StupnyaPRAV.attach(1); // Выбираем пин к которому подключен сервопривод
 StupnyaLEV.attach(6);
  
 KolenoPRAV.attach(2);  
 KolenoLEV.attach(7);
  
 BedroPRAV.attach(4);
 BegroLEV.attach(9);
 
  TazPRAV.attach(5);
  TazLEV.attach(10);
   
     
       
 KistPRAV.attach(14); // Выбираем пин к которому подключен сервопривод
 KistLEV.attach(17);
  
 LocotPRAV.attach(13);  
 LocotLEV.attach(16);
  
 PlechoPRAV.attach(12);
 PlechoLEV.attach(15);
 RUKY(x,x,y,x,x,y);
  NOGY(x,x,x,x,y,y,x,x);
}

void NOGY(int a,int b,int c,int d,int e,int f,int g,int h){  // процедура нога
 
 StupnyaPRAV.writeMicroseconds(a);
 StupnyaLEV.writeMicroseconds(b);
 
 KolenoPRAV.writeMicroseconds(c);
 KolenoLEV.writeMicroseconds(d);
 
 BedroPRAV.writeMicroseconds(e);
 BegroLEV.writeMicroseconds(f);
 
 TazPRAV.writeMicroseconds(g);
 TazLEV.writeMicroseconds(h);
}
 
 
void RUKY(int k,int l,int m,int n,int o,int p){
 
 KistPRAV.writeMicroseconds(k);
 KistLEV.writeMicroseconds(l);
 
 LocotPRAV.writeMicroseconds(m);
 LocotLEV.writeMicroseconds(n);
 
 PlechoPRAV.writeMicroseconds(o);
 PlechoLEV.writeMicroseconds(p);
 

}
  // 
void loop() {
if (Serial.available() > 0){
 int STUPNI = Serial.parseInt();
  int KOLENI = Serial.parseInt();
  int BEDRA  = Serial.parseInt();
  int TAZ    = Serial.parseInt();
 
 
StupnyaPRAV.writeMicroseconds(STUPNI);
StupnyaLEV.writeMicroseconds(STUPNI); 
 
KolenoPRAV.writeMicroseconds(KOLENI);
 KolenoLEV.writeMicroseconds(KOLENI);
 
 BedroPRAV.writeMicroseconds(BEDRA); 
 BegroLEV.writeMicroseconds(BEDRA);

 TazPRAV.writeMicroseconds(TAZ);
 TazLEV.writeMicroseconds(TAZ);
delay(1000);

 }
 for(int i=0; i <= 100; i=i+1)  
{
  a=a+1;
 // ++b;
 // ++c;
 // ++d;
  //++e;
  //--f;
  //g;
  //h;
  //m=m+1;
  //n=n+1;
 
 NOGY(a,b,c,d,e,f,g,h);
//RUKY(k,l,m,n,o,p);

delay(30);Serial.println(i);
}
 for(int i=100; i >=0; i=i-1)  
{
a=a-1;
 // --b;
 // --c;
 // --d;
  //e;
  //f;
  //g;
  //h;
 // m=m-1;
 // n=n-1;
 
 NOGY(a,b,c,d,e,f,g,h);
//RUKY(k,l,m,n,o,p);
 
delay(30);Serial.println(i);
}
}
