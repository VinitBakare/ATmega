// we have to connected analog voltage in port a,1st pin ,convert it into ddigital on LED
#include<avr/io.h>
#include<avr/delay.h>

void main()
{
  ADCSRA=0b11100101;   //CONFIGURE ADC
    DDRB=255;
  while(1)             // SO THAT THE DATA IN X IS READ AGAIN AND AGAIN THOUGH THE CONVERSION IS CONTINUOUS
  {

   ADMUX=0b01100000;   //SOC
   _delay_ms(1);
   int x;
   x=ADCH;
   PORTB=x;

  }

}
