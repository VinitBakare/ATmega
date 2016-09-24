#include<avr/io.h>
void main()
{
int x;
DDRC=255;
DDRA=0;
PORTA=255;

while(1)
{
x=PINA & 0b00011111;
 if(x==0b00011011)
 {
   PORTC=0b00001001;
 }

   else if(x==0b00011001)    //left
     PORTC=0b00000001;

    else if(x==0b00011000)   //extreme left
	 PORTC=0b00000101;

   else if(x==0b00010011)   //right
	   PORTC=0b00001000;

   else if(x==0b00000011)   //extreme right
       PORTC=0b00001010;

   else if(x==0b00011111)   //stop
       PORTC=0;
  }
}
