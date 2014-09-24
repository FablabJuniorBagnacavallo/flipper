#ifndef Period_h
#define Period_h
#include <Arduino.h>

class Period {
	public:
		Period();
		void init(int duration);
		void update();
		boolean status();
		int cycle();

	private:
		int	_duration;
		int	__cycle;

		boolean	__status;
		unsigned long	__startTime;
	};

#endif
