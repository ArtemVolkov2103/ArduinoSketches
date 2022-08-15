
#include <SPI.h>                      // Подключаем библиотеку SPI
#include <nRF24L01.h>                 // Подключаем библиотеку nRF24L01 
#include <RF24.h>                     // Подключаем библиотеку 
 
RF24 radio(9,10);                     // Указываем номера выводов nRF24L01+ (CE, CSN)
 
const byte address[6] = "00001";
 
void setup()
{
  while (!Serial);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening  ();
}
 
void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
