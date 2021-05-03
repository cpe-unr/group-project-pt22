#ifndef BITWAV32_H
#define BITWAV32_H

#include "WavFile.h"


class BitWav32 : public WavFile
{
public:
    void readFile(const QString &filePath) override;
    void writeFile(const QString &outFilePath) override;
	signed int *getBuffer();

private:
	signed int* buffer;
};

#endif
