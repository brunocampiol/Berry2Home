#include <wiringPi.h>
int main (void)
{
  int i, i2 = -1;
  wiringPiSetup () ;
  pinMode (28, INPUT);
  pinMode (29, OUTPUT); //debug: LED
  delay(2000);
  for (;;)
  {
    i = digitalRead(28);
    if((i == HIGH)&&(i2 != i)){
      printf("MOVIMENTO! \n");
      i2 = i;
    }
    else if(i2 != i){
      printf("PARADO! \n");
      i2 = i;
    }
    digitalWrite(29, i); //debug: LED
  }
  return 0 ;
}