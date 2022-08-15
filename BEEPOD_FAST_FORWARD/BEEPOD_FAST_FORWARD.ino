#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire
#include <SoftwareSerial.h>

// получаем углы при помощи DMP
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps_V6_12.h"
MPU6050 mpu;
float angleX = 0;
float angleY = 0;
float angleZ = 0;

bool flag = false; //флаг для режима робота


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
1870, 2050, 1343, 1100, 1122, 1370,400,
1850, 2050, 948, 1443, 1527, 948,300,
2080, 1850, 1000, 1510, 1537, 1002,300,
2080, 1870, 1300, 1122, 1062, 1350,400
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

void setup(){
  Serial.begin(9600);
  for (int i=0; i<ServCount; i++){  // пересчет(сервоприводов)
    Servos[i].attach(NumControl[i],MinTiming,MaxTiming); //att-прикреплять сервы по массиву Номеров пинов
    APos[i]=Servos[i].read();
  }                           
  MovePos(StartPos);
  Serial.println("--------------positioning-------------------");
  delay(StartTimeOut);
  Wire.setClock(400000);
  mpu.initialize();
  initDMP();
  getAngles();
  delay(7000);
  Serial.println("--------------START-------------------");
  delay(1000); 
}

void PlaySteps(int arSteps[], int StepCount){
  int arTMP[ServCount+1];
  for(int i=0; i<StepCount; i++){
    for(int j=0; j<ServCount+1; j++)
      arTMP[j]=arSteps[j+(ServCount+1)*i]+random(-Entrop,Entrop);
    MovePos(arTMP); 
  }
}

void loop(){
if(flag == false){    
for(int iter = 1; iter <= 5; iter++){

  getAngles();
  Serial.print(angleX); Serial.print(',');
  Serial.print(angleY); Serial.print(',');
  Serial.println(angleZ);
  
  if (-25 < angleX && angleX < 25 && -20 < angleY && angleY < 20) {  
     Serial.print('\t');
     Serial.print("итерация №");
     Serial.print(iter);
     Serial.println("  OK");
    PlaySteps(StepForward,ForwardStepCount);
    
    for(int i=6; i<28; i=i+7){
      
       Serial.print('\t');
      Serial.println(StepForward[i]);
      }
   }

 else{
   Serial.print("CRASH  ");
      for(int i=6; i<28; i=i+7){
       Serial.print('\t');
      Serial.println(StepForward[i]);
    }
    MovePos(StartPos);
    flag = true;
    break;
  }
 }
 flag = true;  
}
MovePos(StartPos);
}

// НУЖНЫЕ ПЕРЕМЕННЫЕ
const float toDeg = 180.0 / M_PI;
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
// инициализация
void initDMP() {
  devStatus = mpu.dmpInitialize();
  mpu.setDMPEnabled(true);
  mpuIntStatus = mpu.getIntStatus();
  packetSize = mpu.dmpGetFIFOPacketSize();
}
// получение углов в angleX, angleY, angleZ
void getAngles() {
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    angleX = ypr[2] * toDeg;
    angleY = ypr[1] * toDeg;
    angleZ = ypr[0] * toDeg;
  }
}
