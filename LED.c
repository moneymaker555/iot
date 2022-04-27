#include<reg51.h>
#include<stdio.h>

xdata  char *ledPtr; 

void delay()
{
TMOD = 0x01;
TH0 = 0xff;
TL0 = 0xa3;
TR0 = 1;

while(TF0 == 0);
TR0 = 0;

}

void main()
{


ledPtr= 0xffc0;

while(1)
	{
	*ledPtr  = 0x55;
	delay();
	*ledPtr  = 0xaa;
	delay();
	}		
}
   
