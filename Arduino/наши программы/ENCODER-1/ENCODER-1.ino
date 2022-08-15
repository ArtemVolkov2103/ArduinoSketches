
                                               
unsigned int encoder = 0;//начальное значение шагов энкодера

void Probeg(){ 
  encoder = encoder+1;
}
 
void setup(){

  attachInterrupt(4,Probeg,LOW);
  Serial.begin(9600);
}
 
void loop(){
  Serial.println(encoder);
    Serial.println("    ");
}
 


