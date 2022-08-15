int IN1 = 4; // Input3 подключен к выводу 5 
int IN2 = 5;
int IN3 = 6; // Input3 подключен к выводу 5 
int IN4 = 7;
void setup()
{
  pinMode (IN1 ,OUTPUT); // Input3 подключен к выводу 5 
  pinMode (IN2 ,OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}
void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор вращается   
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  delay(1000);
 
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); 
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  delay(1000);

}

