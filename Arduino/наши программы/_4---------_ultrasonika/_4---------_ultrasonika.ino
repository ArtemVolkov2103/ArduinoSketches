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

// Создаем переменную для запоминания колличества секций 
const int KVADRAT = 32; 
// Массив для хранения данных о расстоянии 
int vHC_SR04_array[4];

void setup() 
{ 
pinMode(Trig1, OUTPUT); pinMode(Trig2, OUTPUT); pinMode(Trig3, OUTPUT); pinMode(Trig4, OUTPUT); 
pinMode(Echo1, INPUT);pinMode(Echo2, INPUT);pinMode(Echo3, INPUT); pinMode(Echo4, INPUT); 

 

  
Serial.begin(9600); 
}

unsigned int time_us1=0;//// Переменные, для хранения данных с дальномера 
unsigned int time_us2=0;
unsigned int time_us3=0;
unsigned int time_us4=0;

unsigned int distance1;
unsigned int distance2;
unsigned int distance3;
unsigned int distance4;


void loop() 
{ 
digitalWrite(Trig1, HIGH);delayMicroseconds(10);digitalWrite(Trig1, LOW);time_us1=pulseIn(Echo1, HIGH);distance1=time_us1/58-15;
Serial.print("X1 = ");Serial.println(distance1);
digitalWrite(Trig2, HIGH);delayMicroseconds(10);digitalWrite(Trig2, LOW);time_us2=pulseIn(Echo2, HIGH);distance2=time_us2/58-15;
Serial.print("Y1 = ");Serial.println(distance2); 
digitalWrite(Trig3, HIGH);delayMicroseconds(10);digitalWrite(Trig3, LOW);time_us3=pulseIn(Echo3, HIGH);distance3=time_us3/58-15;
Serial.print("X2 = ");Serial.println(distance3);
digitalWrite(Trig4, HIGH);delayMicroseconds(10);digitalWrite(Trig4, LOW);time_us4=pulseIn(Echo4, HIGH);distance4=time_us4/58-15;
Serial.print("Y2 = ");Serial.println(distance4);
Serial.println();

delay(1000);
}
