int IN1 = 7; // Input1 подключен к выводу 5 
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int ENA = 9;
int ENB = 3;
int i;
void setup()
{
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
}
void loop()
{
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); 
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  for (i = 50; i <= 180; ++i)
  {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      delay(30);
  }
  analogWrite (ENA, 0);
  analogWrite (ENB, 0);
  delay(500);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  for (i = 50; i <= 180; ++i)
  {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      delay(30);
  }
  analogWrite (ENA, 0);
  analogWrite (ENB, 0);
  delay(8000);
}
