  #include <Servo.h>   // Подключаем библиотеку для сервоприводом
  
  //Создаем объекты для двигателей 
#define D1 2          // Направление вращение двигателя 1
#define M1 3          // ШИМ вывод для управления двигателем 1
#define D2 4          // Направление вращение двигателя 2
#define M2 5          // ШИМ вывод для управления двигателем 2
 
bool direction = 0;   // Текущее направление вращения       
int value;            // Текущее значение ШИМ
  
  // Создаем объект для сервопривода 
  Servo myservo; 
  
   // Пины, используемые ультразвуковым дальномером 
  const int vTrig = 2; 
  const int vEcho = 4; 
  // Переменные, для хранения данных с дальномера 
  unsigned int vtime_us=0; 
  unsigned int vdistance_sm=0; 
  // Минимальное расстояние в сантиметрах, при котором нужно искать новый маршрут движения 
  const int vmindistance = 30;
  
  
    
  void setup() { 
     // Выбираем пин к которому подключен сервопривод 
     myservo.attach(9); // или 10, если воткнули в крайний разъём 
     // Поворачиваем сервопривод в положение 0 градусов при каждом включении 
     myservo.write(0);  
     
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);  
  }
  
  void loop() { 
 
  for(value = 0; value <= 255; value+=1) 
  { 
    digitalWrite(D1, direction);  // Задаем направление вращения
    digitalWrite(D2, direction);
    analogWrite(M1, value);       // Задаем скорость вращения
    analogWrite(M2, value);
    delay(1000); 
  }  
    digitalWrite(D1, direction);  // Задаем направление вращения
    digitalWrite(D2, direction);
    analogWrite(M1, value);       // Задаем скорость вращения
    analogWrite(M2, value);
    delay(1000); 
  direction = direction ^ 1;      // Инвертируем значение, чтобы
    
  // Движение вперед в течении 5 секунд с поворотом сервы на угол 90 градусов 
  myservo.write(90); // Поворот сервы на угол 90 градусов 
  delay(1000); 
   
  myservo.write(180); // Поворот сервы на угол 180 градусов 
  delay(1000);
  
  // Движение назад в течении 5 секунд с поворотом сервы на угол 90 градусов 
  
  myservo.write(90); // Поворот сервы на угол 90 градусов 
  delay(1000); 
    
  //Поворот влево в течении 2 секунд с поворотом сервы на угол 0 градусов
  
  myservo.write(0); // Поворот сервы на угол 0 градусов 
  delay(1000); 
    
  // Остановка двигателей на 3 секунды с поворотом сервы на угол 90 градусов 
  
  myservo.write(90); // Поворот сервы на угол 90 градусов 
  delay(1000); 
  
  myservo.write(180); // Поворот сервы на угол 180 градусов 
  delay(1000);
  
  }
