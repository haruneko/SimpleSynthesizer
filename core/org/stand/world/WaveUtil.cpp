#include <stdlib.h>
#include "world/matlabfunctions.h"

#include "Signal.h"

#include "WaveUtil.h"

using namespace org::stand::world;

Signal *WaveUtil::read(const char *filepath)
{
    int fs, bit, length;
    double *wave = wavread(filepath, &fs, &bit, &length);
    if(!wave || length <= 0)
    {
        return NULL;
    }

    Signal *signal = new Signal(length, fs);
    if(!signal)
    {
        return NULL;
    }

    for(int i = 0; i < length; i++)
    {
        signal->wave[i] = wave[i];
    }

    delete[] wave;
    return signal;
}

void WaveUtil::write(const char *filepath, const Signal *signal)
{
    wavwrite(signal->wave, signal->length, signal->samplingFrequency, 16, filepath);
}
