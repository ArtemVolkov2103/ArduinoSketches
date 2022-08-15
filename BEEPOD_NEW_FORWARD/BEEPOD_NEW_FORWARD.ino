#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire
#include "IRremote.h"
#include <SoftwareSerial.h>

int ServCount = 6;    //count сущ[kaʊnt] - пересчет(сервоприводов)
//int MinDist = 200;
int MinTiming = 540;  //минимальный угол
int MaxTiming = 2400;  //максимальный угол
int StartTimeOut = 5000;
int ForwardStepCount = 4;  //подсчет движений для(шагов вперед)
int ReversStepCount = 4;
int RightStepCount = 3;
int LeftStepCount = 4;
int Entrop = 10;

int NumControl[] = {1, 2, 3,  5, 6, 7}; //массив Номеров пинов с сервоприводами
int StartPos[] = {2000, 2000, 1122, 1243, 1256, 1176, 1000};

Multiservo Servos[6];//Массив кол-ва сервоприводов
int APos[6];        //начальная позиция угла сервы

int StepForward[] = {                       // шаги вперед.
1800, 2119, 1343, 1100, 1122, 1370,1000,
1783, 2119, 948, 1443, 1527, 948,1000,
2110, 1794, 1000, 1510, 1537, 1002,1000,
2113, 1834, 1300, 1122, 1062, 1350,1000
};

void MovePos(int xPos[]){            //move сущ[muːv] движение, ход, перемещение
  int Delta=0;                        //разница.
  int MaxDelta=0;                     //максимальная разница.
  unsigned long a=0;  
  unsigned long b=0;
  unsigned long TimeIter=0;  
  unsigned long DeltaTime=0;            //разница во времени.
  unsigned long TimePoint=0;            //point - точка(во времени)
  for (int i=0; i<ServCount; i++){ 
    Delta=abs(APos[i]-xPos[i]);  
    if (MaxDelta < Delta) MaxDelta = Delta;
  }
  MaxDelta/=2;
  for (int i=0; i<MaxDelta; i++)
    for (int j=0; j<ServCount; j++){
      TimePoint = micros();                   //point - точка(во времени)
      Servos[j].writeMicroseconds(map(i,0,MaxDelta,APos[j],xPos[j]));// преобразование начальную и конечну позиция угла сервы
      a=xPos[ServCount]*1000.0;
      b=MaxDelta*ServCount;
      TimeIter=a/b;
      DeltaTime=micros()-TimePoint;
      if (DeltaTime<TimeIter) delayMicroseconds(TimeIter-DeltaTime);
    }
  for (int i=0; i<ServCount; i++) APos[i]=xPos[i];
}

void setup() {
MovePos(StartPos);
  delay(StartTimeOut);
}

void PlaySteps(int arSteps[], int StepCount){
  int arTMP[ServCount+1];
  for(int i=0; i<StepCount; i++){
    for(int j=0; j<ServCount+1; j++)
      arTMP[j]=arSteps[j+(ServCount+1)*i]+random(-Entrop,Entrop);
    MovePos(arTMP); 
  }
}

void loop() {
       PlaySteps(StepForward,ForwardStepCount);  

}
