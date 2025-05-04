#include<reg51.h>
#include "lcd.h"
#include "delay.h"

void main()
{
	init();
	
	while(1)
	{
		cmd(0x80);
		mssg("hello");
		delay(500);	
	}
}

