#define encoderPinA 2
#define encoderPinB 3
 
 
unsigned int encoderPos = 0;
unsigned int encoderPosPrev = 0;
unsigned int encoderPosInc;
 
unsigned long set_time = 0;
 
void setup() {
 
 pinMode(encoderPinA, INPUT);
 pinMode(encoderPinB, INPUT);
 
// encoder pin on interrupt 0 (pin 2)
 
 attachInterrupt(0, doEncoderA, CHANGE);
 
// encoder pin on interrupt 1 (pin 3)
 
 attachInterrupt(1, doEncoderB, CHANGE); 
 
 Serial.begin (57600);
}
 
void loop(){ //Do stuff here
 
 unsigned long time = millis();  
 
 if (time > set_time) {
   set_time = set_time + 20;
   if (encoderPos > encoderPosPrev) {
 
   encoderPosInc = encoderPos - encoderPosPrev;   
   }
   else
   {
   encoderPosInc = encoderPosPrev - encoderPos;
   }
  
   byte Rate_Hi = ((encoderPosInc >> 6) & 0xFE);
   byte Rate_Lo = ((encoderPosInc << 1) & 0xFE); 
    
  //Send ADC out in MatLAB:
 
   Serial.print("A"); // it is header
   Serial.write(Rate_Lo);
   Serial.write(Rate_Hi); // output byte: uint8   
   
   encoderPosPrev = encoderPos; 
 }
}
 
void doEncoderA(){
 
 // look for a low-to-high on channel A
 
 if (digitalRead(encoderPinA) == HIGH) {
   // check channel B to see which way encoder is turning
 
   if (digitalRead(encoderPinB) == LOW) { 
   encoderPos = encoderPos + 1;   // CW
   }
 
   else {
   encoderPos = encoderPos - 1;   // CCW
   }
 }
 
 else  // must be a high-to-low edge on channel A   
 
 {
   // check channel B to see which way encoder is turning 
   if (digitalRead(encoderPinB) == HIGH) {  
 
   encoderPos = encoderPos + 1;   // CW
 
   }
   else {
 
   encoderPos = encoderPos - 1;   // CCW
 
   }
  }
}
 
void doEncoderB(){
 
 // look for a low-to-high on channel B
 
 if (digitalRead(encoderPinB) == HIGH) {  
  // check channel A to see which way encoder is turning
   if (digitalRead(encoderPinA) == HIGH) { 
 
   encoderPos = encoderPos + 1;   // CW
 
   }
   else {
 
   encoderPos = encoderPos - 1;   // CCW
 
   }
 }
 // Look for a high-to-low on channel B
 else {
   // check channel B to see which way encoder is turning 
   if (digitalRead(encoderPinA) == LOW) {  
 
   encoderPos = encoderPos + 1;   // CW
 
   }
   else {
 
   encoderPos = encoderPos - 1;   // CCW
 
   }
  }
}

