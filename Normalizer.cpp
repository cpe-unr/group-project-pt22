//Alex Czarnomski
//CS 202
//5/4/21

#include "Normalizer.h"

Normalizer::Normalizer(int newNPercent){
	nPercent = newNPercent;
};

void Normalizer::processBuffer(unsigned char* buffer, int bufferSize){
    int i = 0, max = 0;
    for(i;buffer[i] != '\0'; i++){
        if(buffer[i] >= max){
            max = buffer[i];
        };
    };
    i = 0;
    for(i;buffer[i] != '\0'; i++){
        buffer[i] = (nPercent*(255) - max)+(buffer[i]);
    };
};


void Normalizer::processBuffer(signed int* buffer, int bufferSize){
	int i = 0, max = 0;
	for(i;buffer[i] != '\0'; i++){
        if(buffer[i] >= max){
			max = buffer[i];
		};
	};
	i = 0;
	for(i;buffer[i] != '\0'; i++){
		buffer[i] = (nPercent*(32767) - max)+(buffer[i]);
	};
};

void Normalizer::processBuffer(signed short* buffer, int bufferSize){
    /**
    /*@param i, index for iteration.
    /*@param max, maximum peak in the audio.
    */
    int i = 0, max = 0;
    for(i;buffer[i] != '\0'; i++){
        if(buffer[i] >= max){
            max = buffer[i];
        };
    };
    i = 0;

    ///adds the normalization value to point in the audio file.
    for(i;buffer[i] != '\0'; i++){
        buffer[i] = (nPercent*(255) - max)+(buffer[i]);
    };
};

