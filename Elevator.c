#include<reg51.h>
#include<stdio.h>




xdata  char *ele_sw; 
xdata  char *ledPtr; 

//unsigned int switch_data;
//unsigned int data1[] = {0x00,0x30,0x9b,0xb9,0xb4,0xad,0xa7,0x38,0xbf,0xbd};

unsigned char req_pos;
unsigned char cur_pos =0x10;

void delay()
{
int i,j;
for(i=0;i<0xff;i++)
for(j=0;j<0xff;j++);
}

void move(unsigned char req_pos,unsigned char *cur_pos)
{
unsigned char mov_pos;
mov_pos=~req_pos;
while (mov_pos!=*cur_pos)
	{
	//ledPtr=*cur_pos;
	//delay();
	if(mov_pos < *cur_pos)
	*cur_pos=*cur_pos>>1;
	else
	*cur_pos=*cur_pos<<1;
	*ledPtr=*cur_pos;
	delay();
  	}
}

void main()
{
ele_sw = 0xffc5;
ledPtr= 0xffc6;


while(1)
	{
	req_pos = *ele_sw;
	req_pos = (~(req_pos)) & 0x1f;
	
	printf("\n\r Req Pos %x",req_pos);
	printf("\n\r Current Pos %x",cur_pos);
	//*ledPtr = req_pos;
	
	
	if((req_pos & 0x1f) == 0x1f || ~req_pos == cur_pos)
	*ledPtr = cur_pos;
	else
	move(req_pos,&cur_pos);		
	}   
} 
 
