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
int Speed;
int P=314/100;
long interval = 100;
long previousMillis = 0;

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
  } 
  if (SensorState == LOW && flag == 1) {
    digitalWrite(ledPin, LOW);
    flag=0;
  }

  
  unsigned long currentMillis = millis();
  //проверяем, не прошел ли нужный интервал, если прошел, то:
  if(currentMillis - previousMillis > interval) {
    // сохраняем время последнего переключения
    previousMillis = currentMillis; 
    
    Speed = (newRotations-oldRotations)*2;

  oldRotations=newRotations;
   }
  
  
  lcd.setCursor(0,0);// столбец,строка
  lcd.print(newRotations);
  lcd.setCursor(2,2);// столбец,строка
  lcd.print(Speed);
  lcd.setCursor(4,2);// столбец,строка
  lcd.print("m/s");
  lcd.setCursor(17,0);// столбец,строка 
  lcd.print(millis()/1000/60);  
  lcd.setCursor(15,1);// столбец,строка 
  lcd.print(Probeg);
  delay(50);
}
