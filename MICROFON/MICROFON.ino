 
long soundTime=0; // время 1-го хлопка
int soundinputPin = 3;               // choose the input pin (for PIR sensor)
int soundState = LOW;             // we start, assuming no motion detected
int soundval = 0;                    // variable for reading the pin status
 
void setup() {

  pinMode(soundinputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  soundval = digitalRead(soundinputPin);  // read input value
  if (soundval == HIGH) {            // check if the input is HIGH
    if (soundState == LOW) {
      // we have just turned on
      long secondSoundTime=millis(); // лучше измерить один раз для if
      if((millis()>soundTime) && ((secondSoundTime-soundTime)>500) && ((secondSoundTime-soundTime)<1500))  { 
      
      Serial.println("Motion detected!");
      
      }
            soundTime=millis();
      // We only want to print on the output change, not state
      soundState = HIGH;
    }
  } else {
    if (soundState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");

      // We only want to print on the output change, not state
      soundState = LOW;
    }
  }
}
