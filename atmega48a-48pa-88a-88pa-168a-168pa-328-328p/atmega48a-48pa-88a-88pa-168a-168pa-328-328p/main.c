/**************************************************************************************
 *
 * @file	main.c
 *
 * @author	Steven Hulshof
 *
 * @date	31-05-2016
 *
 * @brief	Main test program for atmega libs.
 *   
 *************************************************************************************/

#include "lib/sys/io_ports.h"
#include "lib/sys/tim_0_8_pwm.h"

int main(void) {

	io_initStructure_t ioInitStructure = {
		.pin	= IO_PIN_3,
		.PORT	= &PORTC,
		.mode	= IO_MODE_OUTPUT
	}; IO_init(&ioInitStructure);
	
	tim0_initStructure_t tim0InitStructure = {
		.clockSelectMode = TIM0_CS_CLK_DIV_1024,
		.compareOutputModeA = TIM0_CO_CLEAR_ON_COMPARE_MATCH,
		.waveformMode = TIM0_WF_CTC_OCR0A,
		.outputCompareRegA = 0xFF
	}; TIM0_init(&tim0InitStructure);

    while(TRUE);
}

