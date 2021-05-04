#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class iProcessor {
public:
	virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
	virtual void processBuffer(signed int* buffer, int bufferSize) = 0;
	virtual void processBuffer(signed short int* buffer, int bufferSize) = 0;
	
};


#endif
