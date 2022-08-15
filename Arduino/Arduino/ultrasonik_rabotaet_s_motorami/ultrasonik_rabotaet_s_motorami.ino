#include <AFMotor.h>
 
AF_DCMotor motor1(1); //правый
AF_DCMotor motor2(2); //Левый
const int Trig = 2;
const int Echo = 12;
void setup()
 
{
 
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
 
}
 
 
 
unsigned int time_us=0;
unsigned int distance_sm=0;
 
 
 
 void loop()
 
{
 
  {
 
  for (int i=90; i<=100; i=i+10) 
 
   {                         
     
    delay(200);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW); 
    time_us=pulseIn(Echo, HIGH); 
    distance_sm=time_us/58; 
    Serial.println(distance_sm); 
 
  }
 
 }  
 
    if (distance_sm<30)
 
    {
   motor1.setSpeed(255);
   motor2.setSpeed(255); 
   motor1.run(FORWARD);
   motor2.run(BACKWARD);
   delay(500);
   motor1.run(RELEASE); 
   motor2.run(RELEASE); 
  delay(500);
 
    }
 
 
    else
 
    {
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
  delay(500);
    }
     if (distance_sm=0)
 
    {
   motor1.setSpeed(255);
   motor2.setSpeed(255); 
   motor1.run(FORWARD); 
   motor2.run(FORWARD); 
  delay(500);
 
    }
}
