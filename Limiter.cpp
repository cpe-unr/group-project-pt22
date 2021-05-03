#include "Limiter.h"

Limiter::Limiter(int lim){
        lim = lim;
};

void Limiter::processBuffer(unsigned char* buffer, int bufferSize){
	int i = 0;
	limU = lim;
	limL = 1-lim;
	for(i;buffer[i] != '\0'; i++){
  		if(buffer[i] >= limU*255){
			bufferSize = (int) (limU*255 - 0.5);
		}else if(buffer[i] <= 0.2*255){
			bufferSize = (int) (limL*225 + 0.5);
		};
 	};
};
