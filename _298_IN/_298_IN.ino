 #include <Servo.h>

Servo LexaServo;
int servoPin = 9;
int IN1 = 8; // Input3 подключен к выводу 5 
int IN2 = 7;
int ENA = 3;

int IN3 = 13; // Input3 подключен к выводу 5 
int IN4 = 5;
int ENB = 11;
const int Trig = 2;
const int Echo = 12;
void setup()
 
{
 pinMode (ENA, OUTPUT); 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 
 pinMode (ENB, OUTPUT); 
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
  
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  LexaServo.attach(servoPin);
  Serial.begin(12000);
 
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
 
    if (distance_sm<35)
 
    {
  analogWrite  (ENA, 150);
  analogWrite  (ENB, 150);
  
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 


  
  delay(1000);
  
    }
 
    else
 
    {
  analogWrite (ENA, 170);
  analogWrite (ENB, 150); // Скорость оставляем постоянную-АРТЕМ
  
   digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  
  
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 

  
  delay(500);
 
    }
 
}
