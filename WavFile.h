#ifndef WAVFILE_H
#define WAVFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include "WavStructure.h"
using namespace std;

template <typename T>
class WavFile
{
public:
	T *getBuffer()
	{
		return buffer;
	}

	int getBufferSize() const
	{
		return waveHeader.data_bytes;
	}

	void readFile(const string &filePath)
	{
		ifstream file(filePath, ios::binary | ios::in);
		if(file.is_open())
		{
			file.read((char*)&waveHeader, sizeof(wavStructure));
			buffer = new T[waveHeader.data_bytes];
			file.read((char*)buffer, waveHeader.data_bytes);
			file.close();
		}
	}

	void writeFile(const string &outFilePath)
	{
		ofstream file(outFilePath, ios::binary | ios::out);
		file.write((char*)&waveHeader, sizeof(wavStructure));
		file.write((char*)buffer, waveHeader.data_bytes);
		file.close();
	}
private:
	T* buffer = NULL;
	wavStructure waveHeader;

};

#endif
