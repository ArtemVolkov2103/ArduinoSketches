#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo yourservo;                // twelve servo objects can be created on most boards
 
int pos = 100;    // variable to store the servo position 
int a=0;
int b=0;

void setup() 
{ 
  myservo.attach(9);
  yourservo.attach(10);
  
  posis(pos,pos);
} 

void posis(int levo, int Pravo){
  myservo.write(Levo);
  yourservo.write(Pravo);
}

void loop() {


  for(int i=0;i<=20;i++) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    b=b+1;
    a=a+1;
    posis(a,b);
    delay(15);
  if (i=120){
  i=i-20;
  } 
  for(int i=20;i>=0;i--)
  {                                   
    b=b-1;
    a=a-1;
    posis(a,b);
    delay(15);
  if (i=1){
  i=i+20;
  }
delay(2000); 
  } }}

 

