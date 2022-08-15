int sensor_pin = A5; 
int output_value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }

void loop() {
  output_value = analogRead(sensor_pin);
  output_value = map(output_value,1023,0,100,0);
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(500);
  }  
