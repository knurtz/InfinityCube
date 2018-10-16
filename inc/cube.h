/*
 * LED Cube
 * ========
 * This class describes a WS2812 cube.
 *
 * kriegt Anzahl LEDs, Offset und Richtung pro Kante
 * Funktionen:
 * setPixel(side, number, colorRGB);
 * setSide(side, colorRGB);
 * setAll(colorRGB);
 *
 */


#ifndef CUBE_H
#define CUBE_H

#include "ws2812.h"


class LEDCube {

public:
	LEDCube();

	void refresh();
	void setOne(uint8_t side, uint8_t number, WS2812_RGB* color);
	void setSide(uint8_t side, WS2812_RGB* color);
	void setAll(WS2812_RGB* color);

private:


};

#endif		// CUBE_H
