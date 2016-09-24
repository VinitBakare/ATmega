#include<avr/io.h>

void main()
{
int x;
int count=0;
DDRA=0;
DDRC=255;


while(1)
{
   x=PINA & 0b00000001;
   if(x==0)
   {
     if(count==0)
    {
     PORTC=0b00001000;
	 count++;
    }
     else if(count==1)
	 {
	    PORTC=0b00000001;
		count++;
     }
	else if(count==2)
	 {
	   PORTC=0b00000110;
	 } 
    }
   else
    
   {
     PORTC=0b00001001;
  }

}
 
}
