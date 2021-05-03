#ifndef WAVFILE_H
#define WAVFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include "WavStructure.h"
#include "MetaStructure.h"
#include "MetaDataHeader.h"

using namespace std;

class WavFile
{
public:

	int getBufferSize() const
	{
		return waveHeader.data_bytes;
	}

	void getMetaData(ifstream &file)
	{
		int i = 0;


		file.read((char*)&metaHeader,sizeof(metaDataHeader));
		i += 4;
		do
		{
			auto* temp = new metaStructure;
			file.read((char*)temp,sizeof(metaStructure));

			i += 8;
			i+=temp->numChunkByte;

			char dataTemp[temp->numChunkByte];
			file.read((char*)&dataTemp,sizeof(dataTemp));

			string metaChunk = dataTemp;
			metaStruc.push_back(temp);
			metaChunk_value.push_back(metaChunk);
		}while(i < metaHeader.totalByte);

	}
	void changeMetaData(const string &iName, const string &metaInfo)
	{
		string tempS;
		int i;
		for(i = 0; i < 1; i++)
		{
			tempS = "";
			for(int a = 0; a < sizeof(metaStruc[i]->metaDataChunk);a++)
			{
				if(metaStruc[i]->metaDataChunk[a] >= 'A' && metaStruc[i]->metaDataChunk[a] <= 'Z')
				{
					tempS += metaStruc[i]->metaDataChunk[a];
				}
				else if(metaStruc[i]->metaDataChunk[a] >= 'a' && metaStruc[i]->metaDataChunk[a] <='z')
				{
					tempS += metaStruc[i]->metaDataChunk[a] - 32;
				}
			}

			if(tempS == iName)
			{
				metaStruc[i]->numChunkByte = metaInfo.length();
				metaChunk_value[i] = metaInfo;
				return;
			}
		}

		auto* temp = new metaStructure;

		strcpy(temp->metaDataChunk,iName.c_str());
		temp->numChunkByte = metaInfo.length();
		metaChunk_value.push_back(metaInfo);
		metaStruc.push_back(temp);

	}
	void writeMetaData(ofstream &file)
	{
		string temp = metaStruc[0]->metaDataChunk;
		file.write((char*)&metaHeader, sizeof(metaDataHeader));
		for(int i = 0; i < metaStruc.size(); i++)
		{
			file.write((char*)metaStruc[i], sizeof(metaStructure));
			file.write((char*)metaChunk_value[i].c_str(), metaStruc[i]->numChunkByte);
			delete metaStruc[i];
		}
	}

	virtual void readFile(const string &filePath) = 0;

	virtual void writeFile(const string &outFilePath) = 0;
	wavStructure waveHeader;


private:
	metaDataHeader metaHeader;
	vector<metaStructure*> metaStruc;
	vector<string> metaChunk_value;
};

#endif

