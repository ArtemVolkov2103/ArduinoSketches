#include <Wire.h>
#include <Multiservo.h>

Multiservo Lhip; // Создаем объект для сервопривода,даем имя
Multiservo Rhip;

void setup (void) {
  Wire.begin();
  Lhip.attach(11);
}

void loop (void){
  for (int pos = 70; pos <= 50; pos +=1 )
  {
    Lhip.write(pos);
    delay(200);                       // waits 15ms for the servo to reach the position
  }
   {
  for (int pos = 50; pos >= 70; pos -= 1) {// goes from 180 degrees to 0 degrees
    Lhip.write(pos);    // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
}}
