#include <Multiservo.h>   //Подключение библиотеки multiservo
#include <Wire.h>         //Подключение библиотеки Wire
#include <SoftwareSerial.h>
#include <Servo.h>

//Номера пинов с сервоприводами
int NumControl[] = {1, 2, 3, 5, 6, 7, 15,16,17, 9,10,11};
//int NumControl[] = {1, 2, 3};
//Исходное положение
int StartPos[] = {2000, 2000, 1130, 1250, 1256, 1176,  1200,1850,1280, 1500,600,1800};
int NextPos[] = {2000, 2000, 1130, 1250, 1256, 1176,  1200,1850,1280, 1500,600,1800};
Multiservo Servos[12];//Массив сервоприводов
int ServCount = 12;//Константа хранит количество сервоприводов
//int ServCount = 3;
int MinTiming = 540;//Минимальная длительность импульса
int MaxTiming = 2400;//Максимальная длительность импульса
int APos[12];//Массив хранит предыдущие координаты сервоприводов для
//расчета дискретных шагов приращения для перехода на заданную позицию
int BPos[12];//Массив для передачи параметров новой позиции

String str;//="2000, 2000, 1130, 1250, 1256, 1176,  1200,1850,1280, 1500,600,1800";


void MovePos(int xPos[]){
int Delta=0;
int MaxDelta=0;
for (int i=0; i<ServCount; i++){
    Delta=abs(APos[i]-xPos[i]);
    if (MaxDelta < Delta) MaxDelta = Delta;
}
MaxDelta/=10;
for (int i=0; i<MaxDelta; i++)
    for (int j=0; j<ServCount; j++){
      Servos[j].writeMicroseconds(map(i,0,MaxDelta,APos[j],xPos[j]));
      delayMicroseconds(1000);
    }

  for (int i=0; i<ServCount; i++)
    APos[i]=xPos[i];
}

void setup(){
//Инициализация сервоприводов
for (int i=0; i<ServCount; i++){
    Servos[i].attach(NumControl[i],MinTiming,MaxTiming);
//Вычисление и присвоение "предыдущей позиции"
    APos[i]=Servos[i].read();
} 

Serial.begin(9600);
  Serial.setTimeout(30);

//Переход в стартовую позицию
MovePos(StartPos);
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
while (Serial.available()){
    str=Serial.readString();
    String buff;
    int command[12];
    for(int i=0; i<12; i++){
    buff = getValue(str, ',', i);
    command[i] =  buff.toInt();
    Serial.println(command[i]);
    }
    for(int i=0; i<12; i++){
      if(command[i]<540 || command[i]>2100) break;
      if(command[9]<1400 || command[9]>1600) break;
    NextPos[i] = command[i];
    }
    
   str="";
   buff ="";
   MovePos(NextPos);
}

}
