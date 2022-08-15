

#include <SoftwareSerial.h> // Подключаем библиотеку для работы 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов
#include <AFMotor.h> // Подключаем библиотеку для управления двигателям

int val;
int IN1 = 32;
int IN2 = 31;
int ENA = 5;

const int TX_BT = 51;
const int RX_BT = 50;
SoftwareSerial BTSerial(51, 50); // RX, TX


// Создаем переменную для команд Bluetooth 
char vcmd; 

void setup()
{
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

}
void loop()

{


analogWrite  (ENA, 100);
 
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  }
  
