#ifndef BitWav16_H
#define BitWav16_H

#include "WavFile.h"


class BitWav16 : public WavFile
{
public:
	void readFile(const string &filePath) override;
	void writeFile(const string &outFilePath) override;
	signed short *getBuffer();

private:
	signed short* buffer = NULL;
};

#endif
