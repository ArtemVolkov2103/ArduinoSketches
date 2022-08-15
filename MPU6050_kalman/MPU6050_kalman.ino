#include <Wire.h>

const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

// переменные для Калмана
float varVolt = 50.9; // среднее отклонение (ищем в excel)
float varProcess = 5.9; // скорость реакции на изменение (подбирается вручную)
float Pc = 0.0, G = 0.0, P = 1.0, Xp = 0.0, Zp = 0.0, Xe = 0.0;
// переменные для Калмана

// Функция фильтрации
float filter(float val) {
Pc = P + varProcess;
G = Pc / (Pc + varVolt);
P = (1 - G) * Pc;
Xp = Xe;
Zp = Xp;
Xe = G * (val - Zp) + Xp; // "фильтрованное" значение
return (Xe);
}

void setup() {
Serial.begin(115200);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B); // PWR_MGMT_1 register
Wire.write(0); // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
}

void loop() {
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr, 6, true); // request a total of 14 registers
AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

Serial.print(AcZ); Serial.print(" "); Serial.println((int)filter(AcZ));
delay(100);
}
