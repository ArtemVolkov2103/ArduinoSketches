#include <Wire.h> // подключение библиотеки для I2C 
#include <PID_v1.h>// подключение библиотеки для ПИД регулятора
#include "gyro_accel.h"// подключение библиотеки для гироскопа и акселирометра mpu 6050
// Постоянные для вычилсения угла наклона 
// *********************************************************************
#define dt 20                       // промежуток времени в милисикундах 
#define rad2degree 57.3              // переменная для перевода из радиан в градусы 
#define Filter_gain 0.95             // переменная для фильтра angle = angle_gyro*Filter_gain + angle_accel*(1-Filter_gain)
// *********************************************************************
//Глобальные переменные 
// *********************************************************************
unsigned long t=0; // Переменная времени 
float y=0,angle_x_gyro=0,angle_y_gyro=0,angle_z_gyro=0,angle_x_accel=0,angle_y_accel=0,angle_z_accel=0,angle_x=0,angle_y=0,angle_z=0;
// *********************************************************************
char PWM1[] = {11, 10}; //Номера пинов для ШИМ управления
char Umotor_1[] = {13, 12}; //Подключение первого двигателя
char Umotor_2[] = {7, 8}; //Подключение первого двигателя
//Переменные для ПИД регулятора
// *********************************************************************
double originalSetpoint = -0.6;//Требуемое значение стабилизации
double setpoint = originalSetpoint;
double movingAngleOffset = 0.1;
double input, output;
double Kp = 50;   //28.5//50 Это примеры моих значений 
double Kd = 0.5;    //0.9//0.5
double Ki = 420;    //250//420
//Вызов ПИД регулятора
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// Основной код 
// *********************************************************************
void setup(){
  for (char pin = 0; pin <= 2; pin++) pinMode(PWM1[pin], OUTPUT);
  for (char pin1 = 0; pin1 <= 2; pin1++) pinMode(Umotor_1[pin1], OUTPUT);
  for (char pin2 = 0; pin2 <= 2; pin2++) pinMode(Umotor_2[pin2], OUTPUT);
  Serial.begin(115200);//Общение с компьютером при 115200
  Wire.begin();// Налало работы с I2C шиной , в (адресс устройства  ), если не назван адресс , то плата подключается к шина  как  мастер  
  MPU6050_ResetWake();// Сбрасывает настройки по умолчанию 
  MPU6050_SetGains(0,1);// Настраивает максимальные значения шкалы измерений гироскопа и акселерометра 
  MPU6050_SetDLPF(0); //Настройка фильтра низких частот 
  MPU6050_OffsetCal();// Каллебровка гироскопа и акселерометра 
  MPU6050_SetDLPF(6); // Настройка фильтра низких частот
  Serial.print("\tangle_y_accel");
  Serial.print("\tangle_y");
  Serial.println("\tLoad");
  t=millis(); 
  pid.SetMode(AUTOMATIC);
  pid.SetSampleTime(10);
  pid.SetOutputLimits(-255, 255); 
}
void loop(){
  t=millis(); 
  MPU6050_ReadData();
 // Угловая скорость относительно всех осей 
  angle_y_gyro = (gyro_y_scalled*((float)dt/1000)+angle_y);
  //Угол поворота относительно всех осей 
  angle_y_accel = -atan(accel_x_scalled/(sqrt(accel_y_scalled*accel_y_scalled+accel_z_scalled*accel_z_scalled)))*(float)rad2degree;
  // Отфильтрованные значения угла поворота относительно всех осей 
  angle_y = Filter_gain*angle_y_gyro+(1-Filter_gain)*angle_y_accel;
  Serial.print(angle_y);
  Serial.println("\t");
 //Вывод оси времени 
  //Serial.println(((float)(millis()-t)/(float)dt)*100);
  while((millis()-t) < dt){ // Making sure the cycle time is equat to dt
  // Do nothing
  }
  input=angle_y;//Угол наклона относительно оси OY является входным параметром для ПИД регулятора
  pid.Compute();
     int PWM=output;//Выходной сигнал ШИМ передаем на двигатели 
     Serial.print(PWM);
     Serial.print(" ");
     MOTOR1(PWM);
     MOTOR2(PWM);
}

//Функция для управления первым мотором
// *********************************************************************
void MOTOR1(int PWM_1)
{if (PWM_1>0)
    {digitalWrite(Umotor_1[0], HIGH);
    digitalWrite(Umotor_1[1], LOW);
    analogWrite(PWM1[0], PWM_1);}
    else{
    digitalWrite(Umotor_1[0], LOW);
    digitalWrite(Umotor_1[1], HIGH);
    analogWrite(PWM1[0], abs(PWM_1));
  }
   }
//Функция для управления вторым мотором
// *********************************************************************
void MOTOR2(int PWM_2)
{if (PWM_2>0)
    {digitalWrite(Umotor_2[0], LOW);
    digitalWrite(Umotor_2[1], HIGH);
    analogWrite(PWM1[1], PWM_2);}
    else{
    digitalWrite(Umotor_2[0], HIGH);
    digitalWrite(Umotor_2[1], LOW);
    analogWrite(PWM1[1], abs(PWM_2));
  }
   }   
