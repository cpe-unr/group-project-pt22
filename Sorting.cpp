#include "Sorting.h"
#include "WavFile.h"
#include "32BitWav.h"
#include "16BitWav.h"
#include "8BitWav.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


WavFile* Sorting::filter(const QString &fileName)
{
    std::string fN = fileName.toStdString();
    std::ifstream file(fN,std::ios::binary | std::ios::in);
	file.read((char*)&waveHeader, sizeof(wavStructure));
	file.close();
	if(waveHeader.bit_depth == 8)
	    {
	    	auto* wav = new BitWav8();
	    	wav->readFile(fileName);
            return wav;
	    }
	else if(waveHeader.bit_depth == 16)
	    {
	    	auto* wav = new BitWav16();
            wav->readFile(fileName);
            return wav;
	    }
	else if(waveHeader.bit_depth == 32)
	   	{
	    	auto* wav = new BitWav32();
            wav->readFile(fileName);
            return wav;
	    }
    else { return nullptr; }
}
