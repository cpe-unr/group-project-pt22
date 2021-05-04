#ifndef ECHO_H
#define ECHO_H

#include "iProcessor.h"

using namespace std;

class Echo : public iProcessor {

	int delay;

public:

	Echo();
    Echo(int newDelay);

	void processBuffer(unsigned char* buffer, int bufferSize);
	void processBuffer(signed int* buffer, int bufferSize);
    void processBuffer(signed short* buffer, int bufferSize);

};


#endif
