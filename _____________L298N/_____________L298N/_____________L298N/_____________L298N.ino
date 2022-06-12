/*
Прошивка взята с http://ecnc.ru/flash/l298n_etching
Прошивка для платы Ардуино написана на языке Processing в среде разработки Arduino 1.0.5 r2 в операционной системе Windows.
Эта прошивка предназначена для Arduino (Mega, UNO, Nano) и работает с 3-хосевым станком с ЧПУ. Можно использовать любые драйверы для управления биполярными шаговыми двигателями с четырехконтактным контролем по схеме двойной мост, например драйверы шаговых двигателей L298N. Используются любые подходящие шаговые двигатели, например 17HS3404N, 17HS2408, 42HS40, двигатели в корпусе Nema.
Прошивка может использоваться для лазерной гравировки для обведения орнаментов и силуэтов.

Внимание! Теперь необходимо следить за тем, чтобы скорость передачи данных через COM-порт, установленная в прошивке, совпадала со скоростью, установленной в программе управления дешёвым станком с ЧПУ на Ардуино.

Строка в прошивке, в которой устанавливается скорость: Serial.begin(9600); 
При несовпадении скоростей программа будет "залипать", а станок не будет подавать признаков жизни.
*/

int motorPins[3][4] = {{2, 3, 4, 5},{6, 7, 8, 9},{10, 11, 12, 13}};
int count;
int count2[3] = {0,0,0};
int val = 0;
int rot=0;
int incomingByte = 0;
int sign=1;
long delayTime;

//Процедура настройки прошивки
void setup() {
int i;
Serial.begin(9600);

pinMode(A2, OUTPUT);
for (i=0; i<3; i++) {
 for (count = 0; count < 4; count++) {
  pinMode(motorPins[i][count], OUTPUT); //установка режима работы цифровых pin'ов Ардуино
 }
}
delayTime=2000; //задержка между шагами 3 мс (2 мс - время реакции ШД на подачу напряжения)
}

//Поворот двигателя с номерм sm на один шаг вперёд в направлении st (-1 или 1)
void moveDir(int sm, int st) {
 if ((st==1 ) && (count2[sm]) == 4) count2[sm] = 0;
 if ((st==-1) && (count2[sm]) == 1) count2[sm] = 5;
 count2[sm]+=st;

 switch (count2[sm]) {
  case 1:
   digitalWrite(motorPins[sm][0],HIGH);
   digitalWrite(motorPins[sm][1],LOW);
   digitalWrite(motorPins[sm][2],LOW);
   digitalWrite(motorPins[sm][3],HIGH);
   break;
  case 2:
   digitalWrite(motorPins[sm][0],LOW);
   digitalWrite(motorPins[sm][1],HIGH);
   digitalWrite(motorPins[sm][2],LOW);
   digitalWrite(motorPins[sm][3],HIGH);
   break;
  case 3:
   digitalWrite(motorPins[sm][0],LOW);
   digitalWrite(motorPins[sm][1],HIGH);
   digitalWrite(motorPins[sm][2],HIGH);
   digitalWrite(motorPins[sm][3],LOW);
   break;
  case 4:
   digitalWrite(motorPins[sm][0],HIGH);
   digitalWrite(motorPins[sm][1],LOW);
   digitalWrite(motorPins[sm][2],HIGH);
   digitalWrite(motorPins[sm][3],LOW);
   break;
 }
 
}

//Поворот двигателя с номерм sm на один шаг вперёд
void moveForward(int sm) {
 moveDir(sm,1);
}

//Поворот двигателя с номерм sm на один шаг назад
void moveBackward(int sm) {
 moveDir(sm,-1);
}

//Задержка в микосекундах
void delayMicros(long wt){
unsigned long mls;
unsigned int mks;

mls=(unsigned long)(wt / 1000);
mks=(unsigned int)(wt % 1000);
if (mls>0) delay(mls);
if (mks>0) delayMicroseconds(mks);
}

//Одновременный поворот двигателей 0, 1, 2 на x, y, z шагов соответственно
void MoveSM(long x, long y, long z) {
long c[3], c2[3];
double c1[3], d[3];
long m, i;
boolean flg;

c[0] = x;
c[1] = y;
c[2] = z;

m = 1;
for (i=0; i<2; i++) {
 if (m < abs(c[i])) m = abs(c[i]);
}

for (i=0; i<2; i++) {
 c1[i] = 0;
 d[i] = 1.0 * c[i] / m;
 c2[i] = 0;
}

flg = false;
for (i=0; i<2; i++) {
 if (abs(c1[i]) < abs(c[i])) flg=true;
}
while (flg) {
 flg=false;
 for (i=0; i<2; i++) {
  if (abs(c1[i]) < abs(c[i]))
  c1[i] += d[i];
  if (abs(c1[i]) - abs(c2[i]) >= 0.5) {
  if (c[i]>0) {
  c2[i]++;
  moveForward(i);
  } else {
  c2[i]--;
  moveBackward(i);
  }
  }
  if (abs(c1[i]) < abs(c[i])) flg=true;
 }
 delayMicros(delayTime);
}
if (z>0) {
 digitalWrite(A2, HIGH);
}
if (z<0) {
 digitalWrite(A2, LOW);
}
}

//Основной цикл
void loop() {
if (Serial.available() > 0) { //Пришла команда
 long c[4]={0,0,0,0};
 int i;

 sign=1;
 i=0;
 incomingByte = Serial.read();
 while (incomingByte!=';') { //Читаем входящую строку, признак конца строки знак "точка с запятой"
  if (c[i]==0) {
  if (incomingByte=='-') sign=-1;
  }
  if (incomingByte==',') {
  c[i]*=sign;
  sign=1;
  i++;
  } else if (incomingByte>='0' && incomingByte<='9') {
  c[i]=c[i]*10+incomingByte-'0';
  }
  while (Serial.available() == 0) {
  delayMicroseconds(1);
  }
  incomingByte = Serial.read();
 }
 c[i]*=sign;
 if (c[3]>0) delayTime=c[3];
 MoveSM(c[0],c[1],c[2]); //Вращаем двигатели на заданное число шагов
 Serial.println("OK"); //Отправляем компьютеру сообщение "OK", значит можно высылать новую команду
}
else
 delayMicroseconds(1); //Если ничего не пришло, ждём 1 микросекунду
}
