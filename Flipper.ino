#include "FlashingLight.h"

FlashingLight	greenLight ( 8,  100,  700, 3, 1);
FlashingLight	yellowLight( 7,  100,  500, 3, 1);
FlashingLight	redLight   ( 6,  100,  700, 3, 1);

//-------------------------------------------------------

void setup () {
	Serial.begin(9600);

	greenLight.init();
	greenLight.turnOn();
	
	yellowLight.init();
	yellowLight.turnOn();

	redLight.init();
	redLight.turnOn();

}

void loop () {
	greenLight.update();
	yellowLight.update();
	redLight.update();

	delay(100);
}

//-------------------------------------------------------
