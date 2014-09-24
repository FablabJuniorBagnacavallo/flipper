#include "Period.h"

Period::Period() {}

void Period::init(int duration) {
	_duration = duration;
	__startTime = millis();
	__status = false;
	__cycle = 0;
}

void Period::update() {
	unsigned long now = millis();
	
	if ((now - __startTime) > _duration) {
		__status = !__status;
		__startTime = now;
		if (__status) {
			__cycle ++;
		}
	}
}

boolean Period::status() {
	return __status;
}

int Period::cycle() {
	return __cycle;
}

