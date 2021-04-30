#ifndef SORTING_H
#define SORTING_H

#include "WavFile.h"
#include <string>
#include <iostream>
#include <fstream>
#include "WavStructure.h"
#include <vector>

class Sorting
{
private:
	wavStructure waveHeader;
	int bytes;
public:
	int filter(const std::string&);
};
#endif
