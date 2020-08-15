#ifndef ANIMATIONS_H
#define ANIMATIONS_H


#include "basic_animation.h"


class SimpleAnimation : public BasicAnimation {

public:
	SimpleAnimation(LEDCube* cube);
	void set_current_frame(int number);
};


#endif		// ANIMATIONS_H
