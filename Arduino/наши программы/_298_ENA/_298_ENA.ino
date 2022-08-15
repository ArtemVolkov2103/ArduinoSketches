int IN3 = 5; // Input3 подключен к выводу 5 
int IN4 = 4;
int ENB = 3;
void setup()
{
 pinMode (ENB, OUTPUT); 
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}
void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор готов к вращаению
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  // подаем на вывод ENB управляюший ШИМ сигнал 
  analogWrite(ENB,55);
  delay(2000);
  analogWrite(ENB,105);
  delay(2000);
  analogWrite(ENB,255);
  delay(2000);
  // Останавливаем мотор повад на вывод ENB сигнал низкого уровеня. 
  // Состояние выводво "IN" роли не играет.
  analogWrite(ENB,0);
  delay(5000);
}
