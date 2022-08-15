#include "I2Cdev.h"я
#include "MPU6050_6Axis_MotionApps20.h"
MPU6050 mpu(0x68); //AD0 К GND
MPU6050 mpu1(0x69);//AD0 К VCC

uint8_t fifoBuffer[45];         // буфер
uint8_t fifoBuffer1[45];

void calibration() {
  long offsets[6];
  long offsetsOld[6];
  int16_t mpuGet[6];
  // используем стандартную точность
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  // обнуляем оффсеты
  mpu.setXAccelOffset(0);
  mpu.setYAccelOffset(0);
  mpu.setZAccelOffset(0);
  mpu.setXGyroOffset(0);
  mpu.setYGyroOffset(0);
  mpu.setZGyroOffset(0);
  delay(10);
  for (byte n = 0; n < 10; n++) {   // 10 итераций калибровки
    for (byte j = 0; j < 6; j++) {  // обнуляем калибровочный массив
      offsets[j] = 0;
    }
    for (byte i = 0; i < 100 + 3; i++) {
      // делаем BUFFER_SIZE измерений для усреднения
      mpu.getMotion6(&mpuGet[0], &mpuGet[1], &mpuGet[2], &mpuGet[3], &mpuGet[4], &mpuGet[5]);
      // пропускаем первые 99 измерений
      if (i >= 99) {
        for (byte j = 0; j < 6; j++) {
          offsets[j] += (long)mpuGet[j];  // записываем в калибровочный массив
        }
      }
    }
    for (byte i = 0; i < 6; i++) {
      offsets[i] = offsetsOld[i] - ((long)offsets[i] / 3);  // учитываем предыдущую калибровку
      if (i == 2) offsets[i] += 16384;                      // если ось Z, калибруем в 16384
      offsetsOld[i] = offsets[i];
    }
    // ставим новые оффсеты
    mpu.setXAccelOffset(offsets[0] / 8);
    mpu.setYAccelOffset(offsets[1] / 8);
    mpu.setZAccelOffset(offsets[2] / 8);
    mpu.setXGyroOffset(offsets[3] / 4);
    mpu.setYGyroOffset(offsets[4] / 4);
    mpu.setZGyroOffset(offsets[5] / 4);
    delay(2);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(1000000UL);   // разгоняем шину на максимум
  // инициализация DMP
  mpu.initialize();
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(1000);
  mpu.dmpInitialize();
  mpu.setDMPEnabled(true);
  delay(100);
  mpu1.initialize();
  mpu1.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
  mpu1.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(1000);
  mpu1.dmpInitialize();
  mpu1.setDMPEnabled(true);
}


void loop() {
  static uint32_t tmr;
  if (millis() - tmr >= 11) {  // таймер на 11 мс (на всякий случай)
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer) && mpu1.dmpGetCurrentFIFOPacket(fifoBuffer1)) {
      // переменные для расчёта (ypr можно вынести в глобал)
      Quaternion q;
      VectorFloat gravity;
      Quaternion q1;
      VectorFloat gravity1;
      float ypr[3];
      float ypr1[3];

      // расчёты
      mpu.dmpGetQuaternion(&q, fifoBuffer);
      mpu.dmpGetGravity(&gravity, &q);
      mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

      mpu1.dmpGetQuaternion(&q1, fifoBuffer1);
      mpu1.dmpGetGravity(&gravity1, &q1);
      mpu1.dmpGetYawPitchRoll(ypr1, &q1, &gravity1);
      // выводим результат в радианах (-3.14, 3.14)
      Serial.print(map(ypr[0] * 57, -180, 180, 0, 360)); // вокруг оси Z
      Serial.print(',');
      Serial.print(map(ypr[1] * 57, -180, 180, 0, 360)); // вокруг оси Y
      Serial.print(',');
      Serial.print(map(ypr[2] * 57, -180, 180, 0, 360)); // вокруг оси X
      Serial.print(" | ");
      Serial.print(map(ypr1[0] * 57, -180, 180, 0, 360)); // вокруг оси Z
      Serial.print(',');
      Serial.print(map(ypr1[1] * 57, -180, 180, 0, 360)); // вокруг оси Y
      Serial.print(',');
      Serial.print(map(ypr1[2] * 57, -180, 180, 0, 360)); // вокруг оси X
      Serial.println();
      // для градусов можно использовать degrees()
      tmr = millis();  // сброс таймера
    }
  }
}
