
#include "16BitWav.h"
#include "WavFile.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void BitWav16::readFile(const string &filePath)
{
	ifstream file(filePath, ios::binary | ios::in);
	if(file.is_open())
		{
			file.read((char*)&waveHeader, sizeof(wavStructure));
			BitWav16::buffer = new signed short[waveHeader.data_bytes];
			file.read((char*)BitWav16::buffer, waveHeader.data_bytes);
			getMetaData(file);
			file.close();
		}
}

void BitWav16::writeFile(const string &outFilePath)
{
	ofstream file(outFilePath, ios::binary | ios::out);
	file.write((char*)&waveHeader, sizeof(wavStructure));
	file.write((char*)BitWav16::buffer, waveHeader.data_bytes);
	file.close();
}

signed short *BitWav16::getBuffer()
{
	return BitWav16::buffer;
}
