//Alex Czarnomski
//CS 202
//5/4/21
#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

/**
*@brief iProcessor class is where modification classes inherit from.
*/
class iProcessor {
public:

	/**
	*These virtual void functions are the same, save for the data type of buffer in each.
	*@param buffer The array which is holding the wave audio data.
	*@param bufferSize The size of the buffer above.
	*/
	virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
	virtual void processBuffer(signed int* buffer, int bufferSize) = 0;
	virtual void processBuffer(signed short int* buffer, int bufferSize) = 0;
	
};


#endif
