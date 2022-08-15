#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
MPU6050 mpu(0x68);
MPU6050 mpu1(0x69);

uint8_t fifoBuffer[45];         // буфер
void setup() {
  Serial.begin(115200);
  Wire.begin();
  //Wire.setClock(1000000UL);   // разгоняем шину на максимум
  // инициализация DMP
  mpu.initialize();
  delay(3000);
  mpu.dmpInitialize();
  mpu.setDMPEnabled(true);
  delay(100);
  mpu1.initialize();
  delay(3000);
  mpu1.dmpInitialize();
  mpu1.setDMPEnabled(true);
}
void loop() {
  static uint32_t tmr;
  if (millis() - tmr >= 11) {  // таймер на 11 мс (на всякий случай)
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
      // переменные для расчёта (ypr можно вынести в глобал)
      Quaternion q;
      VectorFloat gravity;
      float ypr[3];
      float ypr1[3];

      // расчёты
      mpu.dmpGetQuaternion(&q, fifoBuffer);
      mpu.dmpGetGravity(&gravity, &q);
      mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
      mpu1.dmpGetQuaternion(&q, fifoBuffer);
      mpu1.dmpGetGravity(&gravity, &q);
      mpu1.dmpGetYawPitchRoll(ypr, &q, &gravity);
      // выводим результат в радианах (-3.14, 3.14)
      Serial.print(ypr1[0]*57); // вокруг оси Z
      Serial.print(',');
      Serial.print(ypr1[1]*57); // вокруг оси Y
      Serial.print(',');
      Serial.print(ypr1[2]*57); // вокруг оси X
      Serial.print(" | ");
      Serial.print(ypr[0]*57); // вокруг оси Z
      Serial.print(',');
      Serial.print(ypr[1]*57); // вокруг оси Y
      Serial.print(',');
      Serial.print(ypr[2]*57); // вокруг оси X
      Serial.println();
      // для градусов можно использовать degrees()
      tmr = millis();  // сброс таймера
    }
  }
}
