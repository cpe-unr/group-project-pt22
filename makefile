AFMS: main.cpp Sorting.o WavFile.h 8BitWav.o 16BitWav.o 32Bitwav.o
	g++ -std=c++11 main.cpp Sorting.o 8BitWav.o 16BitWav.o 32Bitwav.o -o AFMS

Sorting.o: Sorting.h Sorting.cpp WavFile.h WavStructure.h MetaDataHeader.h MetaStructure.h 8BitWav.h 16BitWav.h 32BitWav.h
	g++ -std=c++11 Sorting.cpp 8BitWav.cpp 16BitWav.cpp 32BitWav.cpp -c 
	
8BitWav.o: 8BitWav.cpp 8BitWav.h WavFile.h
	g++ -std=c++11 8BitWav.cpp -c
16BitWav.o: 16BitWav.cpp 16BitWav.h WavFile.h
	g++ -std=c++11 16BitWav.cpp -c
32BitWav.o: 32BitWav.cpp 32BitWav.h WavFile.h
	g++ -std=c++11 32BitWav.cpp -c
	
clean:
	rm *.o AFMS
