#include "Sorting.h"
#include "WavFile.h"
#include "32BitWav.h"
#include "16BitWav.h"
#include "8BitWav.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


void Sorting::filter(const std::string &fileName, std::vector<WavFile*> &wavFile)
{
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	file.read((char*)&waveHeader, sizeof(wavStructure));
	file.close();
	if(waveHeader.bit_depth == 8)
	    {
	    	auto* wav = new BitWav8();
	    	wav->readFile(fileName);
	    	wavFile.push_back(wav);
	    }
	else if(waveHeader.bit_depth == 16)
	    {
	    	auto* wav = new BitWav16();
	    	wav->readFile(fileName);
	    	wavFile.push_back(wav);
	    }
	else if(waveHeader.bit_depth == 32)
	   	{
	    	auto* wav = new BitWav32();
	    	wav->readFile(fileName);
	    	wavFile.push_back(wav);
	    }
}
