#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire

int ServCount = 8;    //count сущ[kaʊnt] - пересчет(сервоприводов)
int MinTiming = 540;  //минимальный угол
int MaxTiming = 2400;  //максимальный угол
int StartTimeOut = 5000;
int ForwardStepCount = 4;  //подсчет движений для(шагов вперед)

int Entrop = 10;

int NumControl[] = {1, 2, 3, 5, 6, 7, 8, 9}; //массив Номеров пинов с сервоприводами
int StartPos[] = {1100, 1100, 1200, 1200, 1200, 1170, 1520, 1420, 5000};
Multiservo Servos[8];//Массив кол-ва сервоприводов
int APos[8];        

int StepForvard[] = {                       // шаги вперед.
1140, 970, 1020, 1400, 1400, 1000, 1520, 1420, 300,     //наклон налево и левая вперед правая назад
1140, 1050, 1400, 1000, 1000, 1400, 1520, 1420, 600,
800, 1230, 1400, 1000, 1000, 1400, 1520, 1420, 300,
950, 1230, 1020, 1400, 1400, 1000, 1520, 1420, 600,
};


void setup(){
  for (int i=0; i<ServCount; i++){              // пересчет(сервоприводов)
    Servos[i].attach(NumControl[i],MinTiming,MaxTiming); //att-прикреплять сервы по массиву Номеров пинов
    APos[i]=StartPos[i]+10;                
  }                             
  MovePos(StartPos);
  delay(StartTimeOut);
}

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

void PlaySteps(int arSteps[], int StepCount){
  int arTMP[ServCount+1];
  for(int i=0; i<StepCount; i++){
    for(int j=0; j<ServCount+1; j++)
      arTMP[j]=arSteps[j+(ServCount+1)*i]+random(-Entrop,Entrop);
    MovePos(arTMP); 
  }
}

void loop()
{
  PlaySteps(StepForvard,ForwardStepCount);
  //MovePos(StartPos);
  //delay(5000);
}
