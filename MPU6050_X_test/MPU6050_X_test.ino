// подключение библиотек
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  // инициализация
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  delay(100);
}


void loop()
{
  // чтение значений гироскопа и акселерометра
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // вывод значений в монитор
  Serial.print("a/g:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);
  delay(50);
}
