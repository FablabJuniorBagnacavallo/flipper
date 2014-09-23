#ifndef FlashingLight_h
#define FlashingLight_h

class FlashingLight {
	public:
		FlashingLight(int pin, int intensity, int flashingTime, int activePeriods, int skipPeriods);
		void init();

	private:
		int	_pin;
		int	_intensity;
		int	_flashingTime;
		int	_activePeriods;
		int	_skipPeriods;
		
};

#endif
