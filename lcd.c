#include <reg51.h>
#include "delay.h"

#define lcddata P2
#define dataport P0


sbit rs = dataport^0;
sbit rw = dataport^1;
sbit en = dataport^2;



void cmd(unsigned char a)
{
	lcddata=(a & 0xf0);
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
	lcddata=(a << 4);
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
	
}

void dat(unsigned char a)
{
	lcddata=(a & 0xf0);
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	lcddata=(a << 4);
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	

}




void mssg(unsigned char *ch)
{
	while(*ch!='\0')
	{
		dat(*ch++);
	}
}

void init()
{
	//cmd(0x28);
	//cmd(0x0e);
	//cmd(0x01);
	//cmd(0x06);
	cmd(0x28); //4bit mode
	cmd(0x0e); //display on cursor blinking
	cmd(0x01); //clear screen
	cmd(0x06);
	cmd(0x80);
}
