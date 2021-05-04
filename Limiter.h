#ifndef LIMITER_H
#define LIMITER_H

#include "iProcessor.h"

using namespace std;

/**
/*This class inherits from the iProcessor class to override processBuffer.
/* The Limiter Class takes audio and caps loudness to a certain volume.
/*@param lim, a percentage value, used to find the limit in 8 or 16 bit.
*/
class Limiter : public iProcessor {

	int lim;

public:

	///Creates the class constructor.
	Limiter();
	/**Constructs Limiter.
	*@param newLim, replaces lim.
	*/
	Limiter(int newLim);

	///This function constructs the processBuffer function for limiting 8 bit audio.
	void processBuffer(unsigned char* buffer, int bufferSize);

	///This function constructs the processBuffer function for limiting 16 bit.
	void processBuffer(signed int* buffer, int bufferSize);

	///This function constructs the processBuffer function for limiting 16 bit.
	void processBuffer(signed short* buffer, int bufferSize);

};


#endif
