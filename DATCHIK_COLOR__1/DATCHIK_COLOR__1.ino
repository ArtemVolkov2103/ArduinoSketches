int s0 = 8; 
int s1 = 9; 
int s2 = 12; 
int s3 = 11; 
int out = 10; 
int red = 0; 
int green = 0; 
int blue = 0; 
 
void setup() 
{ 
 pinMode(s0, OUTPUT); 
 pinMode(s1, OUTPUT); 
 pinMode(s2, OUTPUT); 
 pinMode(s3, OUTPUT); 
 pinMode(out, INPUT); 
 Serial.begin(9600); 
 digitalWrite(s0, HIGH); 
 digitalWrite(s1, HIGH); 
} 
 
void loop() 
{ 
 color();
 // выводим значения цветов
 Serial.print(" RED :" + String(red)); 
 Serial.print(" GREEN : " + String(green)); 
 Serial.println(" BLUE : " + String(blue)); 
 delay(500); 
} 
 
void color() 
{ 
 // если 11 и 12 порты отключить, то мы получим красный цвет
 digitalWrite(s2, LOW); 
 digitalWrite(s3, LOW); 
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 // если 11 порт включить, а 12 отключить, то синий
 digitalWrite(s3, HIGH); 
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 // если 12 включить, а 11 отключить, то зеленый
 digitalWrite(s2, HIGH); 
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
