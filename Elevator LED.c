#include<reg51.h>
#include<stdio.h>


xdata  char *ledPtr; 
xdata  char *switchPtr; 
unsigned int switch_data;

unsigned int data1[] = {0x00,0x30,0x9b,0xb9,0xb4,0xad,0xa7,0x38,0xbf,0xbd};
unsigned int k;
void delay()
{
unsigned int i,j,m;
for(m=0;m<0x04;m++)
for(i=0;i<0xff;i++)
for(j=0;j<0xff;j++);

}

void main()
{

ledPtr = 0xffc6;
//switchPtr=0xffcc;
while(1)
	{

	*ledPtr  = 0X00;
	delay();
	*ledPtr  = 0Xff;
	delay();
	}		
}    
