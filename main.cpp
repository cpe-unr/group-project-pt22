/** @file */
#include <iostream>
#include "WavFile.h"
#include "Sorting.h"
#include <string>
#include <vector>

using namespace std;
/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */


int main() {
    string filename = "yes-8-bit-stereo.wav";
    Sorting sort;
    int byte = 8;
	byte = sort.filter(filename);

    if(byte == 8)
    	{
    		auto* wav = new WavFile<unsigned char>();
    		wav->readFile(filename);
    		//std::cout << wav->waveHeader.num_channels << endl;
    		delete wav;
    	}
    	else if(byte == 16)
    	{
    		auto* wav = new WavFile<signed short>();
    		wav->readFile(filename);
    		delete wav;
    	}
    	else if(byte == 32)
    	{
    		auto* wav = new WavFile<signed int>();
    		wav->readFile(filename);
    		delete wav;
    	}

    return 0;
}
