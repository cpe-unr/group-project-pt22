#include "Echo.h"

Echo::Echo(int delay){
	delay = delay;
};

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	int i = 0;
	for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
	};
};

void Echo::processBuffer(signed int* buffer, int bufferSize){
	int i = 0;
	for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
	};
};

void Echo::processBuffer(signed short int* buffer, int bufferSize){
	int i = 0;
	for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
	};
};
