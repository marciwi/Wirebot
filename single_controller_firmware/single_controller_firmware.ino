/*******************************************************************************
 *  This code is part of the Lier3D software

*******************************************************************************/

#include "config.h"
#include "Lier.h"

// Setup an instance of Encoder and the GearMotor
Encoder   enc1(MOTOR_1_ENC1,MOTOR_1_ENC2);
GearMotor moto1;

void setup() {
//  Serial.begin(9600);
  Serial.begin(19200);
  delay(500);
  Serial.println("ready");
  moto1.setupMotor(MOTOR_1_EN,MOTOR_1_IN1,MOTOR_1_IN2);
  // moto.setupMotor(MOTOR_2_EN,MOTOR_2_IN1,MOTOR_2_IN2);
  // moto.setupMotor(MOTOR_3_EN,MOTOR_3_IN1,MOTOR_3_IN2);
  // moto.setupMotor(MOTOR_4_EN,MOTOR_4_IN1,MOTOR_4_IN2);
  moto1.attach();
}

void loop() {
// put your main code here, to run repeatedly:
//  Serial.println(enc.read());

  if (Serial.available()){
    char c = Serial.read();
    //Serial.print(c);
    if(c=='u'){
      //Serial.print('hey'); //prints: 6841721
      //Serial.print("hey"); //prints: hey
      moto1.write(255);
    } else if (c=='s'){
      moto1.write(0);
    } else if (c=='d'){
      moto1.write(-200);
    } else if (c=='r'){
      enc1.read();
    }
  }
  delay(100);
}
