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

#include "Encoder.h"
#include "GearMotor.h"
#include "PID_v1.h"
#include "config.h"

struct pos3D{
  float posX;
  float posY;
  float posZ;
  // pos3D(float x, float y, float z) : posX(x), posY(y), posZ(z) {}
};

#ifndef Lier_h_
#define Lier_h_

class Lier{
  public:
    Lier(uint8_t encoderPin1, uint8_t encoderPin2, int motorEnablePin, int motorIn1, int motorIn2);
    uint8_t setupLier();    //TODO
    void setLierPosition(pos3D position);
    void moveTo(int count);  //TODO
    void setCount(int count);
    int diffTo(int count);  //TODO? or remove
    void setMotorSpd(int speed);
    int getCodeCount();
    void setPID();  // relate to position or speed
    void update();  // update per timestep or something (observe error & adjust write value)
  private:
    PID _pid;
    GearMotor _motor;
    Encoder _encoder;
    pos3D   _position;              // position of the Lier
    float   _radius;                // spindle radius
    bool    _pidEnable = false;     // use PID or not
    double  _pidSetPoint, _pidInput, _pidOutput;
};

#endif //Lier_h_
