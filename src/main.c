/**
 * @main.c
 *
 * Boilerplate Project for STM32F103C8 as explained on
 * http://www.atakansarioglu.com/stm32-project-from-scratch-on-eclipse/
 *
 * Additional info on STM32F103
 * https://www.st.com/en/microcontrollers/stm32f103.html?querycriteria=productId=LN1565
 *
 */

#include "ws2812.h"
#include "delay.h"


void main(void) {

	delay_init (DELAY_RESOLUTION_5_US);				// init delay with granularity of 5us
	ws2812_init();
}
