#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"

using namespace std;

class Echo : public Processor {

	int delay;

public:

	Echo();
	Echo(int delay);

	void processBuffer(unsigned char* buffer, int bufferSize);

};


#endif
