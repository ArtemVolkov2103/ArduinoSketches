#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600 //0 deg
#define MAX_PULSE_WIDTH 2500 //180 deg
#define DEFAULT_PULSE_WIDTH 1560 //90 degrees
#define FREQUENCY 50
uint8_t servonum = 0;
int pot = 0;
void setup ()
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

void loop ()
{
  
  /*
    pot = map(analogRead(0), 0, 1023, 0, 180);
    Serial.print(analogRead(0));Serial.print("  ");Serial.println(pot);
    pwm.setPWM(0, 0, pulseWidth(pot));
  */
  /*
  // Вращение 16 сервоприводов
  for (int pulselen = 0; pulselen < 180; pulselen++)
  {
    for (int i = 0; i < 16; i++) {
      pwm.setPWM(i, 0, pulseWidth(pulselen));
      Serial.println(pulseWidth(pulselen));
    }
  }
  delay(250);

  for (int pulselen = 180; pulselen > 0; pulselen--)
  {
    for (int i = 0; i < 16; i++) {
      pwm.setPWM(i, 0, pulseWidth(pulselen));
      Serial.println(pulseWidth(pulselen));

    }
  }
  delay(250);
*/
      pwm.setPWM(0, 0, pulseWidth(90));
      pwm.setPWM(1, 0, pulseWidth(90));
      pwm.setPWM(2, 0, pulseWidth(90));
      pwm.setPWM(3, 0, pulseWidth(90));

      pwm.setPWM(4, 0, pulseWidth(90));
      pwm.setPWM(5, 0, pulseWidth(90));
      pwm.setPWM(6, 0, pulseWidth(90));
      pwm.setPWM(7, 0, pulseWidth(90));

      pwm.setPWM(8, 0, pulseWidth(90));
      pwm.setPWM(9, 0, pulseWidth(90));
      pwm.setPWM(10, 0, pulseWidth(90));
      pwm.setPWM(11, 0, pulseWidth(90));
      //pwm.writeMicroseconds(0, 1560);
}
int pulseWidth(int angle)//угол поворота серво
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
