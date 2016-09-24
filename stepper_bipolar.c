#include<avr/io.h>
#include<util/delay.h>
void main()
{
 DDRB=0xFF;
  while(1)
    {
	 PORTB=0x01;
	 _delay_ms(5);
	 PORTB=0x02;
	 _delay_ms(5);
	 PORTB=0x04;
	 _delay_ms(5);
	 PORTB=0x08;
	 _delay_ms(5);
	 }

	}
