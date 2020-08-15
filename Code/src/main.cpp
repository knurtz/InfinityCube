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

#include "basic_animation.h"
#include "animations.h"

//LEDCube main_cube;
//SimpleAnimation foo_animation = SimpleAnimation(&main_cube);

WS2812_RGB off = {0, 0, 0};
WS2812_RGB red = {255, 0, 0};
WS2812_RGB light_blue = {50, 50, 255};

int main(void) {

	// initialize some stuff
	delay_init(DELAY_RESOLUTION_10_US);				// delay with granularity of 10 us
	ws2812_init();

	// init LED pin PC13
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpio_init;
	gpio_init.GPIO_Pin = GPIO_Pin_13;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;                                       // set as input with internal pulldown
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio_init);

    GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);

    ws2812_set_all_leds(&off, WS2812_MAX_LEDS, true);
    int current_led = 0;

	while(1) {
		// Main Loop Delay für 40 fps
		delay_msec(100);

		// blink LED
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) ? Bit_RESET : Bit_SET);


		// von aktueller Animationsklasse nextFrame() aufrufen
		//foo_animation.next_frame();

		// LEDs refreshen
		current_led++;
		if (current_led == WS2812_MAX_LEDS) current_led = 0;

		ws2812_set_led(current_led, &light_blue);

		ws2812_refresh(WS2812_MAX_LEDS);

		ws2812_set_led(current_led, &off);

	}

	return 0;
}
