#ifndef BITWAV32_H
#define BITWAV32_H

#include "WavFile.h"


class BitWav32 : public WavFile
{
public:
	void readFile(const string &filePath) override;
	void writeFile(const string &outFilePath) override;
	signed int *getBuffer();

private:
	signed int* buffer;
};

#endif
