//Alex Czarnomski
//processor code based on prof's lecture demo

#include <iostream>
#include <string>
#include <vector>
#include "FileManager.h"

using namespace std;

template <typename T, unsigned char* B[]>
class IProcessor {

	T buffer[] = B[];

public:

	unsigned char* Echo(T buffer[]);
	unsigned char* NoiseGate(T buffer[]);
	unsigned char* Limiter(T buffer[]);
	unsigned char* noProcess(T buffer[]);

};






