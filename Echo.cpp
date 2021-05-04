#include "Echo.h"
#include <QDebug>

Echo::Echo(int newDelay){
    delay = newDelay;
};

void Echo::processBuffer(unsigned char* buffer, int bufferSize){

    for(int i = 0; i < bufferSize; i++)
        {
            //if it is in scope then adjust sound at current index
            if(i != 0 && (i - delay) > 0)
            {
                buffer[i] = (buffer[i] * .8) + (buffer[i - delay] * .2);

            }


        }
    /*int i = 0;
	for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
    };*/
};

void Echo::processBuffer(signed int* buffer, int bufferSize){
	int i = 0;
    for(int i = 0; i < bufferSize; i++)
        {
            //if it is in scope then adjust sound at current index
            if(i != 0 && (i - delay) > 0)
            {
                buffer[i] = (buffer[i] * .8) + (buffer[i - delay] * .2);

            }


        }
    /*for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
    };*/
};

void Echo::processBuffer(signed short int* buffer, int bufferSize){
	int i = 0;
    qDebug() << "ATest7";
    for(int i = 0; i < bufferSize; i++)
        {
            //if it is in scope then adjust sound at current index
            if(i != 0 && (i - delay) > 0)
            {
                buffer[i] = (buffer[i] * .8) + (buffer[i - delay] * .2);

            }


        }
    /*for(i;i < bufferSize; i++){
		if(i - delay >= 0){	
			buffer[i] = 0.75*(buffer[i]) + 0.25*(buffer[i - delay]);
		};
    };*/
};
