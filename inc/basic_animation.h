/*
 * BasicAnimation
 * ========
 * This class describes abasic animation class that all other animations should build on.
 * It only defines the basic structure, so the main program can handle all different animation types the same way.
 */


#ifndef BASIC_ANIMATION_H
#define BASIC_ANIMATION_H

#include "cube.h"


class BasicAnimation {

public:
	BasicAnimation(LEDCube* cube);
	void reset();
	void next_frame();
	void set_current_frame(int number);
	int get_current_frame();

protected:
	LEDCube* cube_;
	int current_frame_;
};


#endif		// BASIC_ANIMATION_H
