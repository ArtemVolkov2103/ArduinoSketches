


//int pin = 19;                                                
volatile unsigned int encoder = 0;//начальное значение шагов энкодера
 
void setup()
{
  //pinMode(pin, INPUT);

  attachInterrupt(4,Probeg,CHANGE);


  Serial.begin(9600);
}
 
void loop()
{
  Serial.println(encoder);
    Serial.println();
    delay(100);
}
 
void Probeg() //пробег
{
encoder = encoder+1;

 }
