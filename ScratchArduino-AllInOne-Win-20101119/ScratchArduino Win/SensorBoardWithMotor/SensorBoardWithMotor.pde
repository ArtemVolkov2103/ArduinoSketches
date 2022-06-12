/* 
 ScratchBoard compatible program with WeDo simulator
 
 Created 30 Sept. 2009
 by Koji Yokokawa (http://www.yengawa.com)
 
 Modified 11 Jan. 2010
 by Kazuhiro Abe (http://d.hatena.ne.jp/abee2/)
 */

// digital input pin
#define BUTTON 2

// analog input pin
#define SLIDER 0
#define LIGHT  1
#define SOUND  2
#define R_A 3
#define R_B 4
#define R_C 5
#define R_D 5 // Arduino Diecimila has 6 analog inputs

#define FIRMWAEW_ID 4  // ScratchBoard 1.1 Firmware ID

#define LED_PIN 13  // response lamp (digital pin 13 is on board LED)

#define PWM_PIN 11
#define THISWAY_PIN 4
#define THATWAY_PIN 7

const byte req_scratchboard = 0;  // request messge from Scratch
const byte mask_scratcharduino = 240;  // request mask of Scratch+Ardunio
const byte ch_r_D = 0;
const byte ch_r_C = 1;
const byte ch_r_B = 2;
const byte ch_button = 3;
const byte ch_r_A = 4;
const byte ch_light = 5;
const byte ch_sound = 6;
const byte ch_slider = 7;
const byte ch_firmware = 15;

int sensorValue = 0;  // sensor value to send

byte inByte = 0;  // incoming serial byte

byte motorDirection = 0;
byte isMotorOn = 0;
byte motorPower = 0;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(38400);
  pinMode(BUTTON, INPUT);   // digital sensor is on digital pin 2
  digitalWrite(BUTTON, HIGH);

  // initialize the digital pin as an output:
  pinMode(LED_PIN, OUTPUT);     
  //digitalWrite(LED_PIN, HIGH);   // set the LED on
  
  pinMode(PWM_PIN, OUTPUT);     
  pinMode(THISWAY_PIN, OUTPUT);     
  pinMode(THATWAY_PIN, OUTPUT);     
}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    Serial.flush();
    if (inByte >= req_scratchboard) {
      digitalWrite(LED_PIN, HIGH);   // set the LED on
      
      motorPower = (inByte & B111111) * 4;
      motorDirection = (inByte >> 6) & B1;
      isMotorOn = inByte >> 7;
      analogWrite(PWM_PIN, motorPower);
      digitalWrite(THISWAY_PIN, motorDirection & isMotorOn);
      digitalWrite(THATWAY_PIN, ~motorDirection & isMotorOn);

      sendValue(ch_firmware, FIRMWAEW_ID);
      delay(10);

      // analog read range from 0 to 1023
      // delay 10ms to let the ADC recover:

      sensorValue = analogRead(R_D);
      sendValue(ch_r_D, sensorValue);
      delay(10);

      sensorValue = analogRead(R_C);
      sendValue(ch_r_C, sensorValue);
      delay(10);

      sensorValue = analogRead(R_B);
      sendValue(ch_r_B, sensorValue);
      delay(10);

      // read  switch, map it to 0 or 1023L
      sensorValue = map(digitalRead(BUTTON), 0, 1, 0, 1023);  
      sendValue(ch_button, sensorValue);

      sensorValue = analogRead(R_A);
      sendValue(ch_r_A, sensorValue);
      delay(10);

      sensorValue = analogRead(LIGHT);
      sendValue(ch_light, sensorValue);
      delay(10);

      sensorValue = analogRead(SOUND);
      sendValue(ch_sound, sensorValue);
      delay(10);

      sensorValue = analogRead(SLIDER);
      sendValue(ch_slider, sensorValue);
      delay(10);

      digitalWrite(LED_PIN, LOW);    // set the LED off
    }
  }
}

void sendValue(byte channel, int value) {
  byte high = 0;  // high byte to send
  byte low = 0;  // low byte to send
  high = (1 << 7) | (channel << 3) | (value >> 7);
  low =  (0xff >> 1) & value;
  Serial.write(high);
  Serial.write(low);
}




