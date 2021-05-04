#include "Normalizer.h"

Normalizer::Normalizer(int nPercent){
	nPercent = nPercent;
};

void Normalizer::processBuffer(unsigned char* buffer, int bufferSize){
	//int i = 0, max = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	if(buffer[i] >= max;){
	//		max = buffer[i];
	//	};
	//};
	//i = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	buffer[i] = (nPercent*(255) - max)*(buffer[i]);
	//};
};

void Normalizer::processBuffer(signed int* buffer, int bufferSize){
	//int i = 0, max = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	if(buffer[i] >= max;){
	//		max = buffer[i];
	//	};
	//};
	//i = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	buffer[i] = (nPercent*(32767) - max)*(buffer[i]);
	//};
};

void Normalizer::processBuffer(signed short int* buffer, int bufferSize){
	//int i = 0, max = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	if(buffer[i] >= max;){
	//		max = buffer[i];
	//	};
	//};
	//i = 0;
	//for(i;buffer[i] != '\0'; i++){
	//	buffer[i] = (nPercent*(32767) - max)*(buffer[i]);
	//};
};
