<<<<<<< HEAD
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 100
bool isInStartPos = false;
int timer = 3;

int j = 1700, k = 1400;
int m = 1560, n = 1560;
void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, INPUT);
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

void Backward() {
  for (j, k; j < 1700; j += 5, k -= 5) {
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
  for (j = 1700, k = 1400; j > 1400; j -= 5, k += 5) {
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
  for (j = 1400, k = 1700; j < 1700; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Forward() {
  for (j, k; j < 1700; j += 5, k -= 5) {
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

  for (j = 1700, k = 1400; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1700; j < 1700; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Left() {
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

  for (j = 1560, k = 1560; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1720; j < 1560; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, k);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, k);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, j);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Right() {
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

  for (j = 1560, k = 1560; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1720; j < 1560; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, k);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, j);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, j);
    delay(timer);
  }
}
void Righta(int angle) {
  double a = angle/14.4;//количество итераций для поворота
  int b=1;
  int maximum = 1700, minimum = 1400;
  if(a >= 1) b = a;
  else {
    maximum = 1560 + (1720 - 1560) * a;
    minimum = 1560 - (1560 - 1400) * a;
    }
for(int iter = 0; iter <= b; iter++){
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
char inByte;
void loop ()
{
  if (!isInStartPos) {
    StartPos();
    isInStartPos = !isInStartPos;
    delay(500);
  }
  /*if (Serial.available() > 0) {
    inByte = Serial.read();
    switch (inByte) {
      case 'r': Right();break;
      case 'l': Left();break;
      case 'f': Forward();break;
      case 'b': Backward();break;
      case 's': StartPos();break;
      default:  StartPos();//при получении любого другого символа
    }
  }*/
  //Righta(90);
  //delay(2000);
  //Backward();
  //Right();
  //Forward();
  StartPos();
delay(5000);
  //Left();
}
=======
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 100
bool isInStartPos = false;
int timer = 3;

int j = 1700, k = 1400;
int m = 1560, n = 1560;
void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, INPUT);
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

void Backward() {
  for (j, k; j < 1700; j += 5, k -= 5) {
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
  for (j = 1700, k = 1400; j > 1400; j -= 5, k += 5) {
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
  for (j = 1400, k = 1700; j < 1700; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Forward() {
  for (j, k; j < 1700; j += 5, k -= 5) {
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

  for (j = 1700, k = 1400; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1700; j < 1700; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Left() {
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

  for (j = 1560, k = 1560; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1720; j < 1560; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, k);
    pwm.writeMicroseconds(7, j);
    pwm.writeMicroseconds(9, k);

    pwm.writeMicroseconds(3, k);
    pwm.writeMicroseconds(5, j);
    pwm.writeMicroseconds(11, k);
    delay(timer);
  }
}

void Right() {
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

  for (j = 1560, k = 1560; j > 1400; j -= 5, k += 5) {
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

  for (j = 1400, k = 1720; j < 1560; j += 5, k -= 5) {
    pwm.writeMicroseconds(1, j);
    pwm.writeMicroseconds(7, k);
    pwm.writeMicroseconds(9, j);

    pwm.writeMicroseconds(3, j);
    pwm.writeMicroseconds(5, k);
    pwm.writeMicroseconds(11, j);
    delay(timer);
  }
}
void Righta(int angle) {
  double a = angle/14.4;//количество итераций для поворота
  int b=1;
  int maximum = 1700, minimum = 1400;
  if(a >= 1) b = a;
  else {
    maximum = 1560 + (1720 - 1560) * a;
    minimum = 1560 - (1560 - 1400) * a;
    }
for(int iter = 0; iter <= b; iter++){
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
char inByte;
void loop ()
{
  if (!isInStartPos) {
    StartPos();
    isInStartPos = !isInStartPos;
    delay(500);
  }
  /*if (Serial.available() > 0) {
    inByte = Serial.read();
    switch (inByte) {
      case 'r': Right();break;
      case 'l': Left();break;
      case 'f': Forward();break;
      case 'b': Backward();break;
      case 's': StartPos();break;
      default:  StartPos();//при получении любого другого символа
    }
  }*/
  //Righta(90);
  //delay(2000);
  //Backward();
  //Right();
  //Forward();
  StartPos();
delay(5000);
  //Left();
}
>>>>>>> 017f10555ff9a8c4969ec0cfbf1da4fe08c6208e
