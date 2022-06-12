/*Скетч для управления роботом на Arduino по Bluetooth через смартфон на Android

В своём скетче я реализовал следующие функции:

Движение вперед
Движение назад
Разворот влево
Разворот вправо
Плавный поворот влево при движении вперед
Плавный поворот вправо при движении вперед
Плавный поворот влево при движении назад
Плавный поворот вправо при движении назад
Остановка
Установка скорости 0%
Установка скорости 10%
Установка скорости 20%
Установка скорости 30%
Установка скорости 40%
Установка скорости 50%
Установка скорости 60%
Установка скорости 70%
Установка скорости 80%
Установка скорости 90%
Установка скорости 100%
В скетче использовал функции, чтобы не дублировать код при схожих событиях.
*/


#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов  
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый 
AF_DCMotor motor3(3); //канал М3 на Motor Shield — передний левый 
AF_DCMotor motor4(4); //канал М4 на Motor Shield — передний правый

// Создаем объект для сервопривода 
Servo vservo;

SoftwareSerial BTSerial(50, 51); // RX, TX

// Создаем переменную для команд Bluetooth 
char vcmd; 
// Создаем переменные для запоминания скорости двигателей 
int vspdL, vspdR; 
/* Создаем переменную, на значение которой будет уменьшаться скорость при плавных поворотах. 
Текущая скорость должна быть больше этого значения.  В противном случае двигатели со стороны направления поворота просто не будут вращаться */ 
int vspd = 200;

void setup() { 
  // Устанавливаем скорость передачи данных по Bluetooth 
  BTSerial.begin(9600); 
  // Устанавливаем скорость передачи данных по кабелю 
  Serial.begin(9600); 
  // Выбираем пин к которому подключен сервопривод 
  vservo.attach(9); // или 10, если воткнули в крайний разъём 
  // Поворачиваем сервопривод в положение 90 градусов при каждом включении 
  vservo.write(90);  
  // Устанавливаем максимальную скорость вращения двигателей 
  vspeed(255,255); 
}

void loop() { 
  // Если есть данные 
  if (BTSerial.available()) 
  { 
    // Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
    vcmd = (char)BTSerial.read(); 
    // Отправляем команду в порт, чтобы можно было их проверить в "Мониторе порта" 
    Serial.println(vcmd);

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
    // Прямо и влево 
    if (vcmd == 'G') 
    { 
      vforwardleft(); 
    }  
    // Прямо и вправо 
    if (vcmd == 'I') 
    { 
      vforwardright(); 
    }  
    // Назад и влево 
    if (vcmd == 'H') 
    { 
      vbackwardleft(); 
    }  
    // Назад и вправо 
    if (vcmd == 'J') 
    { 
      vbackwardright(); 
    }  
    // Стоп 
    if (vcmd == 'S') 
    { 
      vrelease(); 
    } 
    // Скорость 0% 
    if (vcmd == '0') 
    { 
      vspeed(0,0); 
    } 
    // Скорость 10% 
    if (vcmd == '1') 
    { 
      vspeed(25,25); 
    } 
    // Скорость 20% 
    if (vcmd == '2') 
    { 
      vspeed(50,50); 
    } 
    // Скорость 30% 
    if (vcmd == '3') 
    { 
      vspeed(75,75); 
    } 
    // Скорость 40% 
    if (vcmd == '4') 
    { 
      vspeed(100,100); 
    } 
    // Скорость 50% 
    if (vcmd == '5') 
    { 
      vspeed(125,125); 
    } 
    // Скорость 60% 
    if (vcmd == '6') 
    { 
      vspeed(150,150); 
    } 
    // Скорость 70% 
    if (vcmd == '7') 
    { 
      vspeed(175,175); 
    } 
    // Скорость 80% 
    if (vcmd == '8') 
    { 
      vspeed(200,200); 
    } 
    // Скорость 90% 
    if (vcmd == '9') 
    { 
      vspeed(225,225); 
    } 
    // Скорость 100% 
    if (vcmd == 'q') 
    { 
      vspeed(255,255); 
    } 
  } 
}

// Вперед 
void vforward() { 
  vspeed(vspdL,vspdR); 
  vforwardRL(); 
}

// Вперед для RL 
void vforwardRL() { 
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
}

// Назад 
void vbackward() { 
  vspeed(vspdL,vspdR); 
  vbackwardRL(); 
}

// Назад для RL 
void vbackwardRL() { 
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD); 
}

// Влево 
void vleft() { 
  vspeed(vspdL,vspdR); 
  motor1.run(BACKWARD); 
  motor2.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor4.run(FORWARD); 
}

// Вправо 
void vright() { 
  vspeed(vspdL,vspdR); 
  motor1.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor3.run(FORWARD); 
  motor4.run(BACKWARD); 
}

// Вперед и влево 
void vforwardleft() { 
  if (vspdL > vspd) { 
    vspeed(vspdL-vspd,vspdR); 
  } 
  else 
  { 
    vspeed(0,vspdR); 
  } 
  vforwardRL(); 
}

// Вперед и вправо 
void vforwardright() { 
  if (vspdR > vspd) { 
    vspeed(vspdL,vspdR-vspd); 
  } 
  else 
  { 
    vspeed(vspdL,0); 
  } 
  vforwardRL(); 
}

// Назад и влево 
void vbackwardleft() { 
  if (vspdL > vspd) { 
    vspeed(vspdL-vspd,vspdR); 
  } 
  else 
  { 
    vspeed(0,vspdR); 
  } 
  vbackwardRL(); 
}

// Назад и вправо 
void vbackwardright() { 
  if (vspdR > vspd) { 
    vspeed(vspdL,vspdR-vspd); 
  } 
  else 
  { 
    vspeed(vspdL,0); 
  } 
  vbackwardRL(); 
}

// Стоп 
void vrelease(){ 
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
}

// Изменение скорости 
void vspeed(int spdL,int spdR){ 
  if (spdL == spdR) { 
    vspdL=spdL; 
    vspdR=spdR; 
  } 
  motor1.setSpeed(spdL); 
  motor2.setSpeed(spdR); 
  motor3.setSpeed(spdL); 
  motor4.setSpeed(spdR); 

