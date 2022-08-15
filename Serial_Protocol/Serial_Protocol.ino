#include <string.h>

char unitID_in[10];
char command_in[10];
char data_in[100];

void setup() {
  // открываем порт 
  Serial.begin(9600); 
  pinMode(13,OUTPUT);
}

//--------пример команды: 013,on,ok

void loop() {         

  int i=0;
  char buffer[100];

//если есть данные - считаем их
  if(Serial.available()){
     delay(100);

//сохраним прочитанное в буфер
     while( Serial.available() && i< 99) { buffer[i++] = Serial.read(); } //закрываем массив buffer[i++]=' '; } //если вдруг буфер наполнен if(i>0){  

//разобьем его на части, отделенные запятой
    sscanf(buffer, "%[^','],%[^','],%s", &unitID_in, &command_in, &data_in);

  }

//Исполнительная часть программы
//Проверяем, к какому устройству пришли данные

//Тестовое устройство 001
    if ((String)unitID_in == "001"){  //test serial read
      Serial.print("001,arduino recive: unit ");
      Serial.print(unitID_in);
      Serial.print("n");
      Serial.print("command: ");
      Serial.print(command_in);
      Serial.print("n");
      Serial.print("data: ");
      Serial.print(data_in);      
      Serial.print("n");
      unitID_in [0] = ' '; 
      command_in [0] = ' ';            
    }

//пример выполнения команды устройством 013
     if ((String)unitID_in == "013"){

      if ((String)command_in == "on"){
          digitalWrite(13, HIGH);}
      if ((String)command_in == "off"){
          digitalWrite(13, LOW);}   

      Serial.print("001,arduino recive: unit ");
      Serial.print(unitID_in);
      Serial.print(" command ");
      Serial.print(command_in);
      Serial.print("\n");
      unitID_in [0] = ' ';
      command_in [0] = ' ';            
    }
}
