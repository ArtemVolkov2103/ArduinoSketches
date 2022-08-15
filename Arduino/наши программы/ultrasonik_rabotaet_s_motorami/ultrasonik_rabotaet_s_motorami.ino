#include <AFMotor.h>
 
AF_DCMotor motor1(1); //правый
AF_DCMotor motor2(2); //Левый
const int Trig = 50;
const int Echo = 52;

int skorost1=100;
int skorost2=100;
void setup()
 
{
 
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
  motor1.run(RELEASE); 
   motor2.run(RELEASE); 
 
 
}
 
 
 
unsigned int time_us=0;
unsigned int distance_sm=0;
 
   
 void loop()
 
{    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW); 
    time_us=pulseIn(Echo, HIGH); 
    distance_sm=time_us/58; 
    Serial.println(distance_sm); 
 
   
 
    if (distance_sm>10)
 
    {
   motor1.setSpeed(skorost1);
   motor2.setSpeed(skorost2);
   motor1.run(RELEASE); 
   motor2.run(RELEASE); 
   motor1.run(FORWARD);
   motor2.run(FORWARD);
  
  //                        motor1.run(RELEASE); 
  //                        motor2.run(RELEASE); 
 
    }
 
 
    else
 
    { motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD);
   
    }
  /*   if (distance_sm=0)
 
    {
   motor1.setSpeed(255);
   motor2.setSpeed(255); 
   motor1.run(BACKWARD); 
   motor2.run(BACKWARD); 
  delay(500);
 
    }*/
} 
