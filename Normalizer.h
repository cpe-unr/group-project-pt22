#ifndef NORMALIZER_H
#define NORMALIZER_H

#include "Processor.h"

using namespace std;

class Normalizer : public Processor {

	int peak;

public:

	Normalizer();
	Normalizer(int peak);

	void processBuffer(unsigned char* buffer, int bufferSize);

};


#endif
