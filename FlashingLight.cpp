#include "FlashingLight.h"

FlashingLight::FlashingLight(int pin, int intensity, int flashingTime, int activePeriods, int skipPeriods) {
	_pin = pin;
	_intensity = intensity;
	_flashingTime = flashingTime;
	_activePeriods = activePeriods;
	_skipPeriods = skipPeriods;
}

void FlashingLight::init() {
}