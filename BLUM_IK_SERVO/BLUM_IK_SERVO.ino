                //#include <Servo.h>

                //Servo ArtemServo;
                //int servoPin = 9;
int distPin = 6;

void setup() {
  Serial.begin(9600);                // ArtemServo.attach(servoPin);

}

void loop() {
 int dist = analogRead(distPin);
 int pos = map(dist,0,1023,0,230);
 Serial.println(pos);
                     delay(100);  //ArtemServo.write(pos);

}
