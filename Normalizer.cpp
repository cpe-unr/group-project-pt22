#include "Normalizer.h"
#include <Algorithm>

Normalizer::Normalizer(int peak){
	peak = peak;
};

void Normalizer::processBuffer(unsigned char* buffer, int bufferSize){
	int i = 0, max = max_element(buffer + 0, buffer + bufferSize);
	for(i;buffer[i] != '\0'; i++){  		
		buffer[i] = (int) ((peak - max)*(255) + 0.5); 
	};
};
