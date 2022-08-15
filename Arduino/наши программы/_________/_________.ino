 * IR-led & phototransistor
 * тестовый скетч для работы с фототранзистором
 *
 * http://robocraft.ru
 */

int photoPin = 0;  // фоторезистор подключен 0-му аналоговому входу
int ledPin = 13;   // светодиод подключается к digital pin 9
int val = 0;       // переменная для хранения значения входного напряжения

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(ledPin, HIGH);    // зажигаем
  val = analogRead(photoPin);    // считываем значение с фототранзистора
  Serial.println(val);
  
  // здесь можно проверить значение на превышение заданного порога

  delay(200);
}
