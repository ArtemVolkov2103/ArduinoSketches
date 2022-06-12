#include <SoftwareSerial.h>
int pin = 3;
volatile int state = LOW;
int encoder = 43;
 
void setup()
{
  pinMode(pin, INPUT);
  attachInterrupt(1, blink, CHANGE   );//FALLING
Serial.begin(9600);
}
 
void loop()
{
  digitalRead(pin);
 // Serial.println(pin);
  Serial.println(encoder);
 // delay(1000);
}
 
void blink()
{
 // state = !state;
  encoder = encoder+1;
}

