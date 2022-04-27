#include<8051.h>
#define HIGH 01;
#define LOW  00;
__xdata __at 0xffc5 unsigned char swt;
__xdata __at 0xffc0 unsigned char led;
__idata unsigned char dat;
__idata unsigned char i;
__bit __at(0x94) SCLK;
__bit __at(0x95) SDA;
 bit ACK;
 void I2C_Start(void);
 void I2C_Stop(void);
 void I2C_Write(unsigned char j);
 unsigned char I2C_Read(void);
 void Delay_Time(); 	
void I2C_Start(void)		//Start I2C by creating clock by setting and clearing the port pins
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
void I2C_Stop(void)		//Stop I2C operation by clearing the SCLK Pin
 {
    SCLK = LOW;
    Delay_Time();
    SDA = HIGH;
 }
void I2C_Write(unsigned char j) // shifting data bit by bit to MSB and moving through i2c
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
unsigned char I2C_Read(void) //reading from i2c device bit by bit
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
	unsigned int i=0xff;
		I2C_Start();
		I2C_Write(0x9E);    //send device address
		I2C_Write(0x40);	  //send device's control register address
		I2C_Start();
		I2C_Write(0x9E);    // send command for read
		while(1)
	    {
		I2C_Write(i);
	    if((swt & 0x1f)== 0x1E)
	   	{
	   	i=i-1;
	   	Delay_Time();
	    led = i;
	    }
		}
}
void Delay_Time()
{
 unsigned int i; 
 for(i=0;i<=1000;i++);
}       
   





  


