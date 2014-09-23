#ifndef Period_h
#define Period_h
#include <Arduino.h>

class Period {
	public:
		Period();
		void init(int duration);
		void update();
		boolean status();

	private:
		int	_duration;

		boolean	__status;
		unsigned long	__startTime;
	};

#endif
