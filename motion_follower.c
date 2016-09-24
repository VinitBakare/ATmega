#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>

void wrcommand(unsigned char command)
{
 cbi(PORTB,PB0);             //rs=0
 PORTD=command;              //data pin loaded with command
 sbi(PORTB,PB1);             //en=1
 _delay_ms(10);              //delay
 cbi(PORTB,PB1);             //en=0
}

void wrdata(unsigned char command)
{
 sbi(PORTB,PB0);             //rs=1 
 PORTD=command;              //data pin loaded with data
 sbi(PORTB,PB1);             //en=1
 _delay_ms(10);              //delay en width
 cbi(PORTB,PB1);             //en=0
}

void lcd_initialisation()
{
 wrcommand(0x80);
 wrcommand(0x38);
 wrcommand(0x06);
 wrcommand(0x01);
 wrcommand(0x0c);
}
void main()
{
 DDRB=255;
 DDRD=255;
 DDRA=0;
 ADCSRA=0b11100101;
 lcd_initialisation();
 while(1)
 {
   ADMUX=0x60;
   _delay_ms(1);
   int x=ADCH;
   _delay_ms(100);
   int x2=ADCH;
   
   ADMUX=0x61;
   _delay_ms(1);
   int y1=ADCH;

   ADMUX=0x62;
   _delay_ms(1);
   int z1=ADCH;

   wrcommand(0x80);
   wrdata(x/100+48);
   wrdata((x/10)%10+48);
   wrdata(x%10+48);
   
   wrdata(' ');

   wrdata(y/100+48);
   wrdata((y/10)%10+48);
   wrdata(y%10+48);
   
   wrdata(' ');

   wrdata(z/100+48);
   wrdata((z/10)%10+48);
   wrdata(z%10+48);
   
  }
}
