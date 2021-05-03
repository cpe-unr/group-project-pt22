
#include "32BitWav.h"
#include "WavFile.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void BitWav32::readFile(const string &filePath)
{
	ifstream file(filePath, ios::binary | ios::in);
	if(file.is_open())
		{
			file.read((char*)&waveHeader, sizeof(wavStructure));
			BitWav32::buffer = new signed int[waveHeader.data_bytes];
			file.read((char*)BitWav32::buffer, waveHeader.data_bytes);
			file.close();
		}
}

void BitWav32::writeFile(const string &outFilePath)
{
	ofstream file(outFilePath, ios::binary | ios::out);
	file.write((char*)&waveHeader, sizeof(wavStructure));
	file.write((char*)BitWav32::buffer, waveHeader.data_bytes);
	file.close();
}

signed int *BitWav32::getBuffer()
{
	return BitWav32::buffer;
}
