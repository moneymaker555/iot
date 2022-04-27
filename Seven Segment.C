#include<reg51.h>
#include<stdio.h>

xdata  char *segmentselPtr; 
xdata  char *swPtr; 

unsigned int switch_data;

//unsigned int data1[] = {0xc0,0xf9,0x24,0x30,0x19,0x12,0x03,0x78,0x00,0x10};
unsigned int data1[] = {0x00,0x06,0x5b,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};
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
segmentselPtr= 0xffc2;
swPtr = 0xffc3;
while(1)
	{

	
*swPtr  = 0x04;
	for(k=0;k<10;k++)  {
	*segmentselPtr  = data1[k];
	delay();           }
	

*swPtr  = 0x08;
	for(k=0;k<10;k++){
	*segmentselPtr  = data1[k];
	delay();         }

	
	}		
}  
