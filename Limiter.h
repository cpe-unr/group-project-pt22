#ifndef LIMITER_H
#define LIMITER_H

#include "iProcessor.h"

using namespace std;

class Limiter : public iProcessor {

	int lim;

public:

	Limiter();
	Limiter(int lim);

	void processBuffer(unsigned char* buffer, int bufferSize);
	void processBuffer(signed int* buffer, int bufferSize);
    void processBuffer(signed short* buffer, int bufferSize);

};


#endif
