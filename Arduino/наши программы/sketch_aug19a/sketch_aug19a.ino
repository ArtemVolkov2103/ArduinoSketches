#define D1 2          // Направление вращение двигателя 1
#define M1 3          // ШИМ вывод для управления двигателем 1
#define D2 4          // Направление вращение двигателя 2
#define M2 5          // ШИМ вывод для управления двигателем 2
 
bool direction = 0;   // Текущее направление вращения       
int value;            // Текущее значение ШИМ
  
void setup() 
{ 
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);  
} 
  
void loop() 
{ 
  for(value = 0; value <= 255; value+=1) 
  { 
    digitalWrite(D1, direction);  // Задаем направление вращения
    digitalWrite(D2, direction);
    analogWrite(M1, value);       // Задаем скорость вращения
    analogWrite(M2, value);
    delay(20); 
  }  
  direction = direction ^ 1;      // Инвертируем значение, чтобы в след. цикле вращаться в другую сторону
}

