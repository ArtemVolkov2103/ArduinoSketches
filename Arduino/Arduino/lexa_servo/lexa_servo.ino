 #include <Servo.h>
#include <AFMotor.h>

Servo LexaServo;
int servoPin = 9;
AF_DCMotor motor1(1); //правый
AF_DCMotor motor2(3); //Левый

const int Trig = 2;
const int Echo = 12;
void setup()
 
{

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  LexaServo.attach(servoPin);
  Serial.begin(9600);
 
}
 
 
 
unsigned int time_us=0;
unsigned int distance_sm=0;
 
 
 
 void loop()
 
{
 
  {
 
  for (int i=40; i<=120; i=i+10) 
 
   {                         
 
    LexaServo.write(i);     
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
  
   motor1.run(FORWARD);
   motor2.run(BACKWARD);
   motor1.setSpeed(240);
   motor2.setSpeed(240);
  
   
    }
 
    else
 
    {
 
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor1.setSpeed(160);
      motor2.setSpeed(160);
 
    }
 
}
