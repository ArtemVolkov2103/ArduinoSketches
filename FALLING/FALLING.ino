#include <SoftwareSerial.h>

int pin = 3;                                                
unsigned int encoder = 0;//начальное значение шагов энкодера
 
void setup()
{
  pinMode(pin, INPUT);
  attachInterrupt(1,Probeg,FALLING  );
  Serial.begin(9600);
}
 
void loop()
{
  Serial.println(encoder);
 //   Serial.println("klk");
}
 
void Probeg() //пробег
{
  if(digitalRead(pin) == HIGH  ){// digitalRead читает только LOW и HIGH 
  encoder = encoder+1;
  Serial.println(" ");
  delay(5000);
}


 }
