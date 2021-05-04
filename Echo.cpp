#include "Echo.h"
#include <QDebug>

Echo::Echo(int newDelay){
    delay = newDelay;
};

void Echo::processBuffer(unsigned char* buffer, int bufferSize){

    ///@param i, index for iteration.
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

void Echo::processBuffer(signed short* buffer, int bufferSize){
    int i = 0;
    int dl = delay *.256f;
    for(i;i < bufferSize; i++){
        if(i - dl >= 0){
            buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - dl]);
		};
    };
};
