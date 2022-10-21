/*
 * timers.h
 *
 *  Created on: May 4, 2022
 *      Author: Ziad Abdallah
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "STD_TYPES.h"
#include <avr/io.h>

#define PRESCALER_1					0x01					/* CS10=0, CS10=0, CS10=1 */
#define PRESCALER_8					0x02					/* CS10=0, CS10=1, CS10=0 */
#define PRESCALER_64				0x03					/* CS10=0, CS10=1, CS10=1 */
#define PRESCALER_256				0x04					/* CS10=1, CS10=0, CS10=0 */
#define PRESCALER_1024				0x05					/* CS10=1, CS10=0, CS10=1 */

#define	TIMER1_STOP()						(TCCR1B &= 0xF8)		/* No clock source (Timer/Counter stopped).CS10=0, CS10=0, CS10=0 */
#define TIMER1_START(PRESCALER_VALUE)		(TCCR1B = (TCCR1B&0xF8) | (PRESCALER_VALUE))

void Timer1_Init(uint16 Top_Value, uint8 Enable_Interrupt);

#endif /* TIMERS_H_ */
