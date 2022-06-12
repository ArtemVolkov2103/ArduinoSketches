#include <SoftwareSerial.h>

//МОТОР 1
int ENA = 2;// ENA подключен к выводу 2скорость
int IN1 = 3;// Input1 подключен к выводу 3 
int IN2 = 4;// Input2 подключен к выводу 4
//МОТОР 2
int ENB = 5;// ENA подключен к выводу 5скорость
int IN3 = 6;// Input3 подключен к выводу 6 
int IN4 = 7;// Input4 подключен к выводу 7

int NAPRAVLENIE_1;                  //0-назад,1-вперед
int NAPRAVLENIE_2;                  
volatile unsigned int encoder1 = 10;//начальное значение шагов энкодера
volatile unsigned int encoder2 = 10;

 int del=1000;
  long previousMillis = 0; // нулевая отметка
  long interval = 1000;    // интервал для сравнения
  int i;
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void setup  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void setup

void setup() {

 pinMode (ENA, OUTPUT);  pinMode (IN1, OUTPUT); pinMode (IN2, OUTPUT);
 pinMode (ENB, OUTPUT);  pinMode (IN3, OUTPUT); pinMode (IN4, OUTPUT);

 Serial.begin(9600); 
 attachInterrupt(2,Probeg1,RISING);// на 21
 attachInterrupt(3,Probeg2,RISING);// на 20

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void loop  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void loop

void loop() {
   
   MOTOR1( 100);
   MOTOR1( 1000);
    MOTOR1( 5000);
    
  //Serial.print("MOTOR1 ");Serial.println(encoder1);
   //Serial.print("                MOTOR2 ");Serial.println(encoder2);
  }

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void Probeg  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void Probeg

void Probeg1() //поворот колеса робота(подразумевается,что этим смогу определить положение)
{
  if( NAPRAVLENIE_1 == 1 ){//если крутит вперед
   encoder1 = encoder1+1;
  }
  
  else{
    encoder1 = encoder1-1;
  }
}

void Probeg2() //поворот колеса робота(подразумевается,что этим смогу определить положение)
{
  if( NAPRAVLENIE_2 == 1 ){//если крутит вперед
   encoder2 = encoder2+1;
  }
  
  else{
    encoder2 = encoder2 - 1;
  }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void MOTOR  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void MOTOR

void MOTOR1(int a)// значение,на которое выставится колесо
{  
  if(encoder1 < a ) {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
        analogWrite(ENA,150);
  NAPRAVLENIE_1=1;
  }
  
  else
  if(encoder1 > a) {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH); 
         analogWrite(ENA,150);
  NAPRAVLENIE_1=0;  
  }
  
  else {                      
                           // if(encoder1 == a)
   digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  }
  
}

void MOTOR2(int d)// значение,на которое выставится колесо
{  
  if(encoder2 < d) {
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); 
  analogWrite(ENB,130);
  NAPRAVLENIE_2=1;

  
   /* if(encoder2 < d -100) {
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW); 
    analogWrite(ENB,100);
    NAPRAVLENIE_2=1;
  }*/
  }
  
  else if(encoder2 > d) {
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH); 
  analogWrite(ENB,130);
  NAPRAVLENIE_2=0;


  
     /*if(encoder2 > d + 100) {
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH); 
    analogWrite(ENB,100);
    NAPRAVLENIE_2=0;
  }*/
  }
  
  else {           //if(encoder2 == d)
   digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW); 
  }
  
}
