#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>

void main()
{
  ADCSRA=0b11100101;   //CONFIGURE ADC
  DDRB=255;
  DDRA=0;          
  while(1)             // SO THAT THE DATA IN X IS READ AGAIN AND AGAIN THOUGH THE CONVERSION IS CONTINUOUS
  {
  
   ADMUX=0b01100000;   //SOC
   _delay_ms(1);       //as adc requires 13usec for conversion 4rm A to D
   int a=ADCH;
  
   ADMUX=0b01100001;
   _delay_ms(1);
   int b=ADCH;

   ADMUX=0b01100010;
   _delay_ms(1);
   int c=ADCH;

   ADMUX=0b01100011;
   _delay_ms(1);
   int d=ADCH;
   
   ADMUX=0b01100100;
   _delay_ms(1);
   int e=ADCH;

  if(a>51) 
  {
    sbi(PORTB,PB0);
  }

   if(b>51) 
  {
     sbi(PORTB,PB1);
  }

   if(c>51) 
  {
     sbi(PORTB,PB2);
  }

   if(d>51) 
  {
    sbi(PORTB,PB3);
  }

   if(e>51) 
  {
    sbi(PORTB,PB4);
  }
   
   else
   PORTB=0;
  
 }

}
