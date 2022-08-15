#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1560
#define FREQUENCY 50

MPU6050 mpu(0x68);
uint8_t fifoBuffer[45];  // буфер
// переменные для расчёта (ypr можно вынести в глобал)
Quaternion q;
VectorFloat gravity;
float ypr[3];
int startZ = 0, endZ = 0;
int delta = 0;  //разница между стартовым и через 3 секунды значением гироскопа
int zComp = 0;  //компенсатор дрейфа оси z
bool calibrated = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(1000000UL);  // разгоняем шину на максимум
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  // инициализация DMP
  mpu.initialize();
  delay(1000);
  mpu.dmpInitialize();
  mpu.setDMPEnabled(true);
}

int previousZ = 180;
int errorCount = 0;
void GetGyroData() {
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    // расчёты
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    //ypr[0]=ypr[0]*57;
    ypr[0] = map(ypr[0] * 57, -180, 180, 0, 360);
    if (calibrated) {
      ypr[0] = map(ypr[0], -zComp, 360 - zComp, 0, 360);
    }
    ypr[1] = map(ypr[1] * 57, -180, 180, 0, 360);
    ypr[2] = map(ypr[2] * 57, -180, 180, 0, 360);
    Serial.print(ypr[0]);  // вокруг оси Z
    Serial.print(", ");
    Serial.print(ypr[1]);  // вокруг оси Y
    Serial.print(", ");
    Serial.print(ypr[2]);  // вокруг оси X
    Serial.print(", ");
    Serial.print(zComp);  // вокруг оси X
    Serial.println();
    // для градусов можно использовать degrees()
  }
}


void MoveServo(int lastAngle, int nextAngle, int servoNum) {
  int delta = nextAngle - lastAngle;
  if (delta > 0) {
    for (int angle = lastAngle; angle < nextAngle; angle += delta / 10) {
      pwm.writeMicroseconds(servoNum, angle);
      //Serial.print(ypr[1]); Serial.print("\t"); Serial.println(angle);
      delay(2);
    }
  } else {
    for (int angle = lastAngle; angle > nextAngle; angle += delta / 10) {
      pwm.writeMicroseconds(servoNum, angle);
      //Serial.print(ypr[1]); Serial.print("\t"); Serial.println(angle);
      delay(2);
    }
  }
}


int servoAng = 90, servoAng2 = 90;
int servoAng1 = 45;
int a = 1540, a1 = 2020, a2 = 1540;

int i = 0;  // количество измерений для калибровки
static uint32_t tmr;
static uint32_t tmr1;


void loop() {
  if (millis() - tmr >= 11) {  // таймер на 11 мс (на всякий случай)
    tmr = millis();            // сброс таймера
    GetGyroData();
    if (!calibrated) {
      Serial.print("CALIBRATION ");
      if (tmr > 17000) calibrated = true;


      if (tmr < 50) startZ = ypr[0];//одно из первых показаний
      if (tmr > 16800 && tmr < 16900) { // все остальное время
        endZ = ypr[0];
        if (180 != endZ) {
          //interval = tmr;
          zComp = 180 - endZ;
          calibrated = true;
        }
      }

    }

    else if (calibrated) {
      if (ypr[0] <= 270 && ypr[0] >= 90) {
        servoAng = map(ypr[0], 90, 270, 600, 2500);
        //pwm.writeMicroseconds(0, servoAng);
        MoveServo(a, servoAng, 0);
        a = servoAng;
      }
      //Serial.print(interval); Serial.print(" "); Serial.print(zComp); Serial.print(" ");
      if (ypr[1] <= 270 && ypr[1] >= 90) {
        servoAng1 = map(ypr[1], 90, 270, 2500, 600);

        //pwm.writeMicroseconds(1, servoAng1);
        MoveServo(a1, servoAng1, 1);
        a1 = servoAng1;
      }
      if (ypr[2] <= 270 && ypr[2] >= 90) {
        servoAng2 = map(ypr[2], 90, 270, 600, 2500);
        //pwm.writeMicroseconds(2, servoAng2);
        MoveServo(a2, servoAng2, 2);
        a2 = servoAng2;
      }
      //Serial.print(servoAng);Serial.print(" ");Serial.print(servoAng1);Serial.print(" ");Serial.println(servoAng2);
    }

    /*unsigned long currentMillis = millis(); //каждые interval секунд компенсируем отклонение по оси Z
      //проверяем не прошел ли нужный интервал, если прошел то
      if (currentMillis - previousMillis > interval*0.8) {
      // сохраняем время последнего переключения
      previousMillis = currentMillis;
      zComp = 3; //прибавляем отклонение
      }*/
  }
}

int pulseWidth(int angle)  //угол поворота серво
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
