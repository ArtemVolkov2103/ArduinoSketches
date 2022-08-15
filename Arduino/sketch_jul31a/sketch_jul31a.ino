
int motorPin1 = 8; // Blue - 28BYJ48 pin 1
int motorPin2 = 9; // Pink - 28BYJ48 pin 2
int motorPin3 = 10; // Yellow - 28BYJ48 pin 3
int motorPin4 = 11; // Orange - 28BYJ48 pin 4

int motor1Pin1 = 4; // левый
int motor1Pin2 = 5; // 
int motor1Pin3 = 6; //
int motor1Pin4 = 7; // 


const int analogPin = 1;//левый
const int analogPin2 = 2;//среднии
const int analogPin3 = 3;//правый

int motorSpeed = 1200; //скорость двигателя-не менять
int count = 0; // начальное число шагов
int countsperrev = 540; // число шагов на 1 оборот
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};/*как-то связано 
  с обмотками*/


void setup() {
 //пины мотора выставляем как OUTPUT
pinMode(motorPin1, OUTPUT);//правый
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

pinMode(motor1Pin1, OUTPUT);//левый
pinMode(motor1Pin2, OUTPUT);
pinMode(motor1Pin3, OUTPUT);
pinMode(motor1Pin4, OUTPUT);

  Serial.begin(9600);   // Скорость работы порта
}

void loop() {
  int L = analogRead(analogPin);//левый
  int C = analogRead(analogPin2);//ЦЕНТРАЛЬНЫЙ
  int R = analogRead(analogPin3);//правый
 

 
   if (C>=300){// черный 700-300
                //белый 299-1
                
     Vpered1();//левый
     Vpered2();//правый
    }
    
    ////////////////////////////////////////////////////
    if (C >= 300 && L >= 300){// черный 700-300
                               //белый 299-1

    // Vpered1();//левый
       Vpered2();//правый
    }
    
    ///////////////////////////////////////////////////
       if (L >= 300){// черный 700-300
                      //белый 299-1 
     //Vpered1();//левый
     Vpered2();
    }
    
   ///////////////////////////////////////////////// 
    if (R>=300){// черный 700-300
                 //белый 299-1 
      Vpered1();
     //Vpered2();//правый
    }
   
   /////////////////////////////////////////////////// 
    if (C >= 300 && R >= 300){// черный 700-300
                               //белый 299-1

    Vpered1();//левый
                    // Vpered2();//правый
    }
    

}

void Vpered1()//левый
{
for(int i = 7; i >= 0; i--)//вращаем в 8 тактов
  {
setOutput1(i);
delayMicroseconds(motorSpeed);//малая остановка-для возможности прокрутки
  }
}

void Vpered2()//правый
{
for(int i = 0; i < 8; i++)//вращаем в 8 тактов
  {
setOutput(i);
delayMicroseconds(motorSpeed);//малая остановка-для возможности прокрутки
  }
}

void setOutput(int out)//сигнал на обмотки,где out-номер
{
digitalWrite(motorPin1, bitRead(lookup[out], 0));//правый
digitalWrite(motorPin2, bitRead(lookup[out], 1));
digitalWrite(motorPin3, bitRead(lookup[out], 2));
digitalWrite(motorPin4, bitRead(lookup[out], 3));
}

void setOutput1(int out1)//сигнал на обмотки,где out-номер
{
digitalWrite(motor1Pin1, bitRead(lookup[out1], 0));//левый
digitalWrite(motor1Pin2, bitRead(lookup[out1], 1));
digitalWrite(motor1Pin3, bitRead(lookup[out1], 2));
digitalWrite(motor1Pin4, bitRead(lookup[out1], 3));
}
