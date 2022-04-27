   #include<reg51.h>
  xdata   char *ledPtr; 



void delay()
{  
int i,j;
for(i=0;i<0xf;i++)
for(j=0;j<0xff;j++);
}


void main()
{

ledPtr = 0xffc8;
	while(1)
		{
		*ledPtr = 0X09;
		delay();

*ledPtr = 0X05;
		delay();
*ledPtr = 0X06;
		delay();
*ledPtr = 0X0a;
		delay();
		}
}   
