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

/**************************************************************************************
 * ENUMS
 *************************************************************************************/
/** @brief	Boolean true and false. */
enum {
	FALSE =	(bool_t)	0,
	TRUE =	(bool_t)	1	
};

#endif /* SYSTEM_H */
/* EOF: system.h */