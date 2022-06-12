#include "Adafruit_MPU6050.h"
#include "Adafruit_Sensor.h"
#include <Wire.h>


Adafruit_MPU6050 mpu;

#include "giromath.h"
#include "MadgwickAHRS.h"

sensors_event_t a, g, temp;

const int LEFTwheel_A = 4;
const int LEFTwheel_B = 2;

const int RIGHTwheel_A = 33;
const int RIGHTwheel_B = 32;

const int LA = 1;
const int LB = 2;
const int RA = 3;
const int RB = 4;

const int  FREQ = 200;
const int  RESOLUTION = 10;
const int maxpower = 1000;
const int minWorkPower = 150;
const int minPower = 50;

int  MotorRight =  0;
int  MotorLeft = 0;

//=================================

void LEFTwheel_rotation(int power_L);
void RIGHTwheel_rotation(int power_R);
//=================================

void TaskCarPosition(void *pvParameters)
{
  (void) pvParameters;
  t0 = micros();
  while (true)
  {
    // Опрос гироприбора MPU6050 (Adafruit_MPU6050)
    mpu.getEvent(&a, &g, &temp);
    micros_ = micros();
    dt = micros_ - t0; // Длительность предыдущего периода регулирования.
    t0 = micros_; //Точка начала нового периода регулирования.
    double Dt = double(dt) * 0.000001;

    GyroZ =  g.gyro.z - CompensatorZ;
    //Расчет текущего положения робота фильтром Маджвика
    MadgwickAHRSupdateIMU(Dt, g.gyro.x - CompensatorX , g.gyro.y - CompensatorY, GyroZ, a.acceleration.x, a.acceleration.y, a.acceleration.z);

    quat[0] = q0; quat[1] = q1; quat[2] = q2; quat[3] = q3;
    // преобразуем кватернион в углы Эйлера
    quat2Euler(&quat[0], &imu[0]);
/*
    AcZsum = imu[2]; //Вращение вокруг оси
    Iz += (AcZsum - AzCom) * Dt * Kiz;
    Iz = constrain(Iz, -maxIz, maxIz);
    // ПИД - регулятор
    PIDz = AcZsum * Kpz + GyroZ * Kdz + Iz; //Пока без интегрального звена + вправо - влево //+ dGyroZ*Kddz
    PIDz = constrain( PIDz, -maxPidz, maxPidz);
    // Управление моторами
    MotorRight =  int(-PIDz * 40.0);
    MotorLeft = int(PIDz * 40.0);
    // Команды моторам
    RIGHTwheel_rotation(MotorRight);
    LEFTwheel_rotation(MotorLeft);
*/
    if (i > 40)
    {
      Serial.print(imu[2] / TO_RAD); Serial.print("  "); Serial.println(AcZsum / TO_RAD);
      i = 0;
    }
    i++;
    vTaskDelay(5);  //Передача управления на 5 миллисекунд (программа работает в FreeRTOS)
  }
}

void TaskNewCommand(void *pvParameters)
{
  (void) pvParameters;
  while (true)
  {
    vTaskDelay(10);  // one tick delay (10ms) in between reads
  }
}

//=================================
void setup_car()
{
  pinMode(LEFTwheel_A, OUTPUT);
  pinMode(LEFTwheel_B, OUTPUT);
  pinMode(RIGHTwheel_A, OUTPUT);
  pinMode(RIGHTwheel_B, OUTPUT);

  ledcAttachPin(LEFTwheel_A, LA); // assign pins to channels
  ledcAttachPin(LEFTwheel_B, LB);
  ledcAttachPin(RIGHTwheel_A, RA);
  ledcAttachPin(RIGHTwheel_B, RB);

  // Initialize channels
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(LA, FREQ, RESOLUTION); // FREQ Hz PWM, 10 -bit resolution
  ledcSetup(LB, FREQ, RESOLUTION); // FREQ Hz PWM, 10 -bit resolution
  ledcSetup(RA, FREQ, RESOLUTION); // FREQ Hz PWM, 10 -bit resolution
  ledcSetup(RB, FREQ, RESOLUTION); // FREQ Hz PWM, 10 -bit resolution
  ledcWrite(LA, 0);
  ledcWrite(LB, 0);
  ledcWrite(RA, 0);
  ledcWrite(RB, 0);
}


//=================================
void LEFTwheel_rotation(int power_L) // +/- 1000
{
  power_L = constrain( power_L, -maxpower, maxpower);
  if (power_L < 0)
  {
    power_L = -power_L;
    if (power_L > minPower)
      power_L = map(power_L, 0, maxpower, minWorkPower, maxpower);
    else power_L = 0;
    ledcWrite(LA, 0);
    ledcWrite(LB, power_L);
  }
  else
  {
    if (power_L > minPower)
      power_L = map(power_L, 0, maxpower, minWorkPower, maxpower);
    else power_L = 0;

    ledcWrite(LB, 0);
    ledcWrite(LA, power_L);
  }
}

//=================================
void RIGHTwheel_rotation(int power_R) // +/- 1000
{
  power_R = constrain( power_R, -maxpower, maxpower);
  if (power_R < 0)
  {
    power_R = -power_R;
    if (power_R > minPower)
      power_R = map(power_R, 0, maxpower, minWorkPower, maxpower);
    else power_R = 0;

    ledcWrite(RA, 0);
    ledcWrite(RB, power_R);
  }
  else
  {
    if (power_R > minPower)
      power_R = map(power_R, 0, maxpower, minWorkPower, maxpower);
    else power_R = 0;

    ledcWrite(RB, 0);
    ledcWrite(RA, power_R);
  }
}
//=============================================
void Calc_CompensatorZ(float mill_sec)
{
  uint32_t ms = mill_sec;
  double i = 0;
  CompensatorZ = 0;
  CompensatorX = 0;
  CompensatorY = 0;
  uint32_t  timer = millis();
  uint32_t endtime = millis() + ms;
  while (endtime > timer) {
    timer = millis();
    mpu.getEvent(&a, &g, &temp);

    CompensatorZ += g.gyro.z;
    CompensatorX += g.gyro.x;
    CompensatorY += g.gyro.y;
    delay(2);
    i++;
  }
  CompensatorZ /= i;
  CompensatorX /= i;
  CompensatorY /= i;
}
