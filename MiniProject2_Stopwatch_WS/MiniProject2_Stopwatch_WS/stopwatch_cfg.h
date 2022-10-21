/*
 * stopwatch_cfg.h
 *
 *  Created on: May 3, 2022
 *      Author: Ziad Abdallah
 *     Project: MiniProject2_Stopwatch_WS
 * Description: configuration file for stopwatch
 */

#ifndef STOPWATCH_CFG_H_
#define STOPWATCH_CFG_H_

#define		ANODE						(1u)
#define		CATHODE						(0u)
#define		SEVEN_SEG_PORT_NUM			'A'					/* 7-segment  pins connected to Port A*/
#define		SEVEN_SEG_MASK_ENABLE		(uint8_t)0x1F		/* Mask for 7-segment enable pins (PA0-PA5)*/
#define		SEVEN_SEG_TYPE				ANODE 				/* Type of 7-segment is common anode */

#define		BCD_PORT_NUM				'C'					/* BCD pins connected to Port C*/
#define 	BCD_MASK_PINS				(uint8_t)0x0F		/* Mask for BCD output pins */
#define		BCD_NUM_MASK				(uint8_t)0x0F		/* Mask for BCD display number */
#define		SEC_U						PA0					/* Enable pin for the seconds units place */
#define		SEC_T						PA1					/* Enable pin for the seconds tens place */
#define		MIN_U						PA2					/* Enable pin for the minutes units place */
#define		MIN_T						PA3					/* Enable pin for the minutes tens place */
#define		HOUR_U						PA4					/* Enable pin for the hours units place */
#define		HOUR_T						PA5					/* Enable pin for the hours tens place */

#define		DP_DELAY					10					/* the display time for each 7-segment cell */
#define		ONE_SECOND					(uint16)15625		/* Top value in timer1 to get 1 second */
#endif /* STOPWATCH_CFG_H_ */
