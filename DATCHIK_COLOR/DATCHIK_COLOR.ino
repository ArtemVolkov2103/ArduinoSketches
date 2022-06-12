int s0 = 8; 
int s1 = 9; 
int s2 = 12; 
int s3 = 11; 
int out = 10; 
// порты светодиодов
//int pinred = 2; 
//int pinblue = 3; 
//int pingreen = 4; 
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
 //pinMode(pinred, OUTPUT); 
 //pinMode(pinblue, OUTPUT); 
 //pinMode(pingreen, OUTPUT); 
 Serial.begin(9600); 
 digitalWrite(s0, HIGH); 
 digitalWrite(s1, HIGH); 
 // включаем их, чтобы проверить работоспособность.
     //digitalWrite(pinred, HIGH); 
     // digitalWrite(pinblue, HIGH); 
     //digitalWrite(pingreen, HIGH); 
 delay(2000);
} 
 
void loop() 
{ 
 color();
 // выводим значение в консоль
 Serial.print("       RED :" + String(red)); 
 Serial.print("  GREEN : " + String(green)); 
 Serial.println("  BLUE : " + String(blue)); 
 
 // условия, при которых включаются определенные светодиоды
 if (red < blue && red < green && red < 15 && 7 < red) { 
 Serial.println(" RED"); 
 //svet(pinred);
 } 
 else if (blue < red && blue > green && green < 27) { 
 Serial.println(" GREEN"); 
 //svet(pingreen);
 } 
 else if (green > blue && red > blue && 22 > blue) { 
 Serial.println(" BLUE"); 
 //svet(pinblue);
 } 
  else if (red < 8 && green<8 && blue < 8) { 
 Serial.println(" WHITE!!!!!!!!!!!!!!!!!!!!!!!"); 
 }
  else if (red < blue && red < green && red < 7) { 
 Serial.println(" yellow!!!!!!!!!!!!!!!!!!!!!!!"); 
 }
 else {
// svet(0); 
 }
delay(2000); 
} 
 /*
// функция, включающая определенный светодиод
void svet(int pin){
 digitalWrite(pinred, pin == pinred ? HIGH : LOW); 
 digitalWrite(pinblue, pin == pinblue ? HIGH : LOW); 
 digitalWrite(pingreen, pin == pingreen ? HIGH : LOW); 
}*/
 
void color() 
{ 
 digitalWrite(s2, LOW); 
 digitalWrite(s3, LOW); 
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 digitalWrite(s3, HIGH); 
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
 digitalWrite(s2, HIGH); 
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
