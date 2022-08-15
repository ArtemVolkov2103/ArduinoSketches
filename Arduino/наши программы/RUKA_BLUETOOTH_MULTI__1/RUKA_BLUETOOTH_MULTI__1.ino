#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов 
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

// Создаем объект для сервопривода 
Servo Pservo;
Servo Lservo;
Servo Zservo;
SoftwareSerial BTSerial(50,51); // RX, TX

int P=1300;
int LO=1300;
int Z=600;

int Del=100;
//int UGOLP// Создаем переменные для запоминания УГЛОВ ПОВОРОТА СЕРВ
//int UGOLL
//int UGOLZ

// Создаем переменную для команд Bluetooth 
char vcmd; 

void setup() { 
  // Устанавливаем скорость передачи данных по Bluetooth 
  BTSerial.begin(9600); 
  // Устанавливаем скорость передачи данных по кабелю 
  Serial1.begin(9600); 
    // Выбираем пин к которому подключен сервопривод 
  Pservo.attach(2,560,2300);
  Lservo.attach(5,1000,2000);//1520 СРЕДНЕЕ
  Zservo.attach(7,600,950);
   // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
   Pservo.writeMicroseconds(1300);  
   Lservo.writeMicroseconds(1300);  
   Zservo.writeMicroseconds(600);  
   // Пауза 5 секунд 
delay(5000);    
}

void loop() { 
// Если есть данные 
if (BTSerial.available()) 
{ 
// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)BTSerial.read(); 
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial1.println(vcmd);

// Вперед 
if (vcmd == 'F') { 
Pservo.writeMicroseconds(P=P+1);
delay(Del);
} 
// Назад 
if (vcmd == 'B') 
{ 
Pservo.writeMicroseconds(P=P-1);
delay(Del);
} 
// Влево 
if (vcmd == 'L') 
{ 
Lservo.writeMicroseconds(LO=LO+1);
delay(Del);
} 
// Вправо 
if (vcmd == 'R') 
{ 
Lservo.writeMicroseconds(LO=LO-1);  
delay(Del);
} 
// Стоп 
if (vcmd == 'S') 
{ 
Pservo.writeMicroseconds(P);
Lservo.writeMicroseconds(LO);
Zservo.writeMicroseconds(Z);
delay(Del);
} 
// ЗАХВАТ ВЗЯТЬ 
if (vcmd == 'W') 
{ 
 Zservo.writeMicroseconds(Z=Z+1); 
delay(Del);
} 
// ЗАХВАТ БРОСИТЬ 
if (vcmd == 'w') 
{ 
Zservo.writeMicroseconds(Z=Z-1); 
delay(Del);
}  
} 

}
