#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Wire.h>
#include <Multiservo.h>
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

// Создаем объект для сервопривода 
Multiservo Pservo;
Multiservo Lservo;
Multiservo Zservo;
SoftwareSerial BTSerial(50,51); // RX, TX

// Создаем переменную для команд Bluetooth 
char vcmd; 
int vspd = 60;
int LO=70;

void setup (void) {
  Wire.begin();//Иициализация порта I2C
  // Устанавливаем скорость передачи данных по Bluetooth 
  BTSerial.begin(9600); 
  // Устанавливаем скорость передачи данных по кабелю 
  Serial1.begin(9600); 
    // Выбираем пин к которо;//1520 СРЕДНЕЕ
  Pservo.attach(12);
  Lservo.attach(15);
  Zservo.attach(17);
  Pservo.write(60); 
  Lservo.write(73); 
  Zservo.write(40); 
    

}

void loop (void){
// Если есть данные 
if (BTSerial.available()) 
 
// Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
vcmd = (char)BTSerial.read(); 
{
// Отправляем команду в порт, чтобы можно было их проверить в «Мониторе порта» 
Serial1.println(vcmd);

// Вперед 
if (vcmd == 'F') { 
vforward(); 
} 
// Назад 
if (vcmd == 'B') 
{ 
vbackward(); 
} 
// Влево 
if (vcmd == 'L') 
{ 
vleft(); 
} 
// Вправо 
if (vcmd == 'R') 
{ 
vright(); 
} 
// Скорость 0% 
if (vcmd == '0') 
{ 
Zservo.write(10); 
} 
// Скорость 10% 
if (vcmd == '1') 
{ 
Zservo.write(15); 
} 
// Скорость 20% 
if (vcmd == '2') 
{ 
Zservo.write(20); 
} 
// Скорость 30% 
if (vcmd == '3') 
{ 
Zservo.write(25); 
} 
// Скорость 40% 
if (vcmd == '4') 
{ 
Zservo.write(30); 
} 
// Скорость 50% 
if (vcmd == '5') 
{ 
Zservo.write(35); 
} 
// Скорость 60% 
if (vcmd == '6') 
{ 
Zservo.write(40); 
} 
// Скорость 70% 
if (vcmd == '7') 
{ 
Zservo.write(45); 
} 
// Скорость 80% 
if (vcmd == '8') 
{ 
Zservo.write(50); 
} 
// Скорость 90% 
if (vcmd == '9') 
{ 
Zservo.write(55); 
} 
// Скорость 100% 
if (vcmd == 'q') 
{ 
Zservo.write(60); 
} 
}
}

//  
void vforward() {  
 Pservo.write(30); 
} 
// 
void vbackward() { 
Pservo.write(60); 
} 
//ЛОКОТЬ ВЛЕВО
void vleft() {
 for ( LO = 40; LO < 50; LO = LO+1 );{
Lservo.write(LO);
delay(10);

}
}
//ЛОКОТЬ ВПРАВО
void vright() {
 for ( LO = 50; LO > 40; LO = LO-1 );{
Lservo.write(LO);
delay(10);}
}
