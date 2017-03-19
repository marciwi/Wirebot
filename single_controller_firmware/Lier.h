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

struct pos3D{
  float posX;
  float posY;
  float posZ;
};

#ifndef Lier_h_
#define Lier_h_

class Lier{
  public:
    Lier();
    int setupLier();
    int moveTo(int count);
    void setPID();  // relate to position or speed
    void update();  // update per timestep or something (observe error & adjust write value)
  private:
    // one PID element
    // PID _pid;
    // one GearMotor
    GearMotor _motor;
    // one Encoder
    Encoder _encoder;
    // position of the Lier
    pos3D _position;
    // spindle radius
    float _radius;
};

#endif //Lier_h_
