#include <SoftwareSerial.h>

int pin = 3;                                                
unsigned int encoder = 0;//начальное значение шагов энкодера
int X;


void setup()
{
  pinMode(pin, INPUT);
  attachInterrupt(1,Probeg,CHANGE    );
  Serial.begin(9600);
}
 
void loop()
{
}
 
void Probeg1() //пробег
{
  X=digitalRead(pin);

  if (X == LOW){
    encoder = encoder+1;
    Serial.println(encoder);
    Serial.println("LOW");



}
   else if (X == HIGH)
   {
    encoder = encoder+1;
    Serial.println(encoder);
    Serial.println("HIGH");
    

   }
   
 else 
   {

    Serial.println("ERROR");
   }}
