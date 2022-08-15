#include <SPI.h>                        // Подключаем библиотеку SPI
#include <nRF24L01.h>                   // Подключаем библиотеку nRF24L01 
#include <RF24.h>                       // Подключаем библиотеку RF24 
 
RF24 radio(9,10);                       // Указываем номера выводов nRF24L01+ (CE, CSN)
 
const byte address[6] = "00001";  
 
void setup()
{
  radio.begin();                        // Инициируем работу nRF24L01+
  radio.openWritingPipe(address);
  radio.stopListening();
}
void loop()
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
