 #include <Servo.h>
 #include "Wire.h"
 #include "I2Cdev.h"
 #include "MPU6050.h"

 MPU6050 accelgyro;

Servo Yservo;
Servo Xservo;
 
 int16_t ax, ay, az;
 int16_t gx, gy, gz;
 void setup() {
 
 Wire.begin();
 accelgyro.initialize();
 
 delay(100);   //замедление
 }
 
 void loop() {
 //Получение значений акселерометра и гироскопа сразу
 accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);       

ax=map(ax,-170,170,0,180);
  Xservo.write(ax);
  
ay=map(ay,-170,170,0,180);
  Yservo.write(ay);
  
 }
