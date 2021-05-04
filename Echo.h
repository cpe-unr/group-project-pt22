#ifndef ECHO_H
#define ECHO_H

#include "iProcessor.h"

using namespace std;

class Echo : public iProcessor {

	int delay;

public:

	Echo();
	Echo(int delay);

	void processBuffer(unsigned char* buffer, int bufferSize);
	void processBuffer(signed int* buffer, int bufferSize);
	void processBuffer(signed short int* buffer, int bufferSize);

};


#endif
