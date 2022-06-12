#define axis_X A0    // Ось Х подключена к Analog 0
#define axis_Y A1    // Ось Y подключена к Analog 1
#define axis_Z A3    // Ось Z (кнопка джойстика) подключена к Digital 2
 
int value_X, value_Y, value_Z = 0;    // Переменные для хранения значений осей
 
void setup() {
  pinMode(axis_Z, INPUT);    // Задаем как вход
  Serial.begin(9600);
}
 
void loop() {
  value_X = analogRead(axis_X);    // Считываем аналоговое значение оси Х
  Serial.print("X:");
  Serial.print(value_X, DEC);      // Выводим значение в Serial Monitor
 
  value_Y = analogRead(axis_Y);    // Считываем аналоговое значение оси Y
  Serial.print(" | Y:");
  Serial.print(value_Y, DEC);      // Выводим значение в Serial Monitor
 
  value_Z = digitalRead(axis_Z);   // Считываем цифровое значение оси Z (кнопка)
  //value_Z = value_Z ^ 1;           // Инвертируем значение
  Serial.print(" | Z: ");
  Serial.println(value_Z);    // Выводим значение в Serial Monitor
 
  delay(250);                      // Задержка 250 мс
}
