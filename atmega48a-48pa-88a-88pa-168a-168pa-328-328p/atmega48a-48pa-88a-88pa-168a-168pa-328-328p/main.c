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

#define F_CPU 16000000UL

#include <util/delay.h>
#include "lib/sys/io_ports.h"

int main(void) {

	ioInitStructure_t ioInitStructure = {
		.pin	= IO_PIN_3,
		.PORT	= &PORTC,
		.mode	= IO_MODE_OUTPUT
	}; IO_init(&ioInitStructure);

    while(TRUE) {
		
		IO_toggleBit(&PORTC, IO_PIN_3);
		_delay_ms(1000);
	}
}

