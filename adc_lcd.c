#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>

unsigned char lcd_read_data(unsigned char ch)
{
  ADMUX =0x60+ch;
  _delay_ms(1);
  return ADCH;
}



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
 unsigned char a,b,c,d,e;
 lcd_initialisation();
 while(1)
 {
   a=lcd_read_data(0);
   b=lcd_read_data(1);
   c=lcd_read_data(2);
   d=lcd_read_data(3);
   e=lcd_read_data(4);

   wrcommand(0x80);
   wrdata(a/100+48);
   wrdata((a/10)%10+48);
   wrdata(a%10+48);
   
   wrdata(' ');

   wrdata(b/100+48);
   wrdata((b/10)%10+48);
   wrdata(b%10+48);
   
   wrdata(' ');

   wrdata(c/100+48);
   wrdata((c/10)%10+48);
   wrdata(c%10+48);
   
   wrdata(' ');

   wrdata(d/100+48);
   wrdata((d/10)%10+48);
   wrdata(d%10+48);
   
   wrdata(' ');

   wrdata(e/100+48);
   wrdata((e/10)%10+48);
   wrdata(e%10+48);

   
}
}
