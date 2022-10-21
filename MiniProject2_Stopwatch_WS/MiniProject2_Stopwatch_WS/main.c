/*
 * main.c
 *
 *  Created on: May 3, 2022
 *      Author: Ziad Abdallah
 *     Project: MiniProject2_Stopwatch_WS
 *		  File: main file
 */


#include <util/delay.h>
#include <avr/interrupt.h>
#include "stopwatch.h"
#include "timers.h"

/************************************************************************************
* Service Name: ISR(TIMER1_COMPA_vect)
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Increment the timer every one second
************************************************************************************/
ISR(TIMER1_COMPA_vect)
{
	/* Enable nested interrupts */
	SREG |= (1<<7); /* Re-enable global interrupt (I-bit) */
	seconds++;
	if(seconds>59)
	{
		seconds=0;
		minutes++;
		if(minutes>59)
		{
			minutes=0;
			hours++;
			if(hours>12)
			{
				hours=0;
			}
		}
	}
	sec_units_num = seconds%10;
	sec_tens_num = seconds/10;

	min_units_num = minutes%10;
	min_tens_num = minutes/10;

	hour_units_num = hours%10;
	hour_tens_num = hours/10;
}

/************************************************************************************
* Service Name: ISR(INT0_vect)
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Reset the timer whenever the reset button is pressed (INT0 is triggered)
************************************************************************************/
ISR(INT0_vect)
{
	/* Reset the timer */
	seconds = 0;
	minutes = 0;
	hours = 0;

	sec_units_num = 0;
	sec_tens_num = 0;

	min_units_num = 0;
	min_tens_num = 0;

	hour_units_num = 0;
	hour_tens_num = 0;

	/* Reinitialize timer counting from zero */
	TCNT1 = 0;
}

/************************************************************************************
* Service Name: ISR(INT1_vect)
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Pause the timer whenever the pause button is pressed (INT1 is triggered)
************************************************************************************/
ISR(INT1_vect)
{
	/*disconnect the clock source from the timer */
	TIMER1_STOP();
}


/************************************************************************************
* Service Name: ISR(INT2_vect)
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Resume the timer whenever the resume button is pressed (INT2 is triggered)
************************************************************************************/
ISR(INT2_vect)
{
	/* connect the clock source to the timer */
	TIMER1_START(PRESCALER_64);
}


int main(void){
	/* Initialization Code */
	SevenSegment_Init();

	Timer1_Init(ONE_SECOND, TRUE);
	TIMER1_START(PRESCALER_64);

	Reset_Button_Init();

	Pause_Button_Init();

	Resume_Button_Init();

	sec_units_num = seconds%10;
	sec_tens_num = seconds/10;

	min_units_num = minutes%10;
	min_tens_num = minutes/10;

	hour_units_num = hours%10;
	hour_tens_num = hours/10;

	while(1)
	{
		/* Application Code */

		/* Display units and tens of seconds */
		SevenSegment_Display(SEC_U, sec_units_num);
		_delay_us(DP_DELAY);
		SevenSegment_Display(SEC_T, sec_tens_num);
		_delay_us(DP_DELAY);

		/* Display units and tens of minutes */
		SevenSegment_Display(MIN_U, min_units_num);
		_delay_us(DP_DELAY);
		SevenSegment_Display(MIN_T, min_tens_num);
		_delay_us(DP_DELAY);

		/* Display units and tens of hours */
		SevenSegment_Display(HOUR_U, hour_units_num);
		_delay_us(DP_DELAY);
		SevenSegment_Display(HOUR_T, hour_tens_num);
		_delay_us(DP_DELAY);
	}	

	return 0;
}
