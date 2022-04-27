   #include<reg51.h>
  #include<stdio.h>
  xdata   char *ledPtr; 
unsigned int s;


void delay()
{  
int i,j;
for(i=0;i<0xf;i++)
for(j=0;j<0xff;j++);
}


void main()
{

ledPtr =0xffc5;;
	while(1)
		{
		s=*ledPtr;
		s = ((s&0x20)>>0x05);
		if(s==0)
		printf("\n\r Not Detected");
		
		if(s==1)
		printf("\n\r Detected");

		}
}    
