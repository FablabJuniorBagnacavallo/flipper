#include "Period.h"

Period::Period() {}

void Period::init(int duration) {
	_duration = duration;
	__startTime = millis();
	__status = false;
}

void Period::update() {
	unsigned long now = millis();
	
	if ((now - __startTime) > _duration) {
		__status = !__status;
	}
}

boolean Period::status() {
	return __status;
}

