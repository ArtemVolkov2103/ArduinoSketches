#include <AFMotor.h> // Подключаем библиотеку для управления двигателями 
#include <Servo.h>   // Подключаем библиотеку для сервоприводов  
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(3); //канал М2 на Motor Shield — задний правый й 
// Создаем объект для сервопривода 
Servo vservo; 
// Прописываем пины используемые модулем Bluetooth 
SoftwareSerial BTSerial(50, 51); // RX, TX 
// Создаем переменную для команд Bluetooth 
char vcmd; 
// Создаем переменные для запоминания скорости левых и правых двигателей 
int vspdL, vspdR; 
/* Создаем переменную, на значение которой будет уменьшаться скорость при плавных поворотах. 
Текущая скорость должна быть больше этого значения.  В противном случае двигатели со стороны направления поворота просто не будут вращаться */ 
const int vspd = 200; 
// Заносим в массив пины, к которым подключены светодиоды 
const int vledpins[6]={ 
  22,23,24,25,26,27}; 
// Создаем переменную для сохранения режима работы 
int vmode; 
// Создаем переменную для сохранения предыдущего режима работы 
int vmodeprev = -1; 
// Заносим в массив пины, к которым подключены кнопки 
const int vbtn[2]={ 
  28,29}; 
// Массив для хранения углов поворота сервопривода (шаг 15 градусов) 
const int vservo_array[13]={ 
  0,15,30,45,60,75,90,105,120,135,150,165,180}; 
// Массив для хранения данных о расстоянии под различными углами поворота сервопривода 
int vHC_SR04_array[13]; 
// Пины, используемые ультразвуковым дальномером 
const int vTrig = 2; 
const int vEcho = 4; 
// Переменные, для хранения данных с дальномера 
unsigned int vtime_us=0; 
unsigned int vdistance_sm=0; 
// Минимальное расстояние в сантиметрах, при котором нужно искать новый маршрут движения 
const int vmindistance = 30; 
// Переменная для циклов перебора значения массивов vservo_array и vHC_SR04_array 
int vservo_int; 
// Переменные для цикла поиска максимального значения в массивах 
int vmaxarrayindex_int; 
int vmaxarrayvalue_int;

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
  /* Устанавливаем все выводы, к которым подключены светодиоды, 
   в OUTPUT. Зажигаем и гасим светодиоды с интервалом в 0.5 сек 
   для проверки */ 
  for (vmode = 0; vmode < 6; vmode = vmode + 1) { 
    pinMode(vledpins[vmode], OUTPUT);  
    digitalWrite(vledpins[vmode], HIGH); 
    delay (500); 
    digitalWrite(vledpins[vmode], LOW); 
  } 
  /* Устанавливаем выводы, к которым подключены кнопки, в INPUT. */ 
  pinMode(vbtn[0], INPUT);  
  pinMode(vbtn[1], INPUT); 
  // Устанавливаем значение первого режима работы робота 
  vmode = 0; 
  // Устанавливаем значение для пинов, к которым подключен ультразвуковой дальномер 
  pinMode(vTrig, OUTPUT); 
  pinMode(vEcho, INPUT); 
}

