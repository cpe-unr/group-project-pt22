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
	void filter(const std::string&, std::vector<WavFile*>&);
};
#endif
