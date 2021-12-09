
#include <avr/io.h>
#include "config.h"
#include "timer1.h"

void TMR_voidTMR1Init(void)
{
	/* Select Timer1 Mode = 14 -> Fast PWM, TOP = ICR1 */
	TCCR1A &= ~(1<<0);
	TCCR1A |= (1<<1);
	TCCR1A |= (1<<3);
    TCCR1A |= (1<<4);
	/* Select Non Inverting Mode for OC1A pin */
	TCCR1A &= ~(1<<6);
	TCCR1A |= (1<<7);
	/* Set TOP Value */
	ICR1 = 19999;
	/*Set Initial Direction = 0 Degree */
	OCR1A = 1000 - 1;
	/* Start Timer Using Prescaler */
	/*CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);*/
}
void SetCompareMatchValue(unsigned short int CompareMatchValue)
{
    OCR1A = CompareMatchValue-1;
}