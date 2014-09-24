#ifndef FlashingLight_h
#define FlashingLight_h
#include "Period.h"

class FlashingLight {
	public:
		FlashingLight(int pin, int flashingTime, int intensity, int activePeriods, int skipPeriods);
		void init();
		void turnOn();
		void turnOff();
		void update();

	private:
		int	_pin;
		int	_intensity;
		int	_flashingTime;
		int	_activePeriods;
		int	_skipPeriods;

		int	__periodCount;
		int	__startTime;
		int	__startPeriod;
		boolean	__status;

		int	__periodStatus;
		int	__periodStartTime;
		int	__latestValueSet;

		void updateLight(int value);
		boolean isActiveCycle(int cycle);
		Period	__onOffPeriod;
};

#endif
