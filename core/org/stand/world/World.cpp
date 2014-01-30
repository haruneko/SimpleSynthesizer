#include <stdlib.h>

#include "world/dio.h"
#include "world/star.h"
#include "world/platinum.h"
#include "world/synthesis.h"

#include "Specgrams.h"
#include "Signal.h"

#include "World.h"

using namespace org::stand::world;

Specgrams *World::analyze(Signal *signal, double msFramePeriod)
{
    if(!signal)
    {
        return NULL;
    }

    int frameLength = GetSamplesForDIO(signal->samplingFrequency, signal->length, msFramePeriod);
    int fftSize = GetFFTSizeForStar(signal->samplingFrequency);

    Specgrams *result = Specgrams::create(frameLength, fftSize, msFramePeriod);
    if(!result)
    {
        return NULL;
    }

    Dio(signal->wave, signal->length, signal->samplingFrequency, msFramePeriod, result->timeAxis, result->f0);
    Star(signal->wave, signal->length, signal->samplingFrequency, result->timeAxis, result->f0, frameLength, result->specgram);
    Platinum(signal->wave, signal->length, signal->samplingFrequency, result->timeAxis, result->f0, frameLength, result->specgram, fftSize, result->residual);

    return result;
}

Signal *World::synthesize(Specgrams *spectrograms, int samplingFrequency)
{
    if(!spectrograms)
    {
        return NULL;
    }

    double secLength = spectrograms->msLength() / 1000.0;
    int waveLength = secLength * samplingFrequency;

    Signal *result = new Signal(waveLength, samplingFrequency);
    if(!result)
    {
        return NULL;
    }

    result->clear();
    Synthesis(spectrograms->f0,
              spectrograms->frameLength,
              spectrograms->specgram,
              spectrograms->residual,
              spectrograms->fftSize,
              spectrograms->msFramePeriod,
              result->samplingFrequency,
              result->length,
              result->wave);
    return result;
}
