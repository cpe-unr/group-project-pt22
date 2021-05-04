//Alex Czarnomski
//CS 202
//5/4/21

#ifndef NORMALIZER_H
#define NORMALIZER_H

#include "iProcessor.h"

using namespace std;

/**
/*This class inherits from the iProcessor class to override processBuffer.
/* The Normalizer Class takes audio and makes all of it louder by the same degree.
/*@param nPercent, the percent of loudness that the maximum peak is compared to.
*/
class Normalizer : public iProcessor {

	int nPercent;

public:

	///Creates the class constructor.
	Normalizer();
	/**Constructs Normalizer.
	*@param newNPercent, replaces nPercent.
	*/
	Normalizer(int newNPercent);

	///This function constructs the processBuffer function for an 8 bit Normalization.
	void processBuffer(unsigned char* buffer, int bufferSize);

	///This function constructs the processBuffer function for a 16 bit Normalization.
	void processBuffer(signed int* buffer, int bufferSize);

	///This function constructs the processBuffer function for a 16 bit Normalization.
	void processBuffer(signed short* buffer, int bufferSize);

};


#endif
