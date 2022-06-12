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
   
       NOGY(x,x,x,x,y,y,x,x);
}

void NOGY(int a,int b,int c,int d,int e,int f,int g,int h){  // процедура
 
 StupnyaPRAV.writeMicroseconds(a);
 StupnyaLEV.writeMicroseconds(b);
 
 KolenoPRAV.writeMicroseconds(c);
 KolenoLEV.writeMicroseconds(d);
 
 BedroPRAV.writeMicroseconds(e);
 BegroLEV.writeMicroseconds(f);
 
 TazPRAV.writeMicroseconds(g);
 TazLEV.writeMicroseconds(h);

 }
 
 


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
 }}
