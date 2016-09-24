#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>//header file for sbi & cbi function

//functions for writing command on lcd
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
 wrcommand(0x0f);
 }

int x_axes()
{
   DDRA=0b00001010;
   PORTA=0b00001000;
   //ADCSRA=0XE5;
   ADMUX=0X62;
   _delay_ms(1);
   return ADCH;
}
int y_axes()
{
   DDRA=0b00000101;
   PORTA=0b00000001;
   //ADCSRA=0XE5;
   ADMUX=0X63;
   _delay_ms(1);
   return ADCH;
}

 
 void main()
{   
    int x,y,a;
    ADCSRA=0b11100101;   //CONFIGURE ADC
    DDRD=255;
	DDRB=255;
	lcd_initialisation();
  while(1)             // SO THAT THE DATA IN X IS READ AGAIN AND AGAIN THOUGH THE CONVERSION IS CONTINUOUS
  {
    
   ADMUX=0b01100000;   //SOC
   _delay_ms(1);
  
   x=x_axes();
   y=y_axes();         //storing adch value for digital converted anolog value of y coordinate

   wrcommand(0x80);
   wrdata(x/100+48);
   wrdata((x/10)%10+48);
   wrdata(x%10+48);
   wrdata('  ');
   wrdata(y/100+48);
   wrdata((y/10)%10+48);
   wrdata(y%10+48);
   
   if(x<=70 && y<=50 && x!=0 && y!=0)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(49);   
   }

    if(x>70 && x<130 && y<=50)

   {
    wrcommand(0xc0);
	wrdata(50);   
   }
    if(x>130 && y<=50)
   {
   // a=1;
    wrcommand(0xc0);
	wrdata(51);
	}   
   
    if(x<=70 && y<130 && y>50)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(52);   
   }
    if(x>70 && x<=130 && y>50 && y<=130)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(53);   
   }
    if(x>130 && y<=130 && y>50)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(54);   
   }
    if(x<=70 && y>130)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(55);   
   }
    if(x>70 && x<=130 && y>130)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(56);   
   }
    if(x>130 && y>130)
   {
    //a=1;
    wrcommand(0xc0);
	wrdata(57);   
   }
   
  }

}


