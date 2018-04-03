
#include "msp430g2553.h"


// *************************************************************
// 延时函数，对于1M主频，约延时1ms
// *************************************************************
void delay_1ms(void)
  {
    unsigned int k;
    for (k=0;k<195;k++);
  }

// *************************************************************
// 延时函数，延时n*ms
// *************************************************************
void delay_nms(unsigned int n)
  {
    unsigned int j;
    for (j=0;j<n;j++)
    {
      delay_1ms();
    }
  }

// *************************************************************
// 主程序
// *************************************************************
void main(void)
{
  unsigned const PWMPeriod = 512; //设置PWMPeriod参数
  volatile unsigned int i;        //变量
  WDTCTL = WDTPW + WDTHOLD;   // 关闭看门狗
  BCSCTL1= CALBC1_1MHZ;        //1M内部时钟，其他也可以
  DCOCTL = CALDCO_1MHZ;   
  P1DIR |=BIT6;              // 设置 P1.6为输出
  P1SEL |=BIT6;              // 设置 P1.6为TA0.1输出
  TACCR0 = PWMPeriod;           // 设置PWM 周期
  TACCTL1 = OUTMOD_7;           // 设置PWM 输出模式为：7 - PWM复位/置位模式，
                              // 即输出电平在TAR的值等于CCR1时复位为0，当TAR的值等于CCR0时置位为1，改变CCR1，从而产生PWM。其实模式2也可以
   TACTL =  TASSEL_2 +MC_1;    // 设置TIMERA的时钟源为SMCLK, 计数模式为up,到CCR0再自动从0开始计数
  while(1)
  {
   CCR1=200;//确保开始是暗的
     delay_nms(1000); //暗0.6S增强效果
     CCR1=200;  //确保灯暗
     delay_nms(1000); //暗0.6S增强效果
  }
}
