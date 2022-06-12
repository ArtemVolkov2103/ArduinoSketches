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
volatile unsigned int encoder1 = 1;//начальное значение шагов энкодера
volatile unsigned int encoder2 = 1;

volatile unsigned int previousEncoder1;
volatile unsigned int previousEncoder2;


const int Trig1 = 46; 
const int Echo1= 48;
unsigned int time_us1=0;
unsigned int distance1=0;
int d1;
const int Trig2 = 50; 
const int Echo2= 52;
unsigned int time_us2=0;
unsigned int distance2=0;
int d2;

long previousMillis = 0; // нулевая отметка
long interval = 100;    // интервал для сравнения

  
void setup() {
 pinMode (ENA, OUTPUT);  pinMode (IN1, OUTPUT); pinMode (IN2, OUTPUT); 
 pinMode (ENB, OUTPUT);  pinMode (IN3, OUTPUT); pinMode (IN4, OUTPUT);

 Serial.begin(9600); 

 attachInterrupt(2,Probeg1,RISING);// на 21
 attachInterrupt(3,Probeg2,RISING);// на 20

  pinMode(Trig1, OUTPUT);
  pinMode(Echo1, INPUT);
   pinMode(Trig2, OUTPUT);
  pinMode(Echo2, INPUT);
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void loop  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>void loop

void loop() {
     ultrasonik1(d1);
     ultrasonik2(d2);
    
   if (distance1>40)
   {
    MOTOR2('F');
   } 
   if (distance2>40)
   {
    MOTOR1('F');
   } 
   
   if (distance1<40)
   {
    MOTOR2('B');
   } 
   if (distance2<40)
   {
    MOTOR1('B'); 
   } 

  Serial.print(distance1);  Serial.print("      "); Serial.println(distance2); 
// Serial.print("                  "); Serial.print(encoder1); Serial.print("      "); Serial.println(encoder2);
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

void MOTOR1(char a)// значение,на которое выставится колесо
{ 
  if(a == 'F') {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  analogWrite(ENA,190);
  
  
  }
  
  else if(a == 'B') {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH); 
  analogWrite(ENA,210);
    
   }
  
  else {
   digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  
  }
}

void MOTOR2(char d)// значение,на которое выставится колесо
{  
 if( d == 'F') {
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); 
  analogWrite(ENB,160);


  }
  
  else if( d == 'B') {
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH); 
  analogWrite(ENB,170);
  
  }
  
  else {  
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW); 
  
  }
  
}

  int ultrasonik1 ( int d1)
  {
   digitalWrite(Trig1, HIGH);
   delayMicroseconds(15);
   digitalWrite(Trig1, LOW); // Удерживаем 10 микросекунд 
   time_us1=pulseIn(Echo1, HIGH);
   distance1=time_us1/58; // Пересчитываем в сантиметры 
   d1 = distance1;
  }
  
   int ultrasonik2 ( int d2)
  {
   digitalWrite(Trig2, HIGH);
   delayMicroseconds(15);
   digitalWrite(Trig2, LOW); // Удерживаем 10 микросекунд 
   time_us2=pulseIn(Echo2, HIGH);
   distance2=time_us2/58; // Пересчитываем в сантиметры 
   d2 = distance2;
  }  
