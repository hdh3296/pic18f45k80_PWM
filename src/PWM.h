
#ifndef _PWM_H_
#define _PWM_H_

#define DUTI_MAX 0x3ff // 1023
unsigned int	DutyCycle;

void InitPwm1(void);
void PwmOn(void);
void PwmOff(void);
void OutPWM(unsigned int DutyCycle);




#endif
