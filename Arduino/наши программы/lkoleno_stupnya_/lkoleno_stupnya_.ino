#include <Wire.h>
#include <Multiservo.h>

Multiservo Lbedro; // Создаем объект для сервопривода,даем имя
Multiservo Lkoleno;
Multiservo Lstupnya;
void setup (void) {
  Wire.begin();
  Lbedro.attach(10);
  Lkoleno.attach(8);
  Lstupnya.attach(6);
  Rbedro.attach(5);
  Rkoleno.attach(3);
  Rstupnya.attach(1);
}
void loop (void)
{
  Lbedro.write(70);
  Lkoleno.write(70);
  Lstupnya.write(0);
  delay (700);
  Lbedro.write(60);
  Lkoleno.write(80);
  Lstupnya.write(0);
  delay (700);
  Lbedro.write(50);
  Lkoleno.write(90);
  Lstupnya.write(0);
  delay (700);
  Lbedro.write(45);
  Lkoleno.write(100);
  Lstupnya.write(0);
  delay (700);
  Lbedro.write(55);
  Lkoleno.write(75);
  Lstupnya.write(0);
    delay (700);
  Lbedro.write(68);
  Lkoleno.write(75);
  Lstupnya.write(5);
  delay (700);
  Lbedro.write(75);
  Lkoleno.write(65);
  Lstupnya.write(10);
  delay (700);
}
