#include <GParser.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 100
bool isInStartPos = false;
int timer = 3;

char command[5];
char distanceOrAngle[5];

int j = 1700, k = 1400;
int m = 1560, n = 1560;
void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, OUTPUT);

  Serial.begin(9600);

}

void StartPos() {
  pwm.writeMicroseconds(1, 1560);
  pwm.writeMicroseconds(7, 1560);
  pwm.writeMicroseconds(9, 1560);

  pwm.writeMicroseconds(3, 1560);
  pwm.writeMicroseconds(5, 1560);
  pwm.writeMicroseconds(11, 1560);
  Lower_2410_legs();
  Lower_068_legs();
}


void CheckCommand(){
  int i = 0;
  char buffer[10];
  if (Serial.available() > 0) {
    //delay(100);
    memset(buffer, ' ', sizeof(buffer)); //очистка буффера
    //сохраним прочитанное в буфер
    while ( Serial.available() && i < sizeof(buffer)) {
      buffer[i++] = Serial.read();  //если вдруг буфер наполнен if(i>0){
    } //закрываем массив buffer[i++]=' ';
    //разобьем его на части, отделенные запятой
    sscanf(buffer, "%[^','],%s", &command, &distanceOrAngle);
  }
}

bool IsAnotherCommand(String nowCommand){
  CheckCommand();
  
  String tmp = (String)command;
  if (!tmp.equals(nowCommand)){
  Serial.print("its: ");
  Serial.println((String)command);  
        return true;
  }
  return false;
}

void Raise_2410_legs() { //поднять 3 ноги
  for (m; m < 1700; m += 5) {
    pwm.writeMicroseconds(2, m);//1400  - нога внизу
    pwm.writeMicroseconds(4, m);
    pwm.writeMicroseconds(10, m);
    delay(timer);
  }
}
void Lower_2410_legs() { //опустить 3 ноги
  for (m; m > 1560; m -= 5) {
    pwm.writeMicroseconds(2, m);//1400  - нога внизу
    pwm.writeMicroseconds(4, m);
    pwm.writeMicroseconds(10, m);
    delay(timer);
  }
}

void Raise_068_legs() { //поднять 3 ноги
  for (n; n < 1700; n += 5) {
    pwm.writeMicroseconds(0, n);//1400  - нога внизу
    pwm.writeMicroseconds(6, n);
    pwm.writeMicroseconds(8, n);
    delay(timer);
  }
}
void Lower_068_legs() { //опустить 3 ноги
  for (n; n > 1560; n -= 5) {
    pwm.writeMicroseconds(0, n);//1400  - нога внизу
    pwm.writeMicroseconds(6, n);
    pwm.writeMicroseconds(8, n);
    delay(timer);
  }
}

void Backward(int distance) {
  int maximum = 1700, minimum = 1400;
  double a = distance / 9.99; //количество итераций для поворота
  int integerA = floor(a);//целая часть
  double leftPart = a - integerA;//дробная часть
  int b = 1;
  if (integerA >= 1) { //если нужно пройти несколько больших шагов
    b = integerA;
    BackwardSteps(b,maximum,minimum);
  }
  maximum = 1560 + (1720 - 1560) * leftPart;
  minimum = 1560 - (1560 - 1400) * leftPart;
  BackwardSteps(1,maximum,minimum);
}
void BackwardSteps(int b,int maximum,int minimum) {
  for (int iter = 0; iter < b; iter++) {
    if(IsAnotherCommand("b")) break;

    for (j, k; j < maximum; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      //if(IsAnotherCommand("b")) break;
      delay(timer);
    }

    Lower_068_legs();
    Raise_2410_legs();
    for (j = maximum, k = minimum; j > minimum; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }
    Lower_2410_legs();
    Raise_068_legs();
    for (j = minimum, k = maximum; j < maximum; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      //if(IsAnotherCommand("b")) break;
      delay(timer);
    }
  }
}

void Forward(int distance) {
  int maximum = 1700, minimum = 1400;
  double a = distance / 9.9; //количество итераций для поворота
  int integerA = floor(a);//целая часть
  double leftPart = a - integerA;//дробная часть
  int b = 1;
  if (integerA >= 1) { //если нужно пройти несколько больших шагов
    b = integerA;
    ForwardSteps(b,maximum,minimum);
  }
  maximum = 1560 + (1720 - 1560) * leftPart;
  minimum = 1560 - (1560 - 1400) * leftPart;
  ForwardSteps(1,maximum,minimum);
}
void ForwardSteps(int b,int maximum,int minimum) {

  for (int iter = 0; iter < b; iter++) {
    for (j, k; j < maximum; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }

    Lower_2410_legs();
    Raise_068_legs();

    for (j = maximum, k = minimum; j > minimum; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }
    Lower_068_legs();
    Raise_2410_legs();

    for (j = minimum, k = maximum; j < maximum; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }
  }
}

