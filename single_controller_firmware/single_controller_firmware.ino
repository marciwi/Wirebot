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

#include "config.h"
#include "Lier.h"

// Setup the Lier object(s)
Lier lier1(MOTOR_1_ENC1,MOTOR_1_ENC2,MOTOR_1_EN,MOTOR_1_IN1,MOTOR_1_IN2);

void setup() {
	//  Serial.begin(9600);
	Serial.begin(19200);
	delay(500);
	Serial.println("ready");

	// lier1.setupLier();
}


void loop() {
	// Inout handler
	// TODO: make an actual inputhandler
	if (Serial.available()){
		char c = Serial.read();
		//Serial.print(c);
		if(c=='u'){
		  //Serial.print('hey'); //prints: 6841721
		  //Serial.print("hey"); //prints: hey
			lier1.setMotorSpd(255);
		} else if (c=='s'){
			lier1.setMotorSpd(0);
		} else if (c=='d'){
			lier1.setMotorSpd(-200);
		} else if (c=='r'){
			lier1.getCodeCount();
		}
  	}

	// Determine motor commands
	lier1.update();

	lier1.setCount(0);
	bool test=true;
	while(test){
		lier1.moveTo(1000);
		if(lier1.getCodeCount()>=1000){
			test=false;
		}
		lier1.update();
		delay(100);
	}

	//
	delay(100);
}
