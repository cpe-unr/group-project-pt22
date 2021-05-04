
#include "WavFile.h"
#include "8BitWav.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

///this function reads all the information from the wav file.
void BitWav8::readFile(const QString &filePath)
{
    string fp = filePath.toStdString();
    ifstream file(fp, ios::binary | ios::in);
	if(file.is_open())
		{
			file.read((char*)&waveHeader, sizeof(wavStructure));
			BitWav8::buffer = new unsigned char[waveHeader.data_bytes];
			file.read((char*)BitWav8::buffer, waveHeader.data_bytes);
			getMetaData(file);
			file.close();

		}
}

///This function writes all the information into the wav file.
void BitWav8::writeFile(const QString &outFilePath)
{
    string outfp = outFilePath.toStdString();
    ofstream file(outfp, ios::binary | ios::out);
	file.write((char*)&waveHeader, sizeof(wavStructure));
	file.write((char*)BitWav8::buffer, waveHeader.data_bytes);
	writeMetaData(file);
	file.close();
}
///this function returns the song portion of the wav file.
unsigned char *BitWav8::getBuffer()
{
	return BitWav8::buffer;
}
