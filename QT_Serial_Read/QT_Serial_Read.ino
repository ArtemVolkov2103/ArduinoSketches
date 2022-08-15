#include <SoftwareSerial.h>
#include <Servo.h>
String str;//="1200,1201,1202,1203,1204,1205,1206,1207,1208,1209,1210,1211,@ ";
Servo servo1;
Servo servo2;
void setup() { 
  Serial.begin(9600);
  Serial.setTimeout(30);
  servo1.attach(8);
  servo2.attach(9);
  pinMode(6, OUTPUT);
  analogWrite(6, 128);
}
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
while (Serial.available()){
    str=Serial.readString();
    String buff;
    int command[13];
    for(int i=0; i<13; i++){
    buff = getValue(str, ',', i);
    command[i] =  buff.toInt();
    //Serial.println(command[i]);
    int a=map(command[0],540,2400,0,180);
    int b=map(command[1],540,2400,0,180);
    analogWrite(6, a);
    servo1.write(a);
    servo2.write(b);
    }
   str="";
   buff ="";
}
}
