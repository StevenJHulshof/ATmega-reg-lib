/**********************************************************************************//**
 * 
 * @file	tim_0_8_pwm.h
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
 * @code{.c}
 *
 * @endcode  
 *
 *************************************************************************************/

#ifndef TIM_0_8_PWM_H_
#define TIM_0_8_PWM_H_

/**************************************************************************************
 * INCLUDES
 *************************************************************************************/
#include "system.h"

/**************************************************************************************
 * TYPEDEF ENUMS
 *************************************************************************************/
/** @brief Specifies waveform generation mode of timer 0 */
typedef enum {
	TIM0_WF_NORMAL			= 0x00,
	TIM0_WF_PWM_PC_8BIT		= 0x01,
	TIM0_WF_CTC_OCR0A		= 0x02,
	TIM0_WF_PWM_FAST_8BIT	= 0x03,
	TIM0_WF_PWM_PC_OCR0A	= 0x05,
	TIM0_WF_PWM_FAST_OCR0A	= 0x07
} tim0_waveformMode8_t;

/** @brief Specifies compare output mode of timer 0 */
typedef enum {
	TIM0_CO_NORMAL_PORT_OPERATION	= 0x00,
	TIM0_CO_TOGGLE_ON_COMPARE_MATCH = 0x01,
	TIM0_CO_CLEAR_ON_COMPARE_MATCH	= 0x02,
	TIM0_CO_SET_ON_COMPARE_MATCH	= 0x03
} tim0_compareOutputMode8_t;

/** @brief Specifies the selected clock of timer 0 */
typedef enum {
	TIM0_CS_NO_CLK_SOURCE		= 0x00,
	TIM0_CS_CLK_DIV_1			= 0x01,
	TIM0_CS_CLK_DIV_8			= 0x02,
	TIM0_CS_CLK_DIV_64			= 0x03,
	TIM0_CS_CLK_DIV_256			= 0x04,
	TIM0_CS_CLK_DIV_1024		= 0x05,
	TIM0_CS_EXT_CLK_FALLING_T0	= 0x06,
	TIM0_CS_EXT_CLK_RISING_T0	= 0x07
} tim0_clockSelectMode8_t;

/**************************************************************************************
 * DATA STRUCTURES
 *************************************************************************************/
/** @brief Structure containing data for configuring timer 0 */
typedef struct {
	/** @brief Waveform generation mode */
	tim0_waveformMode8_t waveformMode;	
	/** @brief Compare output mode for register A */
	tim0_compareOutputMode8_t compareOutputModeA;	
	/** @brief Compare output mode for register B */
	tim0_compareOutputMode8_t compareOutputModeB;	
	/** @brief Clock selection */
	tim0_clockSelectMode8_t clockSelectMode;	
	/** @brief Output compare register A */
	outputCompare8_t outputCompareRegA;	
	/** @brief Output compare register B */
	outputCompare8_t outputCompareRegB;
} tim0_initStructure_t;

/**************************************************************************************
 * FUNCTION PROTOTYPES
 *************************************************************************************/
void TIM0_init(tim0_initStructure_t *tim0InitStructure);

#endif /* TIM_0_8_PWM_H_ */
/* EOF: tim_0_8_pwm.h */