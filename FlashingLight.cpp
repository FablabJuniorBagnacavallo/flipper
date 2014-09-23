#include "FlashingLight.h"
#include <Arduino.h>
#include "const.h"

FlashingLight::FlashingLight(int pin, int intensity, int flashingTime, int activePeriods, int skipPeriods) {
	_pin = pin;
	_intensity = intensity;
	_flashingTime = flashingTime;
	_activePeriods = activePeriods;
	_skipPeriods = skipPeriods;
	
	__onOffPeriod = Period();
	__intensityPeriod = Period();
}

//void FlashingLight::togglePeriod() {
//	__periodStatus = !__periodStatus;
//	updateLight();
//}

void FlashingLight::init() {
	pinMode(_pin, OUTPUT);
	__status = OFF;

	__onOffPeriod.init(_flashingTime);
	__intensityPeriod.init(_intensity);
}

void FlashingLight::update() {
//	Serial.print("update\n");
	__onOffPeriod.update();
	__intensityPeriod.update();

	Serial.print(String(String(__status) + " - " + String(__onOffPeriod.status()) + " - " + String(__intensityPeriod.status()) + "\n"));
	if (__status && __onOffPeriod.status() && __intensityPeriod.status()) {
		updateLight(HIGH);
	} else {
		updateLight(LOW);
	}
}

void FlashingLight::updateLight(int status) {
	digitalWrite(_pin, status);
}

void FlashingLight::turnOn() {
	__status = true;
	__periodCount = 0;
	__startTime = millis();
	update();
};

void FlashingLight::turnOff() {
	__status = OFF;
	update();
};
