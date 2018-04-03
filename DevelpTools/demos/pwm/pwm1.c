#include<msp430g2553.h>
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  	volatile int i=-1;
    TACTL=TASSEL_1+TACLR;
    CCR0=85-1;//PWM周期
    CCTL1=OUTMOD_7;
    CCR1=20;//384/512=0.75
    P1DIR|=BIT2;
    P1SEL|=BIT2;
    TACTL|=MC_1;//增计数模式
    while(1)
    {
		if(i==2) i=0;
		else i+=1;

		switch(i)
		{
			case 0:
				CCR1 = 29;
				break;
			case 1:
				CCR1 = 54;
				break;
			case 2:
				CCR1 = 78;
				break;
		}

		__delay_cycles(10000000);
    }
  return 0;
}
