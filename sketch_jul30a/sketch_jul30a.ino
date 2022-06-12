int sensor_pin = A0; 
int output_value ;
int relay=2;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  }

void loop() {
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,580,0,100,0);
  Serial.println(output_value);
   if(output_value < 50){
    digitalWrite(relay,LOW);
    }
    else {
digitalWrite(relay,HIGH);
  }}
