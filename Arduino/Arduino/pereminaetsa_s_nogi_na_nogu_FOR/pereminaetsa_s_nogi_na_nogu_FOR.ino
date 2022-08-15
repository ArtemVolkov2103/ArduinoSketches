#include <Wire.h>
#include <Multiservo.h>

Multiservo Lfoot; // Создаем объект для сервопривода,даем имя
Multiservo Rfoot;

void setup (void) {
  Wire.begin();
  Lfoot.attach(6);
  Rfoot.attach(1);
}

void loop (void){
  for (int pos = 0; pos <= 20; pos +=2 ) {// goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Lfoot.write(pos);
    delay(500);                       // waits 15ms for the servo to reach the position
  }

  for (int pos = 20; pos >= 0; pos -= 2) {// goes from 180 degrees to 0 degrees
    Lfoot.write(pos);    // tell servo to go to position in variable 'pos'
    delay(200);                       // waits 15ms for the servo to reach the position
  }
  {
  for (int pos = 0; pos <= 20; pos +=2 ) {// goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Rfoot.write(pos);
    delay(500);                       // waits 15ms for the servo to reach the position
  }

  for (int pos = 20; pos >= 0; pos -= 2) {// goes from 180 degrees to 0 degrees
    Rfoot.write(pos);    // tell servo to go to position in variable 'pos'
    delay(200);                       // waits 15ms for the servo to reach the position
  }
}}
