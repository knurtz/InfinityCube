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

// neue Klasse: LEDCube
// kriegt LEDBuffer, LEDs, Offset und Richtung pro Kante
// Funktionen:
// setPixel(side, number, colorRGB);
// setSide(side, colorRGB);
// setAll(colorRGB);

// neue Klasse: SimpleAnimation
// kriegt LEDCube
// Funktionen:
// nextFrame(); -> geht alle Seiten des Würfels durch und setzt der Reihe nach einen Pixel

// weitere Animationsklassen


void main(void) {

	// initialize everything
	delay_init (DELAY_RESOLUTION_5_US);				// init delay with granularity of 5us
	ws2812_init();

	while(1) {
		// Main Loop Delay für 40 fps


		// von aktueller Animationsklasse nextFrame() aufrufen


		// LEDs refreshen, falls WS2812 nicht im kontinuierlichen Modus läuft


		// nach einiger Zeit: Animationsklasse abwechseln

	}
}
