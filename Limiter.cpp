#include "Limiter.h"

Limiter::Limiter(int lim){
        lim = lim;
};

void Limiter::processBuffer(unsigned char* buffer, int bufferSize){
	int i = 0;
	for(i;buffer[i] != '\0'; i++){
  		if(buffer[i] >= (lim*128)+128){
			bufferSize = (int) (lim*128)+128 - 0.5);
		}else if(buffer[i] <= 128-(lim*128)){
			bufferSize = (int) (128-(lim*128) + 0.5);
		};
 	};
};
