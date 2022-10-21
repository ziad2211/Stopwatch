/*
 * timers.c
 *
 *  Created on: May 4, 2022
 *      Author: Ziad Abdallah
 */


#include "timers.h"

void Timer1_Init(uint16 Top_Value, uint8 Enable_Interrupt)
{
	/*Configure TCCR1A Register
	 * Non PWM mode: COM1A1 = 0, COM1A0 = 0, COM1B1 = 0, COM1B0 = 0
	 * FOC1A = 0, FOC1B = 0
	 * Configure as CTC mode: WGM11 = 0, WGM10 = 0
	 */
	TCCR1A = 0;

	/* Configure TCCR1B Register
	 * Configure as CTC mode: WGM13 = 0
	 * Configure as CTC mode: WGM13 = 0, WGM12 = 1,
	 * Initialize timer as turned off: CS12=0, CS11=0, CS10=0
	 * */
	TCCR1B = (1<<WGM12);

	/* Initialize counting from zero */
	TCNT1 = 0;

	/* Set the output compare match to the top value */
	OCR1A = Top_Value;

	/* Configure module interrupt */
	if(Enable_Interrupt == TRUE)
	{
		SREG |= (1<<7); /* Enable global interrupt (i-bit) */
		TIMSK |= (1<<OCIE1A); /* Enable module interrupt */
	}
	else
	{
		TIMSK &= ~(1<<OCIE1A);	/* Disable module interrupt */
	}

}