void loop() { 
  /* Переключение режимов работы робота */ 
  // Кнопка переключения на следующий режим - BTN1 
  if (digitalRead(vbtn[0]) == HIGH) {  
    vmode = vmode + 1;  
    vmodeprev = vmode - 1; 
    if (vmode > 5) { 
      vmode = 0; 
      vmodeprev = 5; 
    } 
    vrelease(); 
    delay (500); 
  } 
  // Кнопка переключения на предыдущий режим - BTN2 
  if (digitalRead(vbtn[1]) == HIGH) {  
    vmode = vmode - 1;  
    vmodeprev = vmode + 1; 
    if (vmode < 0) { 
      vmode = 5; 
      vmodeprev = 0; 
    } 
    vrelease(); 
    delay (500); 
  } 
  // Засвечиваем светодиод текущего режима работы 
  digitalWrite(vledpins[vmode], HIGH); 
  // Гасим светодиод предыдущего режима работы 
  if (vmodeprev > -1) { 
    digitalWrite(vledpins[vmodeprev], LOW); 
  } 
  /* Выбор режима работы */ 
  switch (vmode) { 
  case 0: 
    // Режим ожидания 
    break; 
  case 1: 
    // Режим работы с использованием ультразвукового дальномера 
    vultrasoundmode(); 
    break; 
  case 2: 
    // Режим 
    break; 
  case 3: 
    // Режим управления через Bluetooth 
    vbluetoothmode(); 
    break; 
  case 4: 
    // Режим 
    break; 
  case 5: 
    // Режим 
    break; 
  } 
} 
/* Режим работы с использованием ультразвукового дальномера */ 
void vultrasoundmode(){ 
  vservo.write(90);                  
  delay(200); 
  Serial.print("Now "); 
  Serial.println(vHC_SR04()); 
  // Если расстояние меньше наименьшего, то 
  if (vHC_SR04() < vmindistance) { 
    // Останавливаем двигатели 
    vrelease(); 
    // Крутим серву измеряя расстояния и занося данные в массив 
    for (vservo_int = 0; vservo_int < 13; vservo_int = vservo_int + 1) { 
      vservo.write(vservo_array[vservo_int]); 
      delay(200); 
      vHC_SR04_array[vservo_int] = vHC_SR04(); 
      // Выводим данные для отладки 
      Serial.print(vservo_int); 
      Serial.print(" "); 
      Serial.println(vHC_SR04_array[vservo_int]); 
    } 
    vservo.write(90); 
    delay(500); 
    // Поиск в массиве позиции с максимальным значением 
    vmaxarrayindex_int = 0; 
    vmaxarrayvalue_int = 0;    
    for (vservo_int = 0; vservo_int < 13; vservo_int = vservo_int + 1) {     
      if (vHC_SR04_array[vservo_int] > vmaxarrayvalue_int) { 
        vmaxarrayindex_int = vservo_int; 
        vmaxarrayvalue_int = vHC_SR04_array[vservo_int]; 
      } 
    } 
    Serial.print("Max index "); 
    Serial.println(vmaxarrayindex_int); 
    // Проверка - если максимальное значение массива меньше минимального расстояния, то едем назад 
    if (vHC_SR04_array[vmaxarrayindex_int] < vmindistance) { 
      vbackward(); 
      delay(500); 
    } 
    /* Проверка - если индекс максимального значения массива меньше 6 то поворачиваем вправо, 
    иначе влево */ 
    if (vmaxarrayindex_int < 6) { 
      vright(); 
      delay(500); 
    } 
    else 
    { 
      vleft(); 
      delay(500); 
    } 
  } 
  else 
  { 
    // Едем прямо 
    vforward(); 
  } 
}

/* Режим управления через Bluetooth */ 
void vbluetoothmode() { 
  // Если есть данные с Bluetooth 
  if (BTSerial.available()) 
  { 
    /* Читаем команды и заносим их в переменную. 
     (char) преобразует код символа команды в символ */ 
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

/* Функция определения расстояния с дальномера */ 
int vHC_SR04() { 
  digitalWrite(vTrig, HIGH); // Подаем сигнал на выход микроконтроллера 
  delayMicroseconds(10); // Удерживаем 10 микросекунд 
  digitalWrite(vTrig, LOW); // Затем убираем 
  vtime_us=pulseIn(vEcho, HIGH); // Замеряем длину импульса 
  vdistance_sm=vtime_us/58; // Пересчитываем в сантиметры 
  return vdistance_sm; // Возвращаем значение 
}

/* Функции управления двигателями */

// Вперед 
void vforward() { 
  vspeed(vspdL,vspdR); 
  vforwardRL(); 
}

// Вперед для RL 
void vforwardRL() { 
  motor1.run(FORWARD); 
  motor2.run(FORWARD);  
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
}

// Влево 
void vleft() { 
  vspeed(vspdL,vspdR); 
  motor1.run(BACKWARD); 
  motor2.run(FORWARD); 
}

// Вправо 
void vright() { 
  vspeed(vspdL,vspdR); 
  motor1.run(FORWARD); 
  motor2.run(BACKWARD); 

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

}

// Изменение скорости 
void vspeed(int spdL,int spdR){ 
  if (spdL == spdR) { 
    vspdL=spdL; 
    vspdR=spdR; 
  } 
  motor1.setSpeed(spdL); 
  motor2.setSpeed(spdR); 


}
