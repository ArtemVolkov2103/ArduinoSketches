const int Trig1 = 50; //№1
const int Echo1= 52;

const int Trig2 = 40; //№2
const int Echo2 = 42; 

const int Trig3 = 30;//№3 
const int Echo3 = 32; 

const int Trig4 = 20;//№4
const int Echo4 = 22; 
const int ledPin1 = 10;  // 13 – если будете использовать встроенный в Arduino светодиод
const int ledPin2 = 11;  // 13 – если будете использовать встроенный
const int ledPin3 = 12;  // 13 – если будете использовать встроенный
const int ledPin4 = 13;  // 13 – если будете использовать встроенный

void setup() 
{ 
pinMode(Trig1, OUTPUT); pinMode(Trig2, OUTPUT); pinMode(Trig3, OUTPUT); pinMode(Trig4, OUTPUT); 
pinMode(Echo1, INPUT);pinMode(Echo2, INPUT);pinMode(Echo3, INPUT); pinMode(Echo4, INPUT); 

 
pinMode(ledPin1, OUTPUT);pinMode(ledPin2, OUTPUT);pinMode(ledPin3, OUTPUT);pinMode(ledPin4, OUTPUT); 
 
  
Serial.begin(9600); 
}

unsigned int time_us1=0;
unsigned int time_us2=0;
unsigned int time_us3=0;
unsigned int time_us4=0;

unsigned int distance1=0;
unsigned int distance2=0;
unsigned int distance3=0;
unsigned int distance4=0;

void loop() 
{ 
digitalWrite(Trig1, HIGH);digitalWrite(Trig2, HIGH);digitalWrite(Trig3, HIGH);digitalWrite(Trig4, HIGH); // Подаем сигнал на выход микроконтроллера 
delayMicroseconds(10); // Удерживаем 10 микросекунд 
digitalWrite(Trig1, LOW);digitalWrite(Trig2, LOW);digitalWrite(Trig3, LOW);digitalWrite(Trig4, LOW); // Затем убираем 
time_us1=pulseIn(Echo1, HIGH);time_us2=pulseIn(Echo2, HIGH);time_us3=pulseIn(Echo3, HIGH);time_us4=pulseIn(Echo4, HIGH); // Замеряем длину импульса 
distance1=time_us1/58; // Пересчитываем в сантиметры 
distance2=time_us2/58; // Пересчитываем в сантиметры 
distance3=time_us3/58; // Пересчитываем в сантиметры 
distance4=time_us4/58; // Пересчитываем в сантиметры 
Serial.println(distance1); // Выводим на порт
Serial.println(distance2); // Выводим на порт
Serial.println(distance3); // Выводим на порт
Serial.println(distance4); // Выводим на порт
Serial.println(); // Выводим на порт

/*
if (distance_sm<30) // Если расстояние менее 50 сантиметром 
{ 
   digitalWrite(ledPin1, 1); // Зажигаем светодиод 
   digitalWrite(ledPin2, 1); // Зажигаем светодиод 
   digitalWrite(ledPin3, 1); // Зажигаем светодиод 
   digitalWrite(ledPin4, 1); // Зажигаем светодиод 
} 
else 
{ 
   digitalWrite(ledPin1, 0); // иначе тушим 
} 
  */
delay(1000); 
}
