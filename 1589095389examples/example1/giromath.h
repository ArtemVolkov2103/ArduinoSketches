double AcYsum = 0;
double AcXsum = 0;
double AcZsum = 0;
uint32_t dt;
uint32_t  t0;
uint32_t micros_;


double PIDz=0, 
       Iz = 0;

double  Kpz = 40.0;
double  Kdz = 4.00;
//double  Kddz = 0.5;
double  Kiz = 600.0;



double maxIz = 5;

double AzCom = 0;

double maxPidz = 12;
 
//==================================
//double dGyroZ=0;
//double OldGyroZ=0;
double GyroZ, GyroY, GyroX, Acsel;
int i = 0, j = 0; //Счетчики
float imu[3];
const int max_j=2;
float quat[4];
float e[3];
//==================================
#define TO_RAD 0.01745329252f // этот коэффициент нужен нам для перевода градусов в радианы
//==================================
double CompensatorZ=0, CompensatorX=0, CompensatorY=0;
