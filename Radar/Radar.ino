// Includes the Servo library
#include <Servo.h>. 

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
const int trigPin2 = 4;
const int echoPin2 = 5;
// Variables for the duration and the distance
long duration;
int distance;
long duration2;
int distance2;

int pos=0;

int Distance[180];

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(9); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=0;i<=179;i++){ 
    pos=map(i,0,179, 25, 160);
    myServo.write(pos);
    delay(30);
    distance = calculateDistance();
    distance2 = calculateDistance2();
    Distance[i] = distance;
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.println(distance2);
  }
  
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=179;i>0;i--){  
    pos=map(i,0,179, 25, 160);
    myServo.write(pos);
    delay(30);
    distance = calculateDistance();
    distance2 = calculateDistance2();
    Distance[i] = distance;
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.println(distance2);
  }
// for(int i=0;i<=179;i++){  
//  Serial.println(Distance[i]);
//  delay(40);
// }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration/58;
  return distance;
}

int calculateDistance2(){ 
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance2= duration2 /58;
  return distance2;
}
