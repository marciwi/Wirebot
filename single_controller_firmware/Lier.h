
#include "Encoder.h"
#include "GearMotor.h"

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
    float radius;
};

#endif //Lier_h_
