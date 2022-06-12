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

 int a=1900;
int b=1250;
int c=1500;
int d=1900;

int e=1900;
int f=1500;
int g=1500;
int h=1900;

int del=5;

int nahPle = 1250;//начальное положение для плеч
int nahLok = 1900;// начальное положение для локтей

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
      

 }
                                                                   a=a+500;
                                                      Serial.println(a,'\n');
                                                    shaganie(a,b,c,d,e,f,g,h);

                                                                   h=h-500;
                                                        
                                                      shaganie(a,b,c,d,e,f,g,h);
  
for (int i=0; i <=100; i++){ // ЦИКЛ №2
     g=g+5; 
      shaganie(a,b,c,d,e,f,g,h);
      delay(del);
 }
                                                       h=h+500;
                                                   
                                                     shaganie(a,b,c,d,e,f,g,h);
 
                                                               d=d-500;
                                                        //Serial.println(d,'\n');
                                                       shaganie(a,b,c,d,e,f,g,h);  
for (int i=0; i <=100; i++){ // ЦИКЛ №3
     c=c+5; 
      shaganie(a,b,c,d,e,f,g,h);
      delay(del);
 }
                                                           d=d+500;
                                                      // Serial.println(d,'\n');
                                                    shaganie(a,b,c,d,e,f,g,h);

                                                           e=e-500;
                                               
                                                  shaganie(a,b,c,d,e,f,g,h);
  
   for (int i=0; i <= 500; i++){ //ЦИКЛ №4
     
      f=f+1;
      c=c-1;
      b=b-1;
      g=g-1;
      shaganie(a,b,c,d,e,f,g,h);       
   delay(del);

 }
                                                       e=e+500;
                                                  shaganie(a,b,c,d,e,f,g,h);

                                                             d=d-500;
                                                    shaganie(a,b,c,d,e,f,g,h);  
for (int i=0; i <=100; i++){ // ЦИКЛ №5
     c=c+5; 
      shaganie(a,b,c,d,e,f,g,h);
      delay(del);
 }
                                                               d=d+500;
                                                          Serial.println(d,'\n');
                                                        shaganie(a,b,c,d,e,f,g,h);

                                                             h=h-500;
                                                        Serial.println(h,'\n');
                                                      shaganie(a,b,c,d,e,f,g,h);
  
for (int i=0; i <=100; i++){ // ЦИКЛ №6
     g=g+5; 
      shaganie(a,b,c,d,e,f,g,h);
      delay(del);
 }
                                                             h=h+500;
                                                      Serial.println(h,'\n');
                                                  shaganie(a,b,c,d,e,f,g,h);
 
}
