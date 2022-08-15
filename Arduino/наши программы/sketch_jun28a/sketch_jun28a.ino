#include <SoftwareSerial.h>
int pin2 = 2; 
int pin3 = 3; 

 unsigned int encoder = 0;//начальное значение шагов энкодера
unsigned int encoder2 = 0;//начальное значение шагов энкодера

int X;
int Y;
int del=5;

void setup() {
     pinMode(pin2, INPUT);
     pinMode(pin3, INPUT);
  attachInterrupt(0,ENC1,RISING   );
  attachInterrupt(1,ENC2,RISING   );
  Serial.begin(57600);

}

void loop() 
{
}

void ENC1() //пробег
{
  X=digitalRead(pin2);  
    encoder++;
    Serial.println(encoder);
//    Serial.println(X == HIGH ? "High" : "Low");    
}

void ENC2() 
{ 
  Y=digitalRead(pin3);
  encoder2++;
  Serial.print("    ");     
  Serial.println(encoder2);
 // Serial.println(Y == HIGH ? "    H" : "   L");
}
