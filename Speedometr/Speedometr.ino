#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 20, 4);

const int MagnetSensorPin = 2;// пин датчика холла
const int ledPin =  13;

int SensorState = 0;//положение датчика    
int flag;
int newRotations;//обороты
int oldRotations;//обороты
int Probeg;
int D = 61;  //диаметр
float Speed;
int P=314/100;
long interval = 100;
long previousMillis = 0;
//unsigned long currentMillis;

void setup() {
  lcd.init(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея
  pinMode(ledPin, OUTPUT);
  pinMode(MagnetSensorPin, INPUT);
}


void loop() {
  
  lcd.clear();
  Probeg = newRotations * 2;

  SensorState = digitalRead(MagnetSensorPin);
  
  if (SensorState == HIGH && flag == 0) {
    digitalWrite(ledPin, HIGH);
    flag=1; //ДАЕТ ОТСЕЧКУ СРАБАТЫВАНИЙ
    newRotations++; //СЧЕТЧИК СРАБАТЫВАНИЙ - ПРИ СМЕНЕ С LOW НА HIGH
  unsigned long currentMillis = millis();
     
   int a = currentMillis - previousMillis;
   Speed = 2000  / a;
    previousMillis = currentMillis;
  } 
  
  if (SensorState == LOW && flag == 1) {
    digitalWrite(ledPin, LOW);
    flag=0;
  }
  
  
  lcd.setCursor(0,0);// столбец,строка
  lcd.print(newRotations);
  lcd.setCursor(2,2);// столбец,строка
  lcd.print(Speed);
  lcd.setCursor(6,2);// столбец,строка
  lcd.print("M/s");
  lcd.setCursor(17,0);// столбец,строка 
  lcd.print(millis()/1000/60);  
  lcd.setCursor(15,1);// столбец,строка 
  lcd.print(Probeg);
  delay(50);
}
