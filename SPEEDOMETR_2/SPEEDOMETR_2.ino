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
float maxSpeed;
int P=314/100;
long interval = 100;
float previousMillis = 0;
int a;


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
   float currentMillis = millis();
     
   a = currentMillis - previousMillis;
   Speed = 3.6 * 2000  / a;
    previousMillis = currentMillis;
     if(Speed >= maxSpeed){
    maxSpeed = Speed;
    }
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
  lcd.print("km/h");
  //lcd.setCursor(17,0);// столбец,строка 
  //lcd.print(millis()/1000/60);  
  lcd.setCursor(15,1);// столбец,строка 
  lcd.print(Probeg);
  lcd.setCursor(2,3);// столбец,строка
  lcd.print(maxSpeed);
  lcd.setCursor(6,3);// столбец,строка
  lcd.print("km/h");
  lcd.setCursor(8,0);// столбец,строка
  lcd.print(a);
  delay(20);
}