void Left(int angle) {
  double a = angle / 15.5; //количество итераций для поворота 15,5
  int b = 1;
  int integerA = floor(a);//целая часть
  double leftPart = a - integerA;//дробная часть
  int maximum = 1700, minimum = 1400;
  if (integerA >= 1){
    b = a;
    LeftSteps(b,maximum,minimum);
  }
  maximum = 1560 + (1720 - 1560) * leftPart;
  minimum = 1560 - (1560 - 1400) * leftPart;
  LeftSteps(1,maximum,minimum);
}
void LeftSteps(int b, int maximum, int minimum) {
  for (int iter = 0; iter < b; iter++) {
    for (j, k; j > 1560; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, j);//из 1700
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);//из 1400
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }

    Lower_068_legs();
    Raise_2410_legs();

    for (j = 1560, k = 1560; j > minimum; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, k);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, k);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, j);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }

    Lower_2410_legs();
    Raise_068_legs();

    for (j = minimum, k = maximum; j < 1560; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, k);
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, k);

      pwm.writeMicroseconds(3, k);
      pwm.writeMicroseconds(5, j);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }
  }
}

void Right(int angle) {
  double a = angle / 13.5; //количество итераций для поворота 14,1
  int b = 1;
  int integerA = floor(a);//целая часть
  double leftPart = a - integerA;//дробная часть
  int maximum = 1700, minimum = 1400;
  if (integerA >= 1){
    b = a;
    RightSteps(b,maximum,minimum);
  }
  maximum = 1560 + (1720 - 1560) * leftPart;
  minimum = 1560 - (1560 - 1400) * leftPart;
  RightSteps(1,maximum,minimum);
}
void RightSteps(int b, int maximum, int minimum) {
  for (int iter = 0; iter < b; iter++) {
    for (j, k; j > 1560; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, j);//из maximum
      pwm.writeMicroseconds(7, j);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, k);//из minimum
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, k);
      delay(timer);
    }

    Lower_068_legs();
    Raise_2410_legs();

    for (j = 1560, k = 1560; j > minimum; j -= 5, k += 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, k);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, j);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, j);
      delay(timer);
    }

    Lower_2410_legs();
    Raise_068_legs();

    for (j = minimum, k = maximum; j < 1560; j += 5, k -= 5) {
      pwm.writeMicroseconds(1, j);
      pwm.writeMicroseconds(7, k);
      pwm.writeMicroseconds(9, j);

      pwm.writeMicroseconds(3, j);
      pwm.writeMicroseconds(5, k);
      pwm.writeMicroseconds(11, j);
      delay(timer);
    }
  }
}



void loop ()
{
  if (!isInStartPos) {
    StartPos();
    isInStartPos = !isInStartPos;
    delay(1000);
  }
  CheckCommand();

  if ((String)command == "r") {
    int AngleINT = atoi(distanceOrAngle);
    Right(AngleINT);
    Serial.print("command: ");
    Serial.print(command);
    Serial.print(" AngleINT: ");
    Serial.println(AngleINT);
    distanceOrAngle[0] = "";
  }
  if ((String)command == "l") {
    int AngleINT = atoi(distanceOrAngle);
    Left(AngleINT);
    Serial.print("command: ");
    Serial.print(command);
    Serial.print(" AngleINT: ");
    Serial.println(AngleINT);
    distanceOrAngle[0] = "";
  }
  if ((String)command == "f") {
    int distanceINT = atoi(distanceOrAngle);
    Serial.print("command: ");
    Serial.println(command);
    distanceOrAngle[0] = "";
    Forward(distanceINT);
  }
  if ((String)command == "b") {
    int distanceINT = atoi(distanceOrAngle);
    Serial.print("command: ");
    Serial.println(command);
    distanceOrAngle[0] = "";
    Backward(distanceINT);
  }
  if ((String)command == "s") {
    Serial.print("command: ");
    Serial.println(command);
    StartPos();
  }
  else StartPos();
    command[0] = "";


  //Backward();
  //Right();
  //Forward();
  //Left();
}
