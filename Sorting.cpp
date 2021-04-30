#include "Sorting.h"
#include "WavFile.h"
#include <iostream>
#include <string>
#include <fstream>


int Sorting::filter(const std::string &fileName)
{
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	file.read((char*)&waveHeader, sizeof(wavStructure));
	Sorting::bytes = waveHeader.byte_rate/waveHeader.num_channels/(waveHeader.sample_rate/8);
	file.close();
	return Sorting::bytes;
}
