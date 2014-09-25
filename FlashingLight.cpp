#include "FlashingLight.h"
#include <Arduino.h>

FlashingLight::FlashingLight(int pin, int flashingTime, int intensity, int activePeriods, int skipPeriods) {
	_pin = pin;
	_intensity = intensity;
	_flashingTime = flashingTime;
	_activePeriods = activePeriods;
	_skipPeriods = skipPeriods;
	__latestValueSet = 0;
}

//void FlashingLight::togglePeriod() {
//	__periodStatus = !__periodStatus;
//	updateLight();
//}

void FlashingLight::init() {
	pinMode(_pin, OUTPUT);
	__status = false;

	__onOffPeriod = Period();
	__onOffPeriod.init(_flashingTime);
}

boolean FlashingLight::isActiveCycle(int cycle) {
	int step;
	
	step = cycle % (_activePeriods + _skipPeriods);
	return (step < _activePeriods);
}

void FlashingLight::updateLight(int value) {
	if (__latestValueSet != value) {
		__latestValueSet = value;
		analogWrite(_pin, value);
	}
}

void FlashingLight::update() {
//	Serial.print("update\n");
	__onOffPeriod.update();

	if (__status && __onOffPeriod.status() && isActiveCycle(__onOffPeriod.cycle())) {
		updateLight(_intensity);
	} else {
		updateLight(0);
	}
}

void FlashingLight::turnOn() {
	__status = true;
	update();
};

void FlashingLight::turnOff() {
	__status = false;
	update();
};
