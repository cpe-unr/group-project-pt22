#ifndef LIMITER_H
#define LIMITER_H

#include "Processor.h"

using namespace std;

class Limiter : public Processor {

	int lim;

public:

	Limiter();
	Limier(int lim);

	void processBuffer(unsigned char* buffer, int bufferSize);

};


#endif
