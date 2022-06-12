#include "Wire.h"
#include "HMC5883L.h"

HMC5883L compass;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  
  compass = HMC5883L();  // создаем экземпляр HMC5883L библиотеки
  setupHMC5883L();       // инициализация HMC5883L
}

void loop(){
  float heading = getHeading();
  Serial.println(heading);
  delay(250);
}

void setupHMC5883L(){
  // инициализация HMC5883L, и проверка наличия ошибок
  int error;  
  error = compass.SetScale(0.88); // чувствительность датчика из диапазона: 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1
  if(error != 0) Serial.println(compass.GetErrorText(error)); // если ошибка, то выводим ее

  error = compass.SetMeasurementMode(Measurement_Continuous); // установка режима измерений как Continuous (продолжительный)
  if(error != 0) Serial.println(compass.GetErrorText(error)); // если ошибка, то выводим ее
}

float getHeading(){
  // считываем данные с HMC5883L и рассчитываем  направление
  MagnetometerScaled scaled = compass.ReadScaledAxis(); // получаем масштабированные элементы с датчика
  float heading = atan2(scaled.YAxis, scaled.XAxis);    // высчитываем направление

  // корректируем значения с учетом знаков
  if(heading < 0) heading += 2*PI;
  if(heading > 2*PI) heading -= 2*PI;

  return heading * RAD_TO_DEG; // переводим радианы в градусы
}
