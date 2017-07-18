
#include    <pic18.h>

#include 		"crt_45k80_main.h"
#include        "cpu18f45k80.h"
#include		"PWM.h"





void    PortInit(void)
{
	TRISA=0;
	TRISB=0;
	TRISC=0;
	TRISD=0;
	TRISE=0;

  	LATA=0xff;	
  	LATB=0xff;	
  	LATC=0xff;	
  	LATD=0xff;	
  	LATE=0xff;	
}


/*
// Timer 기능 구현 	 
*/
void main(void)
{
	unsigned char i;	
    
    di();
    Initial();
    PortInit();
    Timer0Init(); 
	InitPwm1();
    ei();

	msec=0;

    while (1)
	{ 		
        CLRWDT();

		DutyCycle = 0x3ff/3;
		OutPWM(DutyCycle);
    }
}

	

void interrupt isr(void)
{
   
    if( TMR0IF )		
    {    
        TMR0IF = 0 ;
        TMR0L=MSEC_L;
        TMR0H=MSEC_H;    

        msec++;

        if(msec>1000){
            msec=0;
			LED_TX=!LED_TX;
        } 
    }
}




