#include <VarSpeedServo.h>

#include <Wire.h>
#include <Multiservo.h>
VarSpeedServo PLECHO,LOKOT,ZAHVAT;

//ДАТЧИК ЦВЕТА
int s0 = 8; 
int s1 = 9; 
int s2 = 12; 
int s3 = 11; 
int out = 10;
int red,green,blue=0;
int CVET;//хранилище кода цвета


//МОТОР LEGO
int IN1 = 5;// Input1 подключен к выводу 5 
int IN2 = 6;// Input2 подключен к выводу 6
int ENA = 7;// ENA подключен к выводу 7-скорость

int NAPRAVLENIE;//0-вправо,1-влево
volatile unsigned int encoder = 0;//начальное значение шагов энкодера

int Zahvat=150;//180-сжатие,115-открыть

int del=1000;
  long previousMillisa = 0; // 
  long previousMillis = 0; // нулевая отметка
  long interval = 1000;    // интервал для сравнения
 
void setup() {
Wire.begin();

 pinMode (ENA, OUTPUT); 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 
 pinMode(s0, OUTPUT); 
 pinMode(s1, OUTPUT); 
 pinMode(s2, OUTPUT); 
 pinMode(s3, OUTPUT); 
 pinMode(out, INPUT); 

 digitalWrite(s0, HIGH); 
 digitalWrite(s1, HIGH); 
 Serial.begin(9600); 

PLECHO.attach(2);
LOKOT.attach(2);
ZAHVAT.attach(6);

 PLECHO.writeMicroseconds(1250);
 LOKOT.writeMicroseconds(1250);
ZAHVAT.write(125);
attachInterrupt(4,Probeg,CHANGE);//на 19-ом пин
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  void loop  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void loop() {

   
   unsigned long currentMillisb = millis(); // берем отсечку текущего времени
     if(currentMillisb - previousMillis > interval) // сравниваем разницу отсечки и последней нулевой отметки с базовым интервалом
   {
    previousMillis = currentMillisb; // обновляем нулевую отметку
      ZAXVAT_VZYAT();
      
}
   
     MOTOR_RIGHT(100);

 
 

   unsigned long currentMillisc = millis(); // берем отсечку текущего времени
     if(currentMillisc - previousMillis > interval) // сравниваем разницу отсечки и последней нулевой отметки с базовым интервалом
   {
    previousMillis = currentMillisc; // обновляем нулевую отметку
     ZAXVAT_OTPUSTIT(); }
     

   MOTOR_RIGHT(1);
 
  
 // ZAXVAT_VZYAT();

  
 // PODNYAT();

}


void Probeg() //поворот робота(подразумевается,что этим смогу определить положение)
{
  if( NAPRAVLENIE == 0 ){//когда поворачивается вправо
   encoder = encoder+1;
  }
  
  else{
    encoder = encoder-1;
  }//Serial.print("   ");Serial.println(encoder);
}


void MOTOR_RIGHT(int d)// значение,на сколько повернется робот
{  
  if(encoder < d) {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  analogWrite(ENA,160);
  NAPRAVLENIE=0;
  }
  else if(encoder > d) {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH); 
  analogWrite(ENA,160);
  NAPRAVLENIE=1;
  }
  else if(encoder = d){
   digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  }
  
}

   //<<<<<< ВЗЯТЬ КУБИК >>>>>>>>>>
void ZAXVAT_VZYAT(){
write(150, 100);
 }
 
   //<<<<<< ОПУСТИТЬ КУБИК >>>>>>>>>>
void ZAXVAT_OTPUSTIT(){
write(120, 100);
}

   
  //<<<<<< ПОДНЯТЬ ЛОКОТЬ >>>>>>>>>>
void PODNYAT(){
write(50, 100);
   }

  //<<<<<< ОПУСТИТЬ ЛОКОТЬ >>>>>>>>>>
void OPUSTIT(){
write(0, 100);
}
