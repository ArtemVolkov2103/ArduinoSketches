#include <SoftwareSerial.h> // Подключаем библиотеку для работы 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов
#include <AFMotor.h> // Подключаем библиотеку для управления двигателям

int val;
int IN1 = 32;
int IN2 = 31;
int ENA = 5;

int IN3 = 43;
int IN4 = 44;
int ENB = 6;

const int TX_BT = 51;
const int RX_BT = 50;
SoftwareSerial BTSerial(51, 50); // RX, TX


// Создаем переменную для команд Bluetooth 
char vcmd; 

void setup()
{
    // Устанавливаем скорость передачи данных по Bluetooth 
  BTSerial.begin(9600); 
  // Устанавливаем скорость передачи данных по кабелю 
  Serial.begin(9600); 
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void loop()
{
// Если есть данные 
if (BTSerial.available()) 
{ 
// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)BTSerial.read(); 
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial.println(vcmd); 
 
 // Вперед 
if (vcmd == 'F') { // "F"- ВПЕРЕД , У НАС РУКА РАЗЖИМАЕТ
vFORWARD();
}
}

if (vcmd == 'B') { //"U"- ЗАХВАТ
vBACK();
}
 
   // Стоп 
if (vcmd == 'S') 
{ 
  vSTOP(); 
}
} 
void vFORWARD() {
   
  analogWrite  (ENA, 200);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  
  analogWrite  (ENB, 200);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); 
   }
 void vBACK() {
  
  
  analogWrite  (ENA,200);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
 
  analogWrite  (ENB,200);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  

}

// Стоп 
void vSTOP(){ 
  analogWrite  (ENA,0);
  analogWrite  (ENB,0);
  }
