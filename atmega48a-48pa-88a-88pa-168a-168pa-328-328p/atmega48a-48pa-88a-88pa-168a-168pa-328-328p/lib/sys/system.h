/**********************************************************************************//**
 *
 * @file	system.h
 *
 * @author	Steven Hulshof
 *
 * @date	31-05-2016
 *
 * @brief	Contains system definitions.
 *   
 * Describes system includes, typedefs, enums.
 *
 *************************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

/**************************************************************************************
 * INCLUDES
 *************************************************************************************/
#include <stdint.h>
#include <math.h>
#include <avr/io.h>

/**************************************************************************************
 * TYPEDEFS
 *************************************************************************************/
/** @brief	Boolean data type. */
typedef _Bool bool_t;
/** @brief	I/O-register data type. */
typedef volatile uint8_t register8_t;
/** @brief	Output compare value data type 8 bit. */
typedef uint8_t	outputCompare8_t;
/** @brief	Output compare value data type 16 bit. */
typedef uint16_t outputCompare16_t;

/**************************************************************************************
 * ENUMS
 *************************************************************************************/
/** @brief	Boolean true and false. */
enum {
	FALSE	= 0,
	TRUE	= 1	
};

#endif /* SYSTEM_H */
/* EOF: system.h */