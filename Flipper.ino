#include "FlashingLight.h"
#include "Sample.h"
#include "PCM.h"

const int NO_SELECTION = -1;

const int GREEN_LIGHT_PIN =		 6;
const int YELLOW_LIGHT_PIN = 	 5;
const int RED_LIGHT_PIN =		 4;

const int GREEN_GATE_PIN =	A0;
const int YELLOW_GATE_PIN =	A1;
const int RED_GATE_PIN =	A2;

const int SPEAKER_PIN =		11;
const int MOTOR_PIN =		 4;

const int GATE_THRESHOLD = 50;
const int SELECTION_DURATION = 900;

int selection = NO_SELECTION;
unsigned long selectionTime;


//--------------------------------------------------------

int gates[] = {GREEN_GATE_PIN, YELLOW_GATE_PIN, RED_GATE_PIN};

FlashingLight	greenLight (GREEN_LIGHT_PIN,  200, 255, 3, 2);
FlashingLight	yellowLight(YELLOW_LIGHT_PIN, 200, 255, 3, 2);
FlashingLight	redLight   (RED_LIGHT_PIN,    200, 255, 3, 2);
FlashingLight	lights[] = {greenLight, yellowLight, redLight};

FlashingLight	greenLightSELECTED (GREEN_LIGHT_PIN,   40, 255, 1, 0);
FlashingLight	yellowLightSELECTED(YELLOW_LIGHT_PIN,  40, 255, 1, 0);
FlashingLight	redLightSELECTED   (RED_LIGHT_PIN,     40, 255, 1, 0);
FlashingLight	lightsSELECTED[] = {greenLightSELECTED, yellowLightSELECTED, redLightSELECTED};

//-------------------------------------------------------

void setup () {
	Serial.begin(9600);

	for (int i=0; i<3; i++) {
		lights[i].init();
		lights[i].turnOn();
	}

	for (int i=0; i<3; i++) {
		lightsSELECTED[i].init();
//		lightsSELECTED[i].turnOn();
	}

	pinMode(GREEN_GATE_PIN,		INPUT); 
	pinMode(YELLOW_GATE_PIN,	INPUT); 
	pinMode(RED_GATE_PIN,		INPUT); 

	pinMode(SPEAKER_PIN,		OUTPUT); 
	pinMode(MOTOR_PIN,			OUTPUT); 
}

int gateStatus() {
	int	result;
	
	result = NO_SELECTION;
	for (int i=0; i<3; i++) {
//		Serial.print("[" + String(i) + "] pin: " + String(gates[i]) + " = " + String(analogRead(gates[i])) + "\n");
		if (analogRead(gates[i]) < GATE_THRESHOLD) {
			result = i;
		}
	}
	
	return result;
}

void turnOnSelection(int selectedIndex) {
//	Serial.print("ON:  " + String(selectedIndex) + "\n");
	for (int i=0; i<3; i++) {
		lights[i].turnOff();
	}
	lightsSELECTED[selectedIndex].turnOn();
}

void playSound() {
	startPlayback(sample, sizeof(sample));
}

void turnOffSelection(int selectedIndex) {
//	Serial.print("OFF: " + String(selectedIndex) + "\n");
	stopPlayback();
	lightsSELECTED[selectedIndex].turnOff();
	for (int i=0; i<3; i++) {
		lights[i].turnOn();
	}
}

void loop () {
	int selectedGate;
	unsigned long now = millis();

	for (int i=0; i<3; i++) {
		lights[i].update();
		lightsSELECTED[i].update();
	}

	if (selection == NO_SELECTION) {
		selectedGate = gateStatus();
		if (selectedGate != selection) {
			selection = selectedGate;
			selectionTime = now;
			turnOnSelection(selectedGate);
			playSound();
		}
	} else if ((now - selectionTime) > SELECTION_DURATION) {
		turnOffSelection(selection);
		selection = NO_SELECTION;
	}
	delay(10);
}

//-------------------------------------------------------

