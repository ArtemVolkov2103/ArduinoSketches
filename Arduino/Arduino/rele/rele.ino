int Relay1 = 4;
int Relay = 2;
void setup() 
{                
  pinMode(Relay, OUTPUT);    
  pinMode(Relay1, OUTPUT);     
 
}

void loop() 
{
  digitalWrite(Relay, HIGH);   // реле включено
  delay(1000);               
  digitalWrite(Relay,LOW);  // реле выключено
  delay(1000);   
  digitalWrite(Relay1, HIGH);   // реле включено
  delay(1000);
  digitalWrite(Relay1,LOW);  // реле выключено
  delay(1000);     
}
