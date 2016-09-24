#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>

int ADC_get_data(int  ch)
{
  ADMUX =0x40;               //right adjusted 10 bit data display(ADLAR=0)
  _delay_ms(1);
  int a=ADCL;                //to read from LSB
  int b=ADCH;
  int c=a|(b<<8);            //left shifting 8 bits of ADCH & THEN:(ADCH+ADCL) 
  return c;
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
 int a,b;
 lcd_initialisation();
 while(1)
 {
   b=ADC_get_data(0);     
   a=b/2;               //2 reading corrspnds to 1deg celcius

   wrcommand(0x80);
   wrdata(a/1000+48);
   wrdata((a/100)%10+48);
   wrdata((a/10)%10+48);
   wrdata((a%10)+48);
     
  }
}
