AFMS: main.cpp Sorting.o WavFile.h
	g++ -std=c++11 main.cpp Sorting.o -o AFMS

Sorting.o: Sorting.h Sorting.cpp WavFile.h WavStructure.h
	g++ -std=c++11 Sorting.cpp -c 
	

clean:
	rm *.o AFMS
