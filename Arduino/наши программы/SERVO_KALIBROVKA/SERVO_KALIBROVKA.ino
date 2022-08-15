#include <Multiservo.h>
#include <Wire.h>

Multiservo wservo; // Создаем объект для сервопривода,даем имя

void setup(void) {
      Wire.begin();
  wservo.attach(17);
  wservo.write(0);
 delay(2000);
}

void loop(void) { delay(10000);

  wservo.write(73);
 delay(2000);

}
