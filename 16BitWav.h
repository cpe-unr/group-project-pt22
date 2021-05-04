#ifndef BitWav16_H
#define BitWav16_H

#include "WavFile.h"


class BitWav16 : public WavFile
{
public:
    void readFile(const QString &filePath) override;
    void writeFile(const QString &outFilePath) override;
	signed short *getBuffer();

private:
	signed short* buffer = NULL;
};

#endif
