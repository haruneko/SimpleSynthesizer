#include <stdlib.h>

#include "Signal.h"

using namespace org::stand::world;

Signal::Signal(int length, int samplingFrequency)
{
    this->wave = new double[length];
    this->samplingFrequency = samplingFrequency;
    this->length = length;
}

Signal::~Signal()
{
    delete[] wave;
}

void Signal::clear()
{
    if(!wave || length <= 0)
    {
        return;
    }

    for(int i = 0; i < length; i++)
    {
        wave[i] = 0.0;
    }
}
