#include <Wire.h>
#include <Multiservo.h>
 
Multiservo servo;
 
void setup(void)
{
  servo.attach(17);
}
 
void loop(void)
{
  servo.write(90);
 
  delay(1000);
}
