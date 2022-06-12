#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire

//int SensorPin = A0;
int ServCount = 6;    //count сущ[kaʊnt] - пересчет(сервоприводов)
//int MinDist = 200;
int MinTiming = 540;  //минимальный угол
int MaxTiming = 2400;  //максимальный угол
int StartTimeOut = 5000;
int ForwardStepCount = 4;  //подсчет движений для(шагов вперед)
//int ReversStepCount = 8;
//int RightStepCount = 2;
//int LeftStepCount = 2;
int Entrop = 10;

int NumControl[] = {1, 2, 3,  5, 6, 7}; //массив Номеров пинов с сервоприводами
int StartPos[] = {2000, 2000, 1122, 1303, 1196, 982, 10000};

//unsigned long ReversTimer = 0;
//unsigned long ReversTimeOut = 18000;
//boolean isReversTimer=false;
//int Signal = 0;
Multiservo Servos[6];//Массив кол-ва сервоприводов
int APos[6];        

int StepLeft[] = {                       // шаги вперед.
2000, 1834, 1276, 1129, 1062, 1319,1000,
2000, 1791, 948, 1604, 1537, 888,1000,
2113, 1791, 948, 1604, 1537, 888,1000,
2113, 1834, 1300, 1075, 1062, 1319,1000,

};

/*int StepRevers[] = {
776, 1291, 1997, 1972, 1629, 1608, 550,
776, 1291, 1438, 1615, 1629, 1608, 950,
776, 1454, 1115, 1065, 1629, 1608, 550,
776, 1454, 1115, 1645, 1629, 1608, 550,
1018, 1733, 1127, 1094, 2286, 2293, 550,
1079, 1733, 1509, 1741, 2241, 2293, 950,
1079, 1733, 2135, 2046, 2239, 2293, 550,  
1079, 1733, 1749, 2046, 2239, 2293, 550};

int StepRight[] = {
576, 1238, 1414, 1701, 2239, 2293, 800,
792, 1278, 1203, 1510, 2215, 1651, 800};

int StepLeft[] = {
576, 1238, 1414, 1701, 2239, 2293, 800,
833, 1037, 1522, 1918, 2239, 2293, 800};
*/
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

void setup(){
  for (int i=0; i<ServCount; i++){              // пересчет(сервоприводов)
    Servos[i].attach(NumControl[i],MinTiming,MaxTiming); //att-прикреплять сервы по массиву Номеров пинов
    APos[i]=Servos[i].read();   //                    
  }                             
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
/*
int CheckSensor(){
  int summ = 0;
  for (int i=0; i<100; i++)
    summ+=analogRead(SensorPin);
  return summ/=100;
}
*/
void loop()
{
  PlaySteps(StepLeft,ForwardStepCount); //delay(1000);
 /* Signal=CheckSensor();
  if (Signal>MinDist){
    if (!isReversTimer){
      isReversTimer=true;
      ReversTimer=millis();
    }
    else{
      if (millis()-ReversTimer>ReversTimeOut){
        for(int i=0; i<10; i++){
          PlaySteps(StepRevers,ReversStepCount);
          if (CheckSensor()<MinDist)break;
        }
        ReversTimer=millis();
      }
    }
    if (random(2)==1){
      PlaySteps(StepRight,RightStepCount);
      if(Signal<CheckSensor())
        for(int i=0; i<10; i++){  
          PlaySteps(StepLeft,LeftStepCount); 
          delay(400);
          if (CheckSensor()<MinDist)break; 
        }       
    }else{
      PlaySteps(StepLeft,LeftStepCount);
      if(Signal<CheckSensor())
        for(int i=0; i<10; i++){  
          PlaySteps(StepRight,RightStepCount); 
          delay(400);
          if (CheckSensor()<MinDist)break; 
        }       
    }
  }
  else{ 
    isReversTimer=false;
    PlaySteps(StepForward,ForwardStepCount);
  } 
*/  
}
