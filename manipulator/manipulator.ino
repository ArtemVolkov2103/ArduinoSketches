#include <Wire.h>
#include <Multiservo.h>
Multiservo PLECHO,LOKOT,ZAHVAT;


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

PLECHO.attach(0);
LOKOT.attach(1);
ZAHVAT.attach(4);


 
attachInterrupt(4,Probeg,CHANGE);//на 19-ом пине
}


void loop() {
 //  delay(5000); // НЕЛЬЗЯ ВКЛЮЧАТЬ delay
  //ПОТОМУ ЧТО ПРИ ВЫВОДЕ ВСЕ ПРОЦЕССЫ ТОРМОЗЯТСЯ
 PLECHO.writeMicroseconds(1250);
 LOKOT.writeMicroseconds(1250);
 ZAHVAT.write(Zahvat); 
 
 MOTOR_RIGHT(100);//поворачиваю вправо на 300 делений энкодера 
 MOTOR_RIGHT(200);
 MOTOR_RIGHT(300);
 /*unsigned long currentMillis = millis();
  
  //проверяем не прошел ли нужный интервал, если прошел то
  if(currentMillis - previousMillis > 2000) {
    // сохраняем время последнего переключения
   previousMillis = currentMillis; 
 MOTOR_LEFT(1);}*/
}


int color(){
   RGB();
    if (red >20 && green >20 && blue >20) { 
  //Serial.println(" PUSTO");
   CVET=0;//"код" цвета-пустоты
 } 
   
  else if (red < blue && red < green && red < 12 && 4 < red) { 
 //Serial.println(" RED"); 
   CVET=1;}//"код" цвета
   
  else if (green > blue && red > blue && blue>5) { 
 //Serial.println(" BLUE"); 
   CVET=2; } 
   
  else if (red < 7 && green<7 && blue < 7) { 
 //Serial.println(" WHITE");
   CVET=3; } 

  else {}
  return CVET;
}


void Probeg() //поворот робота(подразумевается,что этим смогу определить положение)
{
  if( NAPRAVLENIE == 0 ){//когда поворачивается вправо
   encoder = encoder+1;
  }
  
  else{
    encoder = encoder-1;
  }// НЕЛЬЗЯ ВКЛЮЧАТЬ Serial.println(encoder);
  //ПОТОМУ ЧТО ПРИ ВЫВОДЕ ВСЕ ПРОЦЕССЫ ТОРМОЗЯТСЯ
}

//по часовой
void MOTOR_RIGHT(int d)// значение,на сколько повернется робот
{  NAPRAVLENIE=0;
  if(encoder <= d) {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  analogWrite(ENA,180);
 }
  else {
   digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 

  }
  
}


void MOTOR_LEFT(int a)// значение,на сколько повернется робот
{  NAPRAVLENIE=1;
  if(encoder >= a) {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH); 
  analogWrite(ENA,180);
  
}
  else {
digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  }
}


void MOTOR_STOP()//просто остановка
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  analogWrite(ENA,0);
}


void RGB() //способ определения цвета
{ 
 digitalWrite(s2, LOW); 
 digitalWrite(s3, LOW); 
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 digitalWrite(s3, HIGH); 
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 digitalWrite(s2, HIGH); 
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}

void COM_PORT(){
  // выводим значение в консоль
 Serial.print("       RED :" + String(red)); 
 Serial.print("  GREEN : " + String(green)); 
 Serial.println("  BLUE : " + String(blue));  
 Serial.print("                                        ");
Serial.println(encoder);
}
