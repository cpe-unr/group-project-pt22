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
    string names[1];
    names[0] = "yes-8bit-mono.wav";
    //names[1] = "yes-8-bit-stereo.wav";
    //names[2] = "yes-16-bit-mono.wav";
    //names[3] = "yes-26-bit-stereo.wav";
    Sorting sort;
    vector<WavFile*> files;


    for(auto filename : names)
    {
    	sort.filter(filename, files);
    }
    files[0]->changeMetaData("INAM", "temp");
    files[0]->changeMetaData("IPRD", "1999");
    files[0]->writeFile(names[0]);


    return 0;
}
