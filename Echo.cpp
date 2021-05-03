#include "Echo.h"

Echo::Echo(int delay){
	delay = delay;
};

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	int i = 0;
	for(i;buffer[i] != '\0'; i++){
		if(i - delay >= 0){	
			bufferSize = 0.5*(buffer[i] + buffer[i - delay]);
		};
	};
};

