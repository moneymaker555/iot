   
//THIS PROGRAM FOR REAL TIME CLOCK IN PCF8583 USING VPIC-89C51.

#include<reg51.h>
#include<stdio.h>

#include<string.h>


void I2C_WRITE(unsigned char);
void Data_Write(unsigned char [],unsigned int);
unsigned char I2C_READ();
void Delay_Time();

void busycheck();
void I2C_START();
void I2C_STOP();
void lcdint();
void ser_int();

unsigned int READ;
sbit  SCLK=P1^4;
sbit  SDA =P1^5;
bit   ACK;

#define HIGH 01;
#define LOW  00;
idata unsigned char dat;
idata unsigned char i;
unsigned int read_time[0x03];

void set_rtc_time();
void get_rtc_time();
int get_hour();
int get_minute();
int get_second();


unsigned char hour,minute,second;

		void set_hour()
		{
			I2C_START();
   		I2C_WRITE(0XA0);
   		I2C_WRITE(0x04);
   		I2C_WRITE(0x11);
   		I2C_STOP();
		}


		void set_minute()
		{
			I2C_START();
	   	I2C_WRITE(0XA0);
	   	I2C_WRITE(0x03);
   		I2C_WRITE(0x59);
   		I2C_STOP();
		}


		void set_second()
		{
			I2C_START();
			I2C_WRITE(0XA0);
	   	I2C_WRITE(0x02);
   		I2C_WRITE(0x56);
   		I2C_STOP();
		}
		
		
		int get_second()
		{
		unsigned char s;

		I2C_START();
		I2C_WRITE(0XA0);
		I2C_WRITE(0x02);
		I2C_STOP();	
		I2C_START();
		I2C_WRITE(0XA1);
		s = I2C_READ();
		I2C_STOP();	
		return(s);
	}
		
	
	int get_minute()
	{
		unsigned char m;

		I2C_START();
		I2C_WRITE(0XA0);
		I2C_WRITE(0x03);
		I2C_STOP();	
		I2C_START();
		I2C_WRITE(0XA1);
		m = I2C_READ();
		I2C_STOP();	
		return(m);
	}		
	

	int get_hour()
	{
		unsigned char h;
		
		I2C_START();
		I2C_WRITE(0XA0);
		I2C_WRITE(0x04);
		I2C_STOP();
		I2C_START();
		I2C_WRITE(0XA1);
		h = I2C_READ();
		I2C_STOP();
		return(h);
	}


	void main()
	{
 	serial();
 		set_hour();
 		set_hour(); 
 		set_minute();
 		set_second();
 		while(1)
 			{
 					second = get_second();
 					minute = get_minute();
 		 			hour   = get_hour();
 					minute = get_minute();
 					second = get_second();
 		 			hour   = get_hour();

 					printf("\n\r Real Time Clock  = %x:%x",hour,minute);
					minute = get_minute();
 					minute = get_minute();
 					second = get_second();
 					printf(":%x",second);
 				}
}


void serial()
{
    SCON  = 0x50;		        
    TMOD  = 0x20;              
	TH1   = 0xfd;  
	TR1   = 1;
    TI    = 1;

}

void I2C_START()
{
		SCLK =LOW;
		SDA  =LOW;
		
		Delay_Time();
		Delay_Time();
		SCLK=HIGH;
		Delay_Time();
		Delay_Time();
		SDA=HIGH;
		Delay_Time();
		Delay_Time();
		SDA=LOW;
		Delay_Time();
		Delay_Time();
		SCLK=LOW;
}

void I2C_WRITE(unsigned char j)
{
	dat=j;
   for(i=0;i<8;i++)
   {
    	 SDA = dat & 0x80;       
       dat=dat<<1;
       SCLK=HIGH;
       Delay_Time();
       Delay_Time();
       SCLK = LOW;
	}
  		SDA=HIGH;
  		Delay_Time();
  		Delay_Time();
  		SCLK = HIGH;
  		Delay_Time();
  		Delay_Time();
  		ACK = SDA;
  		Delay_Time();
  		Delay_Time();
  		SCLK=LOW;
}

void I2C_STOP()
{
		SCLK=LOW;
		Delay_Time();
		Delay_Time();
		SDA=HIGH;
}

unsigned char  I2C_READ()
{
	unsigned char i,j;
	j=0;
	j=SDA;
	
	for(i=0;i<8;i++)
		{
			j<<=1;
			SCLK=HIGH;
			j|=SDA;
			Delay_Time();			
			SCLK=LOW;
		}
	Delay_Time();
	Delay_Time();
	SDA = LOW;
	Delay_Time();
	Delay_Time();
	SCLK = HIGH;
	Delay_Time();
	Delay_Time();
	SCLK = LOW;
	Delay_Time();
	Delay_Time();
	SDA = HIGH;
	return(j);
	}

void Delay_Time()
{   unsigned long int i;
	for(i=0;i<200;i++);

}
 
 
 

