/**
 * @main.cpp
 *
 * Boilerplate Project for STM32F103C8 as explained on
 * http://www.atakansarioglu.com/stm32-project-from-scratch-on-eclipse/
 *
 * Additional info on STM32F103
 * https://www.st.com/en/microcontrollers/stm32f103.html?querycriteria=productId=LN1565
 *
 */
#include "stm32f10x.h"
#include "stm32f10x_conf.h"

#include "config.h"
#include "ws2812.h"
#include "delay.h"


WS2812_RGB off = {0, 0, 0};
WS2812_RGB base_color = {0, 0, 0};

int32_t anim_temp[4];					// 4 global 32-bit temp variables for animations to use
uint16_t current_animation = 0;
uint32_t animation_counter = 0;

void color_dim(WS2812_RGB * rgb, float factor) {
	rgb->red *= factor;
	rgb->green *= factor;
	rgb->blue *= factor;
	return;
}

// simple dot going aroung the whole strip
// anim_temp[0] is used to remember last dot position
void chasing_dot(void) {
	ws2812_set_all_leds(&off, WS2812_MAX_LEDS, 0);
	if (anim_temp[0] == WS2812_MAX_LEDS) anim_temp[0] = 0;
	ws2812_set_led(anim_temp[0], &base_color);
	anim_temp[0]++;
	return;
}

// same as above, but for all 12 sides simultanously
// anim_temp[0] is used to remember last dot position
void chasing_dot_edge(void) {
	ws2812_set_all_leds(&off, WS2812_MAX_LEDS, 0);
	if (anim_temp[0] == LEDS_PER_EDGE) anim_temp[0] = 0;
	for (uint8_t i = 0; i < NUM_EDGES; i++) {
		ws2812_set_led(anim_temp[0] + i * LEDS_PER_EDGE, &base_color);
	}
	anim_temp[0]++;
	return;
}

// same as first, but with trail that is fading off
// anim_temp[0] is used to remember last dot position
void chasing_dot_trail(void) {
	WS2812_RGB temp_color = base_color;
	ws2812_set_all_leds(&off, WS2812_MAX_LEDS, 0);
	if (anim_temp[0] == WS2812_MAX_LEDS) anim_temp[0] = 0;

	for (uint8_t i = 0; i < 6; i++) {
		if (anim_temp[0] - i < 0) break;
		ws2812_set_led(anim_temp[0] - i, &temp_color);
		color_dim(&temp_color, 0.75);
	}

	anim_temp[0]++;
	return;
}

void full_color_fade(void) {
	ws2812_set_all_leds(&base_color, WS2812_MAX_LEDS, 0);
}

void (*anims[NUM_ANIMS])(void) = {
	full_color_fade,
	chasing_dot_trail,
	chasing_dot_edge,
	//chasing_dot,
};

void init_anim_temps(void) {
	anim_temp[0] = anim_temp[1] = anim_temp[2] = 0;
	return;
}

int main(void) {

	// initialize some stuff
	delay_init(DELAY_RESOLUTION_100_US);				// delay with granularity of 100 us
	ws2812_init();

	// init LED pin PC13
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpio_init;
	gpio_init.GPIO_Pin = GPIO_Pin_13;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio_init);
    //GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);

    ws2812_set_all_leds(&off, WS2812_MAX_LEDS, 1);
	init_anim_temps();

	while(1) {
		// main loop delay for selected FPS
		delay_msec(1000 / FPS);
		animation_counter++;

		if (animation_counter >= ANIM_DURATION * FPS) {
			current_animation++;
			if (current_animation >= NUM_ANIMS) current_animation = 0;
			init_anim_temps();
			ws2812_set_all_leds(&off, WS2812_MAX_LEDS, 1);
			animation_counter = 0;
		}

#if COLOR_FADE == 1
		// anim_temp[3] is used for storing the phase of color fade.
		// initial color fade: red up from black
		// phases: green up, red down, blue up, green down, red up, blue down
		// compare this image: https://i.stack.imgur.com/BE73L.png
		switch (anim_temp[3]) {
			case 0:
				base_color.red += FADE_SPEED;
				if ((int16_t)(base_color.red + FADE_SPEED) > 255) anim_temp[3] = 1;
				break;
			case 1:
				base_color.green += FADE_SPEED;
				if ((int16_t)(base_color.green + FADE_SPEED) > 255) anim_temp[3] = 2;
				break;
			case 2:
				base_color.red -= FADE_SPEED;
				if ((int16_t)(base_color.red - FADE_SPEED) < 0) anim_temp[3] = 3;
				break;
			case 3:
				base_color.blue += FADE_SPEED;
				if ((int16_t)(base_color.blue + FADE_SPEED) > 255) anim_temp[3] = 4;
				break;
			case 4:
				base_color.green -= FADE_SPEED;
				if ((int16_t)(base_color.green - FADE_SPEED) < 0) anim_temp[3] = 5;
				break;
			case 5:
				base_color.red += FADE_SPEED;
				if ((int16_t)(base_color.red + FADE_SPEED) > 255) anim_temp[3] = 6;
				break;
			case 6:
				base_color.blue -= FADE_SPEED;
				if ((int16_t)(base_color.blue - FADE_SPEED) < 0) anim_temp[3] = 1;
				break;
		}
#endif

		// blink LED
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) ? Bit_RESET : Bit_SET);

		anims[current_animation]();
		ws2812_refresh(WS2812_MAX_LEDS);

	}

	return 0;			// end of main
}
