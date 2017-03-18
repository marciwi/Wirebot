
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/******************************************************************************/
// PIN SETTINGS
#define MOTOR_1_IN1     1
#define MOTOR_1_IN2     2
#define MOTOR_1_EN      3
#define MOTOR_1_ENC1    5
#define MOTOR_1_ENC2    6

/******************************************************************************/
//MOTOR SETTINGS

#define INVERT_MOTOR_1 FALSE
#define INVERT_MOTOR_2 FALSE
#define INVERT_MOTOR_3 FALSE
#define INVERT_MOTOR_4 FALSE

#define SPINDLE_RADIUS 0.01	//METER

/******************************************************************************/
//ENVIRONMENT SETTINGS

// we set up the room in a cartesian system with the (0x,0y,0z) position below
// motor_1 at floor level
#define MOTOR_1_HEIGHT	2.0 //METER

#define MOTOR_2_HEIGHT	2.0 //METER
#define MOTOR_2_X		2.0 //METER
#define MOTOR_2_Y		2.0 //METER

// (not used for 2D kinematics)
#define MOTOR_3_HEIGHT	2.0 //METER
#define MOTOR_3_X		2.0 //METER
#define MOTOR_3_Y		2.0 //METER

// (not used for 2D kinematics)
#define MOTOR_4_HEIGHT	2.0 //METER
#define MOTOR_4_X		2.0 //METER
#define MOTOR_4_Y		2.0 //METER

#define CARRIAGE_X_L	0.05//METER
#define CARRIAGE_Y_L	0.05//METER (not used for 2D kinematics)

#endif // CONFIGURATION_H
