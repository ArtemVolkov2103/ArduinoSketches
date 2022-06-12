void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.print ("Enter N: "); 
  while(!Serial.available());
  int N = Serial.parseInt();
  Serial.println(N);
  Serial.print("Enter R: ");
  while(!Serial.available());
  int R = Serial.parseInt();
  Serial.println(R);
  float F = (float)N / R;
  Serial.print("Result F: ");
  Serial.println(F);
  Serial.println();
}
