int val;
int IN1 = 22;
int IN2 = 20;
int IN3 = 24;
int IN4 = 26;
int EN1 = 3;
int EN2 = 5;
int LED = 13;
const int TX_BT = 51;
const int RX_BT = 50;

// Создаем переменную для команд Bluetooth 
char vcmd; 
// Создаем переменные для запоминания скорости двигателей 
int vspdL, vspdR; 
/* Создаем переменную, на значение которой будет уменьшаться скорость при плавных поворотах. 
Текущая скорость должна быть больше этого значения. В противном случае двигатели со стороны направления поворота просто не будут вращаться */ 
int vspd = 200;

 void setup() {
 Serial1.begin(9600); // открывает последовательный порт, устанавливает скорость 9600 бит/c
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  //используем 13 пин как индикатор включённой ардуины
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

}
void loop()
{
  if (Serial.available())
  {
    val = Serial.read();

    // Задаём движение вперёд
    if (val == 'W') // При нажатии клавиши "W"
    {
      // Выводы конфигурируются согласно раьоте Motor Shield'а
      // Моторы крутятся вперед
      digitalWrite(EN1, 155);
      digitalWrite(EN2, 155);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
    }

    // Задаём движение назад
    if ( val == 'S')
    {
      digitalWrite(EN1, 155);
      digitalWrite(EN1, 155);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }

    // Задаём движение вправо
    if ( val == 'D')
    {
      digitalWrite(EN1, 200);
      digitalWrite(EN2, 200);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }

    // Задаём движение влево
    if ( val == 'A')
    {
      digitalWrite(EN1, 200);
      digitalWrite(EN2, 200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }

    // Стоп режим
    // При отпускании клавиш в программе в порт шлется "T"
    if ( val == 'T') // При нажатии клавиши "T"
    {
      // Выводы ENABLE притянуты к минусу, моторы не работают
      digitalWrite(EN1, LOW); 
      digitalWrite(EN2, LOW);
    }
  }
}
