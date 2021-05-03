#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>
#include <iostream>

class Processor {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};


#endif
