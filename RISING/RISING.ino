#include <SoftwareSerial.h>

int pin = 3;                                                
unsigned int encoder = 0;//начальное значение шагов энкодера
 
void setup()
{
  pinMode(pin, INPUT);
  attachInterrupt(1,Probeg,RISING );
  Serial.begin(9600);
}
 
void loop()
{
  Serial.println(encoder);
    //Serial.println("klk");
}
 
void Probeg() //пробег
{
  if(digitalRead(pin) == HIGH  ){
  encoder = encoder+1;
}


 }
