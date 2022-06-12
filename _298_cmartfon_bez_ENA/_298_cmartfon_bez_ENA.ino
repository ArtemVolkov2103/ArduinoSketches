#include <SoftwareSerial.h> // Подключаем библиотеку для работы 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов
#include <AFMotor.h> // Подключаем библиотеку для управления двигателям

int val;
int IN1 = 32;
int IN2 = 31;


int IN3 = 43;
int IN4 = 44;


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
 

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 
}
void loop()
{
// Если есть данные 
if (BTSerial.available()) 

// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)BTSerial.read(); 
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial.println(vcmd); 
 
 // Вперед 
if (vcmd == 'F') { // "F"- ВПЕРЕД , У НАС РУКА РАЗЖИМАЕТ
vFORWARD();
}


if (vcmd == 'B') { //"U"- ЗАХВАТ
vBACK();
}
 
   // Стоп 
  if (vcmd == 'S') 
  { 
  vSTOP(); 
  }
  if (vcmd == 'L') 
  {
  vLEFT();
  }
  if (vcmd == 'R')
  {
  vRIGHT();
  }
  } 
void vFORWARD() {
   
  
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  

  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); 
   }
 void vBACK() {
  
  

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
 

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);

}

void vLEFT() {
   

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW); 
   }
   
   void vRIGHT() {
   
  
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  

  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); 
   }
// Стоп 
void vSTOP(){ 
   
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW); 
  

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);

  }
