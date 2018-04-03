#include<msp430g2553.h>
int main(void)
{
	WDTCTL = WDTPW|WDTHOLD;
	TACTL = TASSEL_1 + TACLR+MC_1;
	CCR0 = 4;
	CCR1 = 2;
	CCTL1 = OUTMOD_3;
	P1SEL |= BIT2 + BIT6;
	P1DIR |= BIT2 + BIT6;
	while(1)
	{
			_NOP();
	}
}
