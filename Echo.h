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

};


#endif
