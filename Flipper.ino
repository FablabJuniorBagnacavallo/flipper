const int greenGate = 3;
const int yellowGate = 4;
const int redGate = 5;
const int exitGate = 6;

const int greenLight = 10;
const int yellowLight = 11;
const int redLight = 12;
const int exitMotor = 13;
const int speaker = 14;

//--------------------

const int OFF = 0;
const int ON = 1;

int regularFlashInterval = 100;
int regularFlashIntensity = 50;
int regularFlashStatus = OFF;

int selectedFlashInterval = 10;
int selectedFlashIntensity = 100;
int selectedFlashStatus = OFF;

int	selectedGate;

const int NO_GATE =	-1;
const int GREEN =	 0;
const int YELLOW =	 1;
const int RED =		 2;

unsigned long selectedGateTime;
unsigned long latestLightSwitch;
unsigned long time;

//-------------------------------------------------------

void turnLight (int port, int status) {

}

void flashLights(unsigned long currentTime) {
	if (selectedGate == NO_GATE) {
		if ((currentTime - latestLightSwitch) > regularFlashInterval) {
			if (regularFlashStatus = OFF) {
				regularFlashStatus = ON;	
			} else {
				regularFlashStatus = OFF;	
			}
			
			turnLight(greenLight,	regularFlashStatus);
			turnLight(yellowLight,	regularFlashStatus);
			turnLight(redLight,		regularFlashStatus);
			latestLightSwitch = currentTime;
		}
	}
}

void flashLight (int light, unsigned long currentTime) {
	if ((currentTime - latestLightSwitch) > selectedFlashInterval) {
		if (selectedFlashStatus = OFF) {
			selectedFlashStatus = ON;	
		} else {
			selectedFlashStatus = OFF;	
		}
		
		turnLight(lightPort(light),	selectedFlashStatus);
		latestLightSwitch = currentTime;
	}
}

int checkGates () {
	int	result;

	if (selectedGate == NO_GATE) {
		result = 1;
	} else {
		result = selectedGate;
	}
	
	return result;
}

//-------------------------------------------------------

void setup () {
	selectedGate = NO_GATE;
	selectedGateTime = 0;
	latestLightSwitch = 0;

	pinMode(greenGate,		INPUT);
	pinMode(yellowGate,		INPUT);
	pinMode(redGate,		INPUT);
	pinMode(exitGate,		INPUT);
	
	pinMode(greenLight,		OUTPUT);
	pinMode(yellowLight,	OUTPUT);
	pinMode(redLight,		OUTPUT);
	pinMode(exitMotor,		OUTPUT);
	pinMode(speaker,		OUTPUT);
}

void loop () {
	time = millis();

	flashLights(time);
	selectedGate = checkGates();
	if (selectedGate != NO_GATE) {
		flashLight(selectedGate, time);
	}
	
}

//-------------------------------------------------------
