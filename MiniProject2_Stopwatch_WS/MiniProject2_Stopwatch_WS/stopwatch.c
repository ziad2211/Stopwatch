/*
 * stopwatch.c
 *
 *  Created on: May 3, 2022
 *      Author: Ziad Abdallah
 *     Project: MiniProject2_Stopwatch_WS
 * Description: Source file for stopwatch module
 */


#include "stopwatch.h"

volatile uint8 seconds=0;			/* stores the count of the seconds */
volatile uint8 sec_units_num=0;		/* stores the units of the seconds */
volatile uint8 sec_tens_num=0;		/* stores the tens of the seconds */

volatile uint8 minutes=0;			/* stores the count of the minutes */
volatile uint8 min_units_num=0;		/* stores the units of the minutes */
volatile uint8 min_tens_num=0;		/* stores the tens of the minutes */

volatile uint8 hours=0;				/* stores the count of the hours */
volatile uint8 hour_units_num=0;	/* stores the units of the hours */
volatile uint8 hour_tens_num=0;		/* stores the tens of the hours */


void SevenSegment_Init(void)
{
	/* Configure the pins for common anode 7-segment BCD */

	/* Configure 7-segment pins as outputs*/

#if  (SEVEN_SEG_PORT_NUM == 'A')
	DDRA |= SEVEN_SEG_MASK_ENABLE;

#elif (SEVEN_SEG_PORT_NUM == 'B')
	DDRB |= SEVEN_SEG_MASK_ENABLE;

#elif (SEVEN_SEG_PORT_NUM == 'C')
	DDRC |= SEVEN_SEG_MASK_ENABLE;

#elif (SEVEN_SEG_PORT_NUM == 'D')
	DDRD |= SEVEN_SEG_MASK_ENABLE;

#elif (SEVEN_SEG_PORT_NUM == 'E')
	DDRE |= SEVEN_SEG_MASK_ENABLE;

#else
	/* no action required */
#endif /* 7-segment initialization */

	/* Configure BCD pins as outputs
	 * Initialize first number by zero */

#if  (BCD_PORT_NUM == 'A')
	DDRA |= BCD_MASK_PINS;
	PORTA &= ~(BCD_MASK_PINS);

#elif (BCD_PORT_NUM == 'B')
	DDRB |= BCD_MASK_PINS;
	PORTB &= ~(BCD_MASK_PINS);

#elif (BCD_PORT_NUM == 'C')
	DDRC |= BCD_MASK_PINS;
	PORTC &= ~(BCD_MASK_PINS);

#elif (BCD_PORT_NUM == 'D')
	DDRD |= BCD_MASK_PINS;
	PORTD &= ~(BCD_MASK_PINS);
#else
	/* no action required */
#endif /* BCD initialization */

	return;
}

void SevenSegment_Display(uint8_t PinNum,\
						  uint8_t DP_Num)
{
	/* enable seven segment */
#if (SEVEN_SEG_TYPE == ANODE)

#if (SEVEN_SEG_PORT_NUM == 'A')
	PORTA = (1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'B')
	PORTB = (1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'C')
	PORTC = (1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'D')
	PORTD = (1<<PinNum);
#else
	/* no action required*/
#endif /* port num */

#elif (SEVEN_SEG_TYPE == CATHODE)

#if (SEVEN_SEG_PORT_NUM == 'A')
	PORTA = ~(1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'B')
	PORTB = ~(1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'C')
	PORTC = ~(1<<PinNum);
#elif (SEVEN_SEG_PORT_NUM == 'D')
	PORTD = ~(1<<PinNum);
#else
	/* no action required*/
#endif /* port num */

#endif /* seven segment type */

	/* display the output number */
#if  (BCD_PORT_NUM == 'A')
	PORTA = (PORTA&(~BCD_MASK_PINS)) | (DP_Num&BCD_NUM_MASK);

#elif  (BCD_PORT_NUM == 'B')
	PORTB = (PORTB&(~BCD_MASK_PINS)) | (DP_Num&BCD_NUM_MASK);

#elif  (BCD_PORT_NUM == 'C')
	PORTC = (PORTC&(~BCD_MASK_PINS)) | (DP_Num&BCD_NUM_MASK);

#elif  (BCD_PORT_NUM == 'D')
	PORTD = (PORTD&(~BCD_MASK_PINS)) | (DP_Num&BCD_NUM_MASK);
#endif /* display output number */
	return;
}

void Reset_Button_Init(void)
{
	DDRD &= ~(1<<PD2);	/* Configure PD2 as input */
	PORTD |= (1<<PD2);	/* enable internal pull-up resistor for PD2 */

	/* Configure external interrupt as falling edge trigger
	 * ISCO1 = 1, ISC00=0 */
	MCUCR |= (1<<ISC01);
	MCUCR &= ~(1<<ISC00);

	/* Enable external interrupt INT0 */
	GICR |= (1<<INT0);

	/* Enable global interrupt (I-bit) */
	SREG |= (1<<7);

	return;
}

void Pause_Button_Init(void)
{
	DDRD &= ~(1<<PD3);	/* Configure PD3 as input */

	/* Configure external interrupt as rising edge trigger
	 * ISC11 = 1, ISC10=1 */
	MCUCR |= (1<<ISC11) | (1<<ISC10);

	/* Enable external interrupt INT1 */
	GICR |= (1<<INT1);

	/* Enable global interrupt (I-bit) */
	SREG |= (1<<7);

	return;

}

void Resume_Button_Init(void)
{

	DDRB &= ~(1<<PB2);	/* Configure PB2 as input */
	PORTB |= (1<<PB2);	/* enable internal pull-up resistor for PB2 */

	/* Configure external interrupt as falling edge trigger
	 * ISC2 = 0*/
	MCUCSR &= ~(1<<ISC01);

	/* Enable external interrupt INT2 */
	GICR |= (1<<INT2);

	/* Enable global interrupt (I-bit) */
	SREG |= (1<<7);


	return;
}


