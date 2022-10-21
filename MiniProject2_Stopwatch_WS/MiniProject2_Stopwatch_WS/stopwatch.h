/*
 * stopwatch.h
 *
 *  Created on: May 3, 2022
 *      Author: Ziad Abdallah
 *     Project: MiniProject2_Stopwatch_WS
 * Description: Header file for stopwatch module
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "STD_TYPES.h"
#include "stopwatch_cfg.h"
#include "avr/io.h"


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: SevenSegment_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes BCD and 7-segment pins for 7-segment
************************************************************************************/
void SevenSegment_Init(void);

/************************************************************************************
* Service Name: SevenSegment_Display
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): - PinNum for the enable pin of the seven segment
* 				   - DP_Num is the number to be displayed
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Display the number on seven segment
************************************************************************************/
void SevenSegment_Display(uint8 PinNum,\
						  uint8 DP_Num);

/************************************************************************************
* Service Name: Reset_Button_Init
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the reset button connected to PD2(INT0)
************************************************************************************/
void Reset_Button_Init(void);

/************************************************************************************
* Service Name: Pause_Button_Init
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the pause button connected to PD3(INT1)
************************************************************************************/
void Pause_Button_Init(void);

/************************************************************************************
* Service Name: Resume_Button_Init
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the resume button connected to PB2(INT2)
************************************************************************************/
void Resume_Button_Init(void);


/*******************************************************************************
 *                      External Variables										*
 *******************************************************************************/
extern volatile uint8 seconds;			/* stores the count of the seconds */
extern volatile uint8 sec_units_num;		/* stores the units of the seconds */
extern volatile uint8 sec_tens_num;		/* stores the tens of the seconds */

extern volatile uint8 minutes;			/* stores the count of the minutes */
extern volatile uint8 min_units_num;		/* stores the units of the minutes */
extern volatile uint8 min_tens_num;		/* stores the tens of the minutes */

extern volatile uint8 hours;				/* stores the count of the hours */
extern volatile uint8 hour_units_num;	/* stores the units of the hours */
extern volatile uint8 hour_tens_num;		/* stores the tens of the hours */




#endif /* STOPWATCH_H_ */
