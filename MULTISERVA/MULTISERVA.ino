#include <Wire.h>
#include <Multiservo.h>

#define MULTISERVO_PIN 17
 
Multiservo myservo;

int pos = 0;

void setup(void) {
  Wire.begin();
  myservo.attach(MULTISERVO_PIN);
}
 
void loop(void) {
  for (pos = 0; pos <= 170; pos += 1) {// goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 170; pos >= 0; pos -= 1) {// goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
/* attach() — присоединяет переменную к конкретному пину. Возможны два варианта синтаксиса для этой функции: servo.attach(pin) и servo.attach(pin, min, max). При этом pin — номер пина, к которому присоединяют сервопривод, min и max — длины импульсов в микросекундах, отвечающих за углы поворота 0° и 180°. По умолчанию выставляются равными 544 мкс и 2400 мкс соответственно.
write() — отдаёт команду сервоприводу принять некоторое значение параметра. Синтаксис следующий: servo.write(angle), где angle — угол, на который должен повернуться сервопривод.
writeMicroseconds() — отдаёт команду послать на сервоприводимульс определённой длины, является низкоуровневым аналогом предыдущей команды. Синтаксис следующий: servo.writeMicroseconds(uS), где uS — длина импульса в микросекундах.
read() — читает текущее значение угла, в котором находится сервопривод. Синтаксис следующий: servo.read(), возвращается целое значение от 0 до 180.
attached() — проверка, была ли присоединена переменная к конкретному пину. Синтаксис следующий: servo.attached(), возвращается логическая истина, если переменная была присоединена к какому-либо пину, или ложь в обратном случае.
detach() — производит действие, обратное действию attach(), то есть отсоединяет переменную от пина, к которому она была приписана. Синтаксис следующий: servo.detach().
*/
