#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты
#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов
int val;
int IN1 = 4;
int IN2 = 2;
int EN1 = 3;
int EN2 = 5;
int LED = 13;

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — левый 

const int TX_BT = 51;
const int RX_BT = 50;
SoftwareSerial BTSerial(51, 50); // RX, TX
// Создаем объект для сервопривода 
Servo vservo;

// Создаем переменную для команд Bluetooth 
char vcmd; 
// Создаем переменные для запоминания скорости двигателей 
int vspdL, vspdR; 
/* Создаем переменную, на значение которой будет уменьшаться скорость при плавных поворотах. 
Текущая скорость должна быть больше этого значения. В противном случае двигатели со стороны направления поворота просто не будут вращаться */ 
int vspd = 200;

 void setup() {
 BTSerial.begin(9600); //открывает последовательный порт, устанавливает скорость 9600 бит/c
   // Выбираем пин к которому подключен сервопривод 
  vservo.attach(9); // или 10, если воткнули в крайний разъём 
  // Поворачиваем сервопривод в положение 90 градусов при каждом включении 
  vservo.write(90); 

 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

}
  
void loop() { 
  motor1.setSpeed(250);
   
// Если есть данные 
if (BTSerial.available()) 
{ 
// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)BTSerial.read(); 
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial.println(vcmd);

// Вперед 
if (vcmd == 'F') { 
    // Выводы конфигурируются согласно раьоте Motor Shield'а
      // Моторы крутятся вперед
      digitalWrite(EN1, 155);
      digitalWrite(EN2, 155);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
    }
    // Назад 
if (vcmd == 'B') 
{   digitalWrite(EN1, 155);
      digitalWrite(EN1, 155);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
// Влево 
if (vcmd == 'L') 
{   digitalWrite(EN1, 200);
      digitalWrite(EN2, 200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
    // Вправо 
if (vcmd == 'R') 
{  digitalWrite(EN1, 200);
      digitalWrite(EN2, 200);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
     // ВВЕРХ 
 
if (vcmd == 'X') { 
vextra(); 
}
}
    // ВНИЗ
if (vcmd == 'V'){ 
vhorn(); 
 }
}
void vhorn() { 
motor1.run(BACKWARD); 
delay(500);
 motor1.run(RELEASE); 
}
void vextra() { 
motor1.run(FORWARD); 
delay(500);
 motor1.run(RELEASE); 
}

