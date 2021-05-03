#ifndef BitWav8_H
#define BitWav8_H

#include "WavFile.h"
#include <vector>

using namespace std;

class BitWav8 :  public WavFile
{
public:
    void readFile(const QString &filePath) override;
    void writeFile(const QString &outFilePath) override;
	unsigned char *getBuffer();

private:
	unsigned char* buffer = NULL;
};

#endif
