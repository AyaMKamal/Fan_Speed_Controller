/************************************************************************************************
 * MODULE :  DC_MOTOR
 *
 * FILE : DC_MOTOR.h
 *
 * AUTHOR : Aya Mohamed
 **************************************************************************************************/


#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"


/*************************************** types declaration*********************************************************/
typedef enum{
	STOP,CW,A_CW
}DC_MOTOR_STATE;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
description :
initialization of motor by setting pins directions and stop it at the beginig
*/
void DCmotor_init(void);
/*
description :
function responsible for rotating the motor CW or A_CW or stop it based on the state input
and to send the duty cycle value to the PWM driver based on the required speed value*/


void DCmotor_Rotate(DC_MOTOR_STATE state, uint8 speed);


#endif /* MOTOR_H_ */
