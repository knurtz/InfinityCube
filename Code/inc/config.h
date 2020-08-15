/*
 * Config file for Infinity Cube project
 *
 */


#ifndef CONFIG_H
#define CONFIG_H

#define LEDS_PER_EDGE				9									// 9 LEDs per edge
#define NUM_EDGES                   12
#define WS2812_MAX_LEDS             ((NUM_EDGES) * (LEDS_PER_EDGE))				// 12 edges

#define NUM_ANIMS                   3
#define ANIM_DURATION               20              // in s
#define FPS                         30              // in Hz

#define COLOR_FADE                  1
#define FADE_SPEED                  2

#endif
