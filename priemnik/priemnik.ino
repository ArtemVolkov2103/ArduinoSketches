#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
    pinMode( 13, OUTPUT );
    mySwitch.enableReceive(0);
    Serial.begin(9600);
}

void loop() {
    if( mySwitch.available() ){
        int value = mySwitch.getReceivedValue();
        Serial.println(value);
        mySwitch.resetAvailable();
    }
}
