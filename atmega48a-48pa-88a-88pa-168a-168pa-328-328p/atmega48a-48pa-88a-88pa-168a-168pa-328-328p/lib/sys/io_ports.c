/**********************************************************************************//**
 *
 * @file	io_ports.c
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
 *************************************************************************************/

/**************************************************************************************
 * INCLUDES
 *************************************************************************************/
#include "io_ports.h"

/**************************************************************************************
 * FUNCTION
 *************************************************************************************/
void IO_init(ioInitStructure_t *ioInitStructure) {
	
	// Locate DDR register.
	ioRegister8_t *DDR = ioInitStructure->PORT-1;
		
	// Reset bit values.
	*DDR &= ~ioInitStructure->pin;
	*ioInitStructure->PORT &= ~ioInitStructure->pin;
		
	// Exit function on High Impedance.
	if(ioInitStructure->mode == IO_MODE_HI_Z)
		return;
		
	// Set pin mode.
	*DDR |= ioInitStructure->pin * ioInitStructure->mode;
	*ioInitStructure->PORT |=	ioInitStructure->pin * 
								((~ioInitStructure->mode) & 0x01);
}

void IO_setBit(ioRegister8_t *PORT, ioPin8_t pin) {
	
	// Set bit.
	*PORT |= pin;
}

void IO_resetBit(ioRegister8_t *PORT, ioPin8_t pin) {
	
	// Reset bit.
	*PORT &= ~pin;
}

void IO_toggleBit(ioRegister8_t *PORT, ioPin8_t pin) {
	
	// Locate PIN register.
	ioRegister8_t *PIN = PORT-2;
	
	// Toggle bit.
	*PIN |= pin;
}

bool_t IO_readBit(ioRegister8_t *PORT, ioPin8_t pin) {
	
	// Locate PIN register.
	ioRegister8_t *PIN = PORT-2;
	
	// Read bit value.
	bool_t bitValue = (bool_t) (*PIN >> (uint8_t)(log10(pin)/log10(2))) & 0x01;

	return bitValue;
}
/* EOF: io_ports.c */