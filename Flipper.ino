#include "FlashingLight.h"

FlashingLight	greenLight (11,  200, 55, 3, 2);
FlashingLight	yellowLight(10,  200, 55, 3, 2);
FlashingLight	redLight   ( 9,  200, 55, 3, 2);


FlashingLight	greenLightSELECTED (11,   40, 255, 1, 0);
FlashingLight	yellowLightSELECTED(10,   40, 255, 1, 0);
FlashingLight	redLightSELECTED   ( 9,   40, 255, 1, 0);

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

	delay(10);
}

//-------------------------------------------------------
