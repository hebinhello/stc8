#include "reg51.h"
#define TIMS 3036
sfr AUXR  =0x8E;
sfr P6 =0xE8;
void timer_0() interrupt 1
{
	P6=~P6;
}
main()
{
	TL0=TIMS;
	TH0=TIMS>>8;
	AUXR&=0x7F;
	TMOD=0x08;
	P6=0;
	TR0=1;
	ET0=1;
	EA=1;
	while(1);
}