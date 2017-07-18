
#include	<pic18.h>
#include	"PWM.h"


// PIN_PWM Mode On
void PwmOn(void)
{
	CCP1M3=1;
	CCP1M2=1;
	CCP1M1=0;
	CCP1M0=0;
}

void PwmOff(void)
{
	CCP1M3=0;
	CCP1M2=0;
	CCP1M1=0;
	CCP1M0=0;
}


void OutPWM(unsigned int DutyCycle)
{
	DC1B0 = (bit)DutyCycle; 	//update the PIN_PWM duty cycle 
	DC1B1 = (bit)(DutyCycle>>1);
	CCPR1L = (DutyCycle>>2);	//13.04.30
}



void InitPwm1(void)
{	
	TMR2IE=0;
	TMR2IP=0;
	TMR2IF=0;
	CCP1CON=0x0;	/* select PIN_PWM mode */
	PwmOn(); // PIN_PWM ON	

	PR2 = 0xff;			
	T2CON = 0x06;		// 가장 안정적이다. 다른 값은 오랜시간 사용시 열이 난다. 

	DutyCycle = 0; // Q???
	OutPWM(DutyCycle); // Q???
}

