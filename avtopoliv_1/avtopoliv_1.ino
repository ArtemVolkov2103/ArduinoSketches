int sensor_pin = A5; 
int sensor2_pin = A4;
int output_value;
int output2_value;

long previousMillis = 0;        // храним время последнего переключения 
long interval = 1000;           // интервал между включение/выключением(1 секунда)


void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(sensor2_pin, INPUT);
  pinMode(6, OUTPUT);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
 //digitalWrite(7, LOW);
  Serial.println("Reading From the Sensor ...");
  delay(100);
  ReadValue();
  }

void loop() {
  if(output_value>=50 && output2_value>=50){
    unsigned long currentMillis = millis();
    //проверяем не прошел ли нужный интервал, если прошел то
    if(currentMillis - previousMillis > interval) {
      // сохраняем время последнего переключения
      previousMillis = currentMillis; 
    
      ReadValue();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      analogWrite(6, map(output_value,100,0,0,255));
  }}
  
  else{
    if(output_value<=50 && output2_value>=50){
      while(output_value<=50){
        digitalWrite(3, LOW);
        Serial.println("                  1");
        ReadValue();
        if(output_value>=50){//для моментального выключения
          digitalWrite(3, HIGH);
        }
      }
    }

    if(output_value>=50 && output2_value<=50){
      while(output2_value<=50){
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        Serial.println("                  2");
        ReadValue();
        if(output2_value>=50){//для моментального выключения
         digitalWrite(4, HIGH);
         digitalWrite(5, HIGH);
        }
      }
    }
    
    else{
      while(output_value<=50&&output2_value<=50){
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        Serial.println("                  3");
        ReadValue();
        if(output_value>=50){//для моментального выключения
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
        }
      }
    }
    
  }
}  

int ReadValue(){
  output_value = analogRead(sensor_pin);
  output_value = map(output_value,512,0,100,0);
  output2_value = analogRead(sensor2_pin);
  output2_value = map(output2_value,512,0,100,0);
  Serial.print("Влажность: ");
  Serial.print(output_value);
  Serial.print("% "); 
  Serial.print(output2_value);
  Serial.println("%"); 
  
}
