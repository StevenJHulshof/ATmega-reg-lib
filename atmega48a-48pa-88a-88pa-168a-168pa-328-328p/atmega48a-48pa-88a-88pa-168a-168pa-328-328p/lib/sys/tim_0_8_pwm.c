/**********************************************************************************//**
 * 
 * @file	tim_0_8_pwm.c
 *
 * @author	Steven Hulshof
 *
 * @date	01-06-2016
 *
 * @brief	Function for configuring timer 0.
 *
 * This file contains a configuration function of timer 0. Timer 0 can be used in the
 * following modes: normal mode, clear timer on compare match mode, fast PWM mode and 
 * phase correct PWM mode 
 *
 *************************************************************************************/

/**************************************************************************************
 * INCLUDES
 *************************************************************************************/
#include "tim_0_8_pwm.h"

/**************************************************************************************
 * FUNCTION
 *************************************************************************************/
void TIM0_init(tim0_initStructure_t *tim0InitStructure) {
	
	// Reset timer registers
	TCCR0A = 0x00;
	TCCR0B = 0x00;
		
	// Set compare output mode
	TCCR0A |= (tim0InitStructure->compareOutputModeA << COM0A0);
	TCCR0A |= (tim0InitStructure->compareOutputModeB << COM0B0);
		
	// Set waveform generation mode
	TCCR0A |= (tim0InitStructure->waveformMode & 0x03);
	TCCR0B |= ((tim0InitStructure->waveformMode & 0x04) << 1);
		
	// Select clock mode
	TCCR0B |= tim0InitStructure->clockSelectMode;
		
	// Set output compare registers
	OCR0A = tim0InitStructure->outputCompareRegA;
	OCR0B = tim0InitStructure->outputCompareRegB;
}

/* EOF: tim_0_8_pwm.c */