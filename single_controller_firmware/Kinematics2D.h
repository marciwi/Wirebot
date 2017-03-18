// We use motor_1 and motor_2 to describe a 2D plane.
// The distance between the two motors is described by their X coordinates and individual heights
//(NOT their Y_values) since we're using them in a wall mounted setup
#ifndef KINEMATICS2D_H
#define KINEMATICS2D_H

#include "config.h"

class Kinematics2D{
	public:
		Kinematics2D();
		void inverse(float posX, float posY, float* wireLength1, float* wireLength2);
	private:

};

#endif //KINEMATICS2D_H
