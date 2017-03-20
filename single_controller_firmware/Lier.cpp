/*
This file is part of the Wirebot Software
Copyright (C) Marc Hulscher 2017

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License V3 as published by
the Free Software Foundation.

The software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. In no event shall the
authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising from,
out of or in connection with the software or the use or other dealings in
the software.
*/

#include "Lier.h"

Lier::Lier(uint8_t encoderPin1, uint8_t encoderPin2, int motorEnablePin, int motorIn1, int motorIn2)
:
_encoder(encoderPin1,encoderPin2)
{
	_motor.setupMotor(motorEnablePin,motorIn1,motorIn2);
	_motor.attach();
	_position.posX = 0.0;
	_position.posY = 0.0;
	_position.posZ = 0.0;
	_radius = SPINDLE_RADIUS;
}

uint8_t Lier::setupLier(double* pidInput, double* pidOutput, double* pidSetPoint){
	_pid.setup(0,0,0,PID_KP,PID_KI,PID_KD,DIRECT);		//TODO: the values are just a placeholder for now
	_pidEnable = true;
}

void Lier::setLierPosition(pos3D position){
	_position = position;
}

void Lier::setMotorSpd(int speed){
	_motor.write(speed);
}

int Lier::getCodeCount(){
	return _encoder.read();
}
