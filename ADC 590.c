  #include<Reg51.h>
#include<stdio.h>
//#include<serial.h>

#define HIGH 01;
#define LOW  00;



idata unsigned char dat;
idata unsigned char i;

 sbit SCLK=P1^4;
 sbit SDA=P1^5;
 bit  ACK;	
 
 void I2C_Start(void);
 void I2C_Stop(void);
 void I2C_Write(unsigned char j);
 unsigned char I2C_Read(void);
 void Delay_Time(); 	


void serial()
{
 	 TMOD = 0x20;
	 TH1  = 0xfd;
	 TL1  = 0x00;
	 TCON  = 0x40;
	 SCON = 0x50;
	

} 

void I2C_Start(void)
 {
    SCLK=LOW;
    SDA=LOW;
    Delay_Time();
    SCLK = HIGH;
    Delay_Time();
    SDA=HIGH;
    Delay_Time();
    SDA = LOW;
    Delay_Time();
    SCLK = LOW;
 }

void I2C_Stop(void)
 {
    SCLK = LOW;
    Delay_Time();
    SDA = HIGH;
 }
void I2C_Write(unsigned char j)
{
   dat=j;
   for(i=0;i<8;i++)
   
     {
       SDA = dat & 0x80;			
       dat=dat<<1;
       SCLK = HIGH;
       Delay_Time();
       SCLK = LOW;
     }
         
  SDA=HIGH;
  Delay_Time();
  SCLK = HIGH;
  Delay_Time();
  ACK = SDA;
  Delay_Time();
  SCLK = LOW;
}
unsigned char I2C_Read(void)
{ 
  unsigned char i,j;
  j = 0;
  i = SDA;
  for(i=0;i<8;i++)
    {
      j<<=1;
      SCLK = HIGH;
      j |= SDA;
      Delay_Time();
      SCLK = LOW;
   }
  Delay_Time();
  SDA = LOW;   
  Delay_Time();
  SCLK = HIGH;
  Delay_Time();  
  SCLK = LOW;
  Delay_Time();
  SDA = HIGH;
  return j;
}

void main()
{    
		int data1;
     int i=0x24;
         

   	I2C_Start();
		I2C_Write(0x9E);    //ac write ad read device address
		I2C_Write(0x42);	  //control register
      
	
		I2C_Start();
		I2C_Write(0x9f);
	
	  while(1)
	  {
	   data1=I2C_Read();
	//	I2C_Stop();
		serial();
		SBUF=' ';     
		printf("\n\r  %x",data1);
		}
		delay_time();
	//	goto loop;
	


}
void Delay_Time()
{
 unsigned int i; 
 for(i=0;i<=5000;i++);
}       
   





  
  
