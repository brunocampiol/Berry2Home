#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (9, INPUT);
  pinMode (0, OUTPUT);
  for (;;)
  {
  	if(digitalRead(9) == 0)
  		digitalWrite(0, LOW);
  	else
  		digitalWrite(0, HIGH);
  	delay(50);
  }
  return 0 ;
}
