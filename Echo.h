#ifndef ECHO_H
#define ECHO_H

#include "iProcessor.h"

using namespace std;

/**
/*This class inherits from the iProcessor class to override processBuffer.
/* The Echo Class takes audio and repeats it dealyed with a taper.
/*@param delay, defines how long until the echo begins.
*/
class Echo : public iProcessor {

	int delay;

public:

	///Creates the class constructor.
	Echo();
	/**
	*Constructs Echo with newDelay.
	*@param newDelay, replaces delay.
	*/
	Echo(int newDelay);

	///This function constructs the processBuffer function for echoing 8 bit audio.
	void processBuffer(unsigned char* buffer, int bufferSize);

	///This function constructs the processBuffer function for echoing 16 bit.
	void processBuffer(signed int* buffer, int bufferSize);

	///This function constructs the processBuffer function for echoing 16 bit.
	void processBuffer(signed short* buffer, int bufferSize);

};


#endif
