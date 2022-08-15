<<<<<<< HEAD
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 50

void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, INPUT);
  Serial.begin(9600);
  
}

void StartPos(){
  for (int i = 0; i < 12; i++) {
      pwm.writeMicroseconds(i, 1560);
    }
  }
bool isInStartPos = false;
void loop ()
{
  if(!isInStartPos) StartPos();
  
  for (int j = 1700; j > 1400; j-=5) {
    for (int i = 0; i < 12; i +=2) {

      pwm.writeMicroseconds(i, j);
      delay(1);
    }
  }
  for (int j = 1400; j < 1700; j+=5) {
    for (int i = 0; i < 12; i +=2) {

      pwm.writeMicroseconds(i, j);
      delay(1);
    }
  }

}
=======
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 50

void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, INPUT);
  Serial.begin(9600);
  
}

void StartPos(){
  for (int i = 0; i < 12; i++) {
      pwm.writeMicroseconds(i, 1560);
    }
  }
bool isInStartPos = false;
void loop ()
{
  if(!isInStartPos) StartPos();
  
  for (int j = 1700; j > 1400; j-=5) {
    for (int i = 0; i < 12; i +=2) {

      pwm.writeMicroseconds(i, j);
      delay(1);
    }
  }
  for (int j = 1400; j < 1700; j+=5) {
    for (int i = 0; i < 12; i +=2) {

      pwm.writeMicroseconds(i, j);
      delay(1);
    }
  }

}
>>>>>>> 017f10555ff9a8c4969ec0cfbf1da4fe08c6208e
