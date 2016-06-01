/**********************************************************************************//**
 * 
 * @file	io_ports.h
 *
 * @author	Steven Hulshof
 *
 * @date	31-05-2016
 *
 * @brief	Functions for manipulating I/O-ports.
 *
 * This file contains functions to manipulate the I/O-ports of the ATmega. 
 * Configure the I/O-ports with the ioInitStructure to set I/O-port usage. I/O-pins
 * can be set, reset, toggled and read. 
 *
 * @code{.c}
 * #include <util/delay.h>
 * #include "lib/sys/io_ports.h"
 *
 * // Led output on PORTC
 * const ioPin_t ledR = IO_PIN_3;
 * const ioPin_t ledG = IO_PIN_4;
 * 
 * // Button input on PORTB
 * const ioPin_t button = IO_PIN_4;
 *
 * int main(void) {
 *
 *	ioInitStructure_t output = {
 *		.pin	= ledR | ledG,
 *		.port	= &PORTC, 
 *		.mode	= IO_MODE_OUTPUT
 *	}; IO_init(&output);
 *
 *	ioInitStructure_t input = {
 *		.pin	= button,
 *		.port	= &PORTB,
 *		.mode	= IO_MODE_INPUT
 *	}; IO_init(&button);
 * 
 *	while(TRUE) {
 *		 
 *		if(IO_readBit(&input.port, button) == TRUE) {
 *			IO_resetBit(&output.port, ledR);
 *			IO_setBit(&output.port, ledG);
 *		} else {
 *			IO_setBit(&output.port, ledR);
 *			IO_resetBit(&output.port, ledG);
 *		}
 *	}
 * }	 
 * @endcode  
 *************************************************************************************/

#ifndef IO_PORTS_H_
#define IO_PORTS_H_

/**************************************************************************************
 * INCLUDES
 *************************************************************************************/
#include "system.h"

/**************************************************************************************
 * TYPEDEFS
 *************************************************************************************/
/** @brief	I/O-pin data type. */
typedef uint8_t	ioPin8_t;
/** @brief	I/O-mode data type. */
typedef uint8_t	ioMode8_t;
/** @brief	I/O-register data type. */
typedef volatile uint8_t ioRegister8_t;

/**************************************************************************************
 * ENUMS
 *************************************************************************************/
/** @brief	I/O-port pins. */
enum {
	IO_PIN_0 = 0x01,	
	IO_PIN_1 = 0x02,
	IO_PIN_2 = 0x04,
	IO_PIN_3 = 0x08,
	IO_PIN_4 = 0x10,
	IO_PIN_5 = 0x20,
	IO_PIN_6 = 0x40,
	IO_PIN_7 = 0x80,
};

/** @brief	I/O-pin modes. */
enum {
	IO_MODE_INPUT	= 0x00,
	IO_MODE_OUTPUT	= 0x01,
	IO_MODE_HI_Z	= 0x02
};

/**************************************************************************************
 * DATA STRUCTURES
 *************************************************************************************/
/** @brief	I/O initialization structure */
typedef struct {
	/** @brief	I/O-pin number. */
	ioPin8_t	pin;
	/** @brief	I/O-pin mode. */
	ioMode8_t mode;
	/** @brief	Pointer to the I/O-PORT register. */
	ioRegister8_t *PORT;	
} ioInitStructure_t;

/**************************************************************************************
 * FUNCTION PROTOTYPES
 *************************************************************************************/
/**
 * @brief	I/O-ports initialization.
 *
 * Initializes DDR, PIN and PORT registers to the specified configuration.
 *
 * @param	ioInitStructure	Pointer to I/O-ports initialization structure.
 */
void IO_init(ioInitStructure_t *ioInitStructure);

/**
 * @brief	Set I/O-pin high.
 *
 * Set pin bit in PORT register to 1. Resulting in a 1 on the I/O-pin.
 *
 * @param	PORT	Pointer to the I/O-PORT register.
 * @param	pin		I/O-pin number.
 */
void IO_setBit(ioRegister8_t *PORT, ioPin8_t pin);

/**
 * @brief	Set I/O-pin low.
 *
 * Set pin bit in PORT register to 0. Resulting in a 0 on the I/O-pin.
 *
 * @param	PORT	Pointer to the I/O-PORT register.
 * @param	pin		I/O-pin number.
 */
void IO_resetBit(ioRegister8_t *PORT, ioPin8_t pin);

/**
 * @brief	Toggle I/O-pin.
 *
 * Write 1 to PIN register. Resulting in a toggle on the I/O-pin.
 *
 * @param	PORT	Pointer to the I/O-PORT register.
 * @param	pin		I/O-pin number.
 */
void IO_toggleBit(ioRegister8_t *PORT, ioPin8_t pin);

/**
 * @brief	Read I/O-pin.
 *
 * Read PIN register. Resulting in a pin read out. Returns 1 or 0.
 *
 * @param	PORT	Pointer to the I/O-PORT register.
 * @param	pin		I/O-pin number.
 *
 * @return	State of the I/O-pin.
 */
bool_t IO_readBit(ioRegister8_t *PORT, ioPin8_t pin);

#endif /* IO_PORTS_H_ */
/* EOF: io_ports.h */