 #include<reg51.h>
#include<stdio.h>

xdata  char *ledPtr; 
xdata  char *switchptr;

unsigned int s;
void delay()
{
unsigned int i,j;
for(i=0;i<0x3ff;i++)
for(j=0;j<0xff;j++);

}

void main()
{
ledPtr= 0xffc0;
switchptr = 0xffc1;

while(1)
	{
	s = *switchptr;
	*ledPtr  = s;
	}		
}
   
