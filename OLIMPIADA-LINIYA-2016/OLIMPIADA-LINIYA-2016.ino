#include <AFMotor.h>
//Создаем объекты для двигателей 
AF_DCMotor motor1(1); //канал М1 на Motor Shield — задний левый 
AF_DCMotor motor2(2); //канал М2 на Motor Shield — задний правый

//motor1 right motor
const int Trig = 50;//нельзя использовать порты моторов(1,2,3,4)
const int Echo = 52;//2 часа искал ошибку

const int analogPin = 8;
const int analogPin2 = 9;
const int analogPin3 = 10;

int skorost1=200;
int skorost2=200;
int del=200;
//int RF;int LF;int RB;int LB;

void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);   // Скорость работы порта
  Serial.println("Z-Line Sensor Test"); // Выводим текст
  Serial.println();     // Пустая строка 
    
   motor1.setSpeed(skorost1); 
   motor2.setSpeed(skorost2); 
                           /*   motor1.run(RELEASE);
                            motor2.run(RELEASE); */
}

unsigned int time_us=0;
unsigned int distance_sm=0;

//Перекресток
  void PEREKRESTOK(){
     vforward;
     
    }
   void OTVETVLENIE(){
    vforward;
   }
// Вперед
  void vforward() { 
    
      motor1.run(RELEASE);
      motor2.run(RELEASE); 
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
}

// Назад 
  void vbackward() { 
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD);
       delay(500);
    motor1.run(RELEASE);
    motor2.run(RELEASE); 
}

// Влево 
  void vleft() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);  
    motor1.run(FORWARD);
//    motor2.run(BACKWARD);
  
}

// Вправо 
  void vright() { 
    motor1.run(RELEASE);
     motor2.run(RELEASE); 
 //    motor1.run(BACKWARD); 
     motor2.run(FORWARD);
}

    // Стоп 
  void STOPP(){ 
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 

}

 
void loop() {

digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера 
delayMicroseconds(10); // Удерживаем 10 микросекунд 
digitalWrite(Trig, LOW); // Затем убираем 
time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
distance_sm=time_us/58; // Пересчитываем в сантиметры 
Serial.print("            distance");Serial.println(distance_sm); Serial.println();// Выводим на порт

  
  int analogValue = analogRead(analogPin);
  int analogValue2 = analogRead(analogPin2);
  int analogValue3 = analogRead(analogPin3);
 
    Serial.print("L-");Serial.print(analogValue3); Serial.print(" ");
    Serial.print("C-");Serial.print(analogValue2);Serial.print(" "); 
    Serial.print("R-");Serial.println(analogValue);Serial.print(" ");  
    Serial.println();
  
   if (analogValue3 < 100 && analogValue2 > 100 && analogValue < 100 ){ 
                     //БЕЛЫЙ--ЧЕРНЫЙ--БЕЛЫЙ
    vforward();                             
      Serial.print("      LINE");
}
    
    
   if( analogValue3 < 100 && analogValue2 < 100 && analogValue > 100){
                   //БЕЛЫЙ--БЕЛЫЙ--ЧЕРНЫЙ
     
      vright();
      Serial.println("           LINE ");
      Serial.print("           RIGHT ");   
       }         
   
   if(analogValue3 > 100 && analogValue2 < 100 && analogValue < 100 ){
                    //ЧЕРНЫЙ--БЕЛЫЙ--БЕЛЫЙ

    vleft();
      Serial.println("LINE ");
      Serial.print("LEFT "); 
      }
      
      
     /*if(analogValue3 < 100 && analogValue2 < 100 && analogValue < 100){
                    //БЕЛЫЙ--БЕЛЫЙ--БЕЛЫЙ
      Serial.println(" WHITE ");
      //vright();
    }      */                    //delay(2000);
     /* else{
              vleft();  delay(2000);   //  vbackward();     
        vforward();
       delay(1000);    
 }*/
      if(analogValue3 > 100 && analogValue2 > 100 && analogValue > 100){
                    //ЧЕРНЫЙ--ЧЕРНЫЙ--ЧЕРНЫЙ
                    //ПЕРЕКРЕСТОК +                 
  
        vforward(); 

  }
 /* if(analogValue3 < 100 && analogValue2 > 100 && analogValue > 100 || analogValue3 > 100 && analogValue2 > 100 && analogValue < 100){
                      //БЕЛЫЙ--ЧЕРНЫЙ--ЧЕРНЫЙ //ЧЕРНЫЙ--ЧЕРНЫЙ--БЕЛЫЙ
                    //ОТВЕТВЛЕНИЕ  |- и -|                 
          vforward();
  }*/
  
  /*if(analogValue3 > 100 && analogValue2 < 100 && analogValue > 100){
                    //ЧЕРНЫЙ--БЕЛЫЙ--ЧЕРНЫЙ
                    //МОСТ  |||
     vforward();
  }*/
   
}
