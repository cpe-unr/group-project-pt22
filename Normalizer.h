#ifndef NORMALIZER_H
#define NORMALIZER_H

#include "iProcessor.h"

using namespace std;

class Normalizer : public iProcessor {

	int nPercent;

public:

	Normalizer();
	Normalizer(int nPercent);

	void processBuffer(unsigned char* buffer, int bufferSize);

};


#endif
