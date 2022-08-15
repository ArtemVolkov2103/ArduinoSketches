#include <Multiservo.h>
#include <Wire.h>

Multiservo levPerLok;

int a=135;

void setup() {
  Wire.begin();
    Serial.begin(9600);
      levPerLok.attach(0);

shaganie(135);
}
  void shaganie(byte a){  // процедура
  levPerLok.write(a);
}

void loop() {
   for (int i=0; i <= 5; i++){
     
      a=a-5;
      shaganie(a);
      delay(3000);
      Serial.println(a);
   }
for (int i=5; i >= 0; i--){
     
     a=a+5;
      shaganie(a);
      delay(3000);
      Serial.println(a);
   }
}
