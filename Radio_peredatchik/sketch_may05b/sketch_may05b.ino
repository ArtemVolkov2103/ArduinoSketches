
#include <SPI.h>  // Подключаем библиотеку для работы с SPI-интерфейсом

#include <nRF24L01.h> // Подключаем файл конфигурации из библиотеки RF24

#include <RF24.h> // Подключаем библиотеку для работа для работы с модулем NRF24L01

#define PIN_POT A7  // Номер пина Arduino, к которому подключен потенциометр

#define PIN_CE  10  // Номер пина Arduino, к которому подключен вывод CE радиомодуля

#define PIN_CSN 9 // Номер пина Arduino, к которому подключен вывод CSN радиомодуля

RF24 radio(PIN_CE, PIN_CSN); // Создаём объект radio с указанием выводов CE и CSN
#define PIN_LED 7
 

int potValue[1]; // Создаём массив для передачи значений потенциометра
int one=1;
 int two=2;
 int timer;

void setup() {
pinMode(PIN_LED, OUTPUT); // Настраиваем на выход пин светодиода
  radio.begin();  // Инициализация модуля NRF24L01

  radio.setChannel(5); // Обмен данными будет вестись на пятом канале (2,405 ГГц)

  radio.setDataRate (RF24_1MBPS); // Скорость обмена данными 1 Мбит/сек

  radio.setPALevel(RF24_PA_HIGH); // Выбираем высокую мощность передатчика (-6dBm)

  radio.openWritingPipe(0x7878787878LL); // Открываем трубу с уникальным ID

}

 

void loop() {

  //potValue[0] = analogRead(PIN_POT); // Считываем показания потенциометра
timer=millis();
  radio.write( timer, 1); // Отправляем считанные показания по радиоканалу
  digitalWrite(PIN_LED, HIGH);
  delay(100);
  radio.write( timer, 1);
  digitalWrite(PIN_LED, LOW);//analogWrite
  delay(100);
}
