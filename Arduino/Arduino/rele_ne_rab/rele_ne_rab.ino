int Relay4 = 4;
int Relay3 = 3;
void setup() 
{                
  pinMode(Relay4, OUTPUT);
 pinMode(Relay3 , OUTPUT);  
}

void loop() 
{ 
  digitalWrite(Relay4, LOW);   // реле включено
  delay(2000);               
  digitalWrite(Relay4, HIGH);  // реле выключено
  delay(2000); 
 digitalWrite(Relay3, LOW);   // реле включено
  delay(2000);               
  digitalWrite(Relay3, HIGH);  // реле выключено
  delay(2000);  
}

