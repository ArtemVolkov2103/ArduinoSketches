#include <VarSpeedServo.h>
VarSpeedServo myServo;           
 void setup()
{
 myServo.attach (7);
 

}
void loop()
{
  myServo.slowmove (10, 10);  // положение , скорость ВНИМАНИЕ: delay(5000) ОБЯЗАТЕЛЬНА.
 // ЕСЛИ УДАЛИТЬ - РАБОТАТЬ НЕ БУДЕТ. ЕСЛИ ПОМЕНЯТЬ ВРЕМЯ РАБОТАЕТ НЕПРАВИЛЬНО.
 delay(2000);
 
  myServo.slowmove (60, 10);  // положение , скорость 
  delay(2000);

}

