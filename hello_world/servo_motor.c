#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (28, OUTPUT);
  for (;;)
  {
    digitalWrite(28, HIGH);
    delayMicroseconds (1200);
    digitalWrite(28, LOW);
    delayMicroseconds(18800);
    //printf("ACABOU O CICLO \n");
  }
  return 0 ;
}