#include "Sorting.h"
#include "WavFile.h"
#include "32BitWav.h"
#include "16BitWav.h"
#include "8BitWav.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
/**This function does a temp read on the wav in order
 * to get the byte rate and create a wav class
 * that is based on the said information
 */

WavFile* Sorting::filter(const QString &fileName)
{
    std::string fN = fileName.toStdString();
    std::ifstream file(fN,std::ios::binary | std::ios::in);
    file.read((char*)&waveHeader, sizeof(wavStructure));
    file.close();

    if(waveHeader.bit_depth == 8)///checks if the byte rate is 8
        {
            auto* wav = new BitWav8();
            wav->readFile(fileName);
            return wav;
        }
    else if(waveHeader.bit_depth == 16)///checks if the byte rate is 16
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
