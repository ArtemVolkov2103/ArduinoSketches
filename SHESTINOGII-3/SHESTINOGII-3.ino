#include <Multiservo.h>
#include <Wire.h>
#include <SoftwareSerial.h> // Подключаем библиотеку для работы с Serial через дискретные порты

SoftwareSerial BTSerial(50, 51); // RX, TX

Multiservo PrPerBedro;
Multiservo PrPerKol;
Multiservo PrPerStupnya;

Multiservo PrSredStupnya;
Multiservo PrSredBedro;

Multiservo PrZadBegro;
Multiservo PrZadKol;
Multiservo PrZadStupnya;

Multiservo LevZadBedro;
Multiservo LevZadKol;
Multiservo LevZadStupnya;

Multiservo LevSredBedro;
Multiservo LevSredStupnya;

Multiservo LevPerBedro;
Multiservo LevPerKol;
Multiservo LevPerStupnya;

// Создаем переменную для команд Bluetooth 
char vcmd; 

int x=650;
int y=1150;
int z=750;
int w=1350;

int a=y;
int b=x;
int c=x;
int d=w;
int e=z;
int f=y;
int g=x;
int h=x;
int u=w;
int j=z;
int k=z;
int m=y;
int n=x;
int o=w;
int p=z;
int r=z;

int del=5;
void setup() {
  // Устанавливаем скорость передачи данных по Bluetooth 
  BTSerial.begin(9600); 
  // Устанавливаем скорость передачи данных по кабелю 
  Serial.begin(9600);
  Wire.begin();
  PrPerStupnya.attach(6); // Выбираем пин к которому подключен сервопривод
  PrPerKol.attach(7);
  PrPerBedro.attach(8);
  
  
  PrSredStupnya.attach(4);
  PrSredBedro.attach(5);
  
  
  PrZadBegro.attach(2);
  PrZadKol.attach(1);
  PrZadStupnya.attach(0);
  
  
  LevZadBedro.attach(15);
  LevZadKol.attach(16);
  LevZadStupnya.attach(17);
  
  
  LevSredBedro.attach(12);
  LevSredStupnya.attach(13);
  
  LevPerBedro.attach(11);
  LevPerKol.attach(10);
  LevPerStupnya.attach(9);
  
  shaganie(y,x,x,w,z,y,x,x,w,z,z,y,x,w,z,z);
}

void shaganie(int a,int b,int c,int d,int e,int f,int g,int h,int u,int j,int k,int m,int n,int o,int p,int r){  // процедура
 PrPerBedro.writeMicroseconds(a);
 PrPerKol.writeMicroseconds(b);
 PrPerStupnya.writeMicroseconds(c);

 PrSredBedro.writeMicroseconds(d);
 PrSredStupnya.writeMicroseconds(e);

 PrZadBegro.writeMicroseconds(f);
 PrZadKol.writeMicroseconds(g);
 PrZadStupnya.writeMicroseconds(h);

 LevZadBedro.writeMicroseconds(u);
 LevZadKol.writeMicroseconds(j);
 LevZadStupnya.writeMicroseconds(k);

 LevSredBedro.writeMicroseconds(m);
 LevSredStupnya.writeMicroseconds(n);

 LevPerBedro.writeMicroseconds(o);
 LevPerKol.writeMicroseconds(p);
 LevPerStupnya.writeMicroseconds(r);
       
}



////////////////////////////////////////////////////////////////////////////////////////////////////
void vforward() {
   shaganie(y,x,x,w,z,y,x,x,w,z,z,y,x,w,z,z);

for (int i=0; i <= 100; i++){ //ЦИКЛ №1
    b=b+1;
    c=c+1;
    g=g+1;
    h=h+1;
    n=n+1;
    
    e=e-1;
    j=j-1;
    k=k-1;
    p=p-1;
    r=r-1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 200; i++){ //ЦИКЛ №2
   a=a+1;
   f=f+1;
   m=m+1;
   
   d=d-1;
   u=u-1;
   o=o-1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 100; i++){ //ЦИКЛ №3
    b=b-1;
    c=c-1;
    g=g-1;
    h=h-1;
    n=n-1;
    
    e=e+1;
    j=j+1;
    k=k+1;
    p=p+1;
    r=r+1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 200; i++){ //ЦИКЛ №4
   a=a-1;
   f=f-1;
   m=m-1;
   
   d=d+1;
   u=u+1;
   o=o+1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}
}




////////////////////////////////////////////////////////////////////////////////////////////////////
// Назад 
void vbackward() { 
    shaganie(y,x,x,w,z,y,x,x,w,z,z,y,x,w,z,z);

  for (int i=0; i <= 100; i++){ //ЦИКЛ №1
    b=b+1;
    c=c+1;
    g=g+1;
    h=h+1;
    n=n+1;
    
    e=e-1;
    j=j-1;
    k=k-1;
    p=p-1;
    r=r-1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}

for (int i=0; i <= 200; i++){ //ЦИКЛ №2 (который был 4 в forvard)
   a=a-1;
   f=f-1;
   m=m-1;
   
   d=d+1;
   u=u+1;
   o=o+1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}

for (int i=0; i <= 100; i++){ //ЦИКЛ №3
    b=b-1;
    c=c-1;
    g=g-1;
    h=h-1;
    n=n-1;
    
    e=e+1;
    j=j+1;
    k=k+1;
    p=p+1;
    r=r+1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}

for (int i=0; i <= 200; i++){ //ЦИКЛ №4(который был 2 в forvard)
   a=a+1;
   f=f+1;
   m=m+1;
   
   d=d-1;
   u=u-1;
   o=o-1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}

}

void loop() {
 // Если есть данные 
  if (BTSerial.available()) 
  { 
    // Читаем команды и заносим их в переменную. char преобразует код символа команды в символ 
   vcmd = (char)BTSerial.read(); 
    // Отправляем команду в порт, чтобы можно было их проверить в "Мониторе порта" 
    Serial.println(vcmd);

    // Вперед 
    if (vcmd == 'F') { 
      vforward(); 
    } 
    
    // Назад 
    if (vcmd == 'B') 
    { 
      vbackward(); 
    } }
    
    
    
    
    
    
 /*for (int i=0; i <= 100; i++){ //ЦИКЛ №1
    b=b+1;
    c=c+1;
    g=g+1;
    h=h+1;
    n=n+1;
    
    e=e-1;
    j=j-1;
    k=k-1;
    p=p-1;
    r=r-1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 200; i++){ //ЦИКЛ №2
   a=a+1;
   f=f+1;
   m=m+1;
   
   d=d-1;
   u=u-1;
   o=o-1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 100; i++){ //ЦИКЛ №3
    b=b-1;
    c=c-1;
    g=g-1;
    h=h-1;
    n=n-1;
    
    e=e+1;
    j=j+1;
    k=k+1;
    p=p+1;
    r=r+1;

shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}


for (int i=0; i <= 200; i++){ //ЦИКЛ №4
   a=a-1;
   f=f-1;
   m=m-1;
   
   d=d+1;
   u=u+1;
   o=o+1;
   
shaganie(a,b,c,d,e,f,g,h,u,j,k,m,n,o,p,r);
        
   delay(del);
}*/
}

