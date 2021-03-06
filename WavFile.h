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
#include <QString>
using namespace std;

class WavFile///first class that is inherited from for the certain bit wav
{
public:
	///retun buffer size
	int getBufferSize() const
	{
		return waveHeader.data_bytes;
	}

	/**This function would loop through the vector until to either find a match
	 * or return a blank string
	 */
    QString metaDisplayer(const QString &iName)
    {
        string tempS;
        string inName = iName.toStdString();
        int i;
        for(i = 0; i < metaStruc.size(); i++)
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
                    tempS += metaStruc[i]->metaDataChunk[a] - 32;                    }
            }
            if(tempS == inName)
            {
                return QString::fromStdString(metaChunk_value[i]);
            }
        }
            return "";
    }

    /**reads the file after the wav for the meta data information
     * and creates a data structure for the meta data when it finds it
     */

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
	/**Checks the vector to see if a metadata input exist before hand.
	 * If it does not, it will create a new metastructure in order to hold the new
	 * information.
	 */
    void changeMetaData(const QString &iName, const QString &metaInfo)
	{
        string iN = iName.toStdString();
        string mI = metaInfo.toStdString();
        string tempS;
		int i;
        for(i = 0; i < metaStruc.size(); i++)
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

            if(tempS == iN)
			{
                metaStruc[i]->numChunkByte = mI.length();
                metaChunk_value[i] = mI;
				return;
			}
		}

		auto* temp = new metaStructure;

        strcpy(temp->metaDataChunk,iN.c_str());
        temp->numChunkByte = mI.length();
        metaChunk_value.push_back(mI);
		metaStruc.push_back(temp);

	}
    /**This would write the metadata back in the order it was obtained
     * it will stop once the vector is at its end, and delete the pointer every
     * time it loops through.
     */

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

    virtual void readFile(const QString &filePath) = 0;///abstract function to override

    virtual void writeFile(const QString &outFilePath) = 0;///abstract function to override
    wavStructure waveHeader;//public information about the wav file ex byte rate


private:
	metaDataHeader metaHeader;///used to hold list, total byte, and info
	vector<metaStructure*> metaStruc;///holds the metadata type and bytes
	vector<string> metaChunk_value;///holds the actual value of the metadata
};

#endif

