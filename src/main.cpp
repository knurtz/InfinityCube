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


int main(void) {

	// initialize everything
	delay_init (DELAY_RESOLUTION_5_US);				// init delay with granularity of 5us
	//ws2812_init();

	// init LED pin PC13
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpio_init;
	gpio_init.GPIO_Pin = GPIO_Pin_13;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;                                       // set as input with internal pulldown
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio_init);

    GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);

    LEDCube main_cube;


    SimpleAnimation foo_animation = SimpleAnimation(&main_cube);


	while(1) {
		// Main Loop Delay für 40 fps
		delay_msec(25);

		GPIO_WriteBit(GPIOC, GPIO_Pin_13, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) ? Bit_RESET : Bit_SET);




		// von aktueller Animationsklasse nextFrame() aufrufen
		foo_animation.next_frame();

		// LEDs refreshen, falls WS2812 nicht im kontinuierlichen Modus läuft


		// nach einiger Zeit: Animationsklasse abwechseln


	}

	return 0;
}
