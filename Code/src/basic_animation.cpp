/*
 * BasicAnimation
 * ========
 * This class describes abasic animation class that all other animations should build on.
 * It only defines the basic structure, so the main program can handle all different animation types the same way.
 */

#include <basic_animation.h>

BasicAnimation::BasicAnimation(LEDCube* cube) {

	cube_ = cube;
	current_frame_ = 0;
}

void BasicAnimation::reset() {
	set_current_frame(0);
}

void BasicAnimation::next_frame() {
	set_current_frame(current_frame_++);
}

void BasicAnimation::set_current_frame(int number) {
	current_frame_ = number;
}

int BasicAnimation::get_current_frame() {
	return current_frame_;
}
