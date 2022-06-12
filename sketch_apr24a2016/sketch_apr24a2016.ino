#include <Multiservo.h>
#include <Wire.h>

Multiservo levPerLok_a;
Multiservo levPerPle_b;
Multiservo praPerPle_c;
Multiservo praPerLok_d;

Multiservo levZadLok_e;
Multiservo levZadPle_f;
Multiservo praZadPle_g;
Multiservo praZadLok_h;

int a=1250;
int b=1250;
int c=1250;
int d=1250;

int e=1250;
int f=1250;
int g=1250;
int h=1250;

int del=100;

int nahPle = 1250;//начальное положение для плеч
int nahLok = 1250;// начальное положение для локтей

void setup(void) {   //добавил void
  Wire.begin();
    Serial.begin(9600);
      levPerLok_a.attach(3);
      levPerPle_b.attach(10);
      praPerPle_c.attach(6);
      praPerLok_d.attach(5);

      levZadLok_e.attach(1);
      levZadPle_f.attach(8);

      praZadPle_g.attach(12);
      praZadLok_h.attach(14);
      
      shaganie(nahLok,nahPle,nahPle,nahLok,nahLok,nahPle,nahPle,nahLok);

}
void shaganie(int a,int b,int c,int d,int e,int f,int g,int h){  // процедура
  levPerLok_a.writeMicroseconds(a);//            
  levPerPle_b.writeMicroseconds(b);//           
  praPerPle_c.writeMicroseconds(c);// 
  praPerLok_d.writeMicroseconds(d);//
  
  levZadLok_e.writeMicroseconds(e);//            
  levZadPle_f.writeMicroseconds(f);//           
  praZadPle_g.writeMicroseconds(g);// 
  praZadLok_h.writeMicroseconds(h);//  
}

void loop() {
                                                                      a=a-500;
                                                         Serial.println(a,'\n');
                                                      shaganie(a,b,c,d,e,f,g,h);
                                                                 //delay(1000);
  
   for (int i=0; i <= 500; i++){ //ЦИКЛ №1
     
      b=b+1;
      c=c-1;
      f=f-1;
      g=g-1;
      shaganie(a,b,c,d,e,f,g,h);
        
   delay(del);
      

 


                                                          
 
}}
