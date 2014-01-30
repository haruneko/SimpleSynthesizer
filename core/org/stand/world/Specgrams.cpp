#include <stdlib.h>

#include "Specgrams.h"

using namespace org::stand::world;

Specgrams::Specgrams(int frameLength, int fftSize, double msFramePeriod)
{
    this->frameLength = frameLength;
    this->fftSize = fftSize;
    this->msFramePeriod = msFramePeriod;
    f0 = new double[frameLength];
    timeAxis = new double[frameLength];
    specgram = allocMatrix(frameLength, fftSize);
    residual = allocMatrix(frameLength, fftSize);
}

Specgrams::Specgrams(const Specgrams &other)
{
    frameLength = other.frameLength;
    fftSize = other.fftSize;
    msFramePeriod = other.msFramePeriod;
    f0 = new double[frameLength];
    timeAxis = new double[frameLength];
    specgram = allocMatrix(frameLength, fftSize);
    residual = allocMatrix(frameLength, fftSize);

    copy(f0, other.f0, frameLength);
    copy(timeAxis, other.timeAxis, frameLength);
    copy(specgram[0], other.specgram[0], fftSize * frameLength);
    copy(residual[0], other.residual[0], fftSize * frameLength);
}

Specgrams::~Specgrams()
{
    delete[] f0;
    delete[] timeAxis;
    if(specgram)
    {
        delete[] specgram[0];
    }
    delete[] specgram;
    if(residual)
    {
        delete residual[0];
    }
}

double **Specgrams::allocMatrix(int frameLength, int fftSize)
{
    double **result = new double*[frameLength];
    result[0] = new double[frameLength * fftSize];
    for(int i = 1; i < frameLength; i++)
    {
        result[i] = result[0] + i * fftSize;
    }
    return result;
}

void Specgrams::copy(double *dst, const double *src, int length)
{
    for(int i = 0; i < length; i++)
    {
        dst[i] = src[i];
    }
}

Specgrams *Specgrams::create(int frameLength, int fftSize, double msFramePeriod)
{
    if(frameLength <= 0 || fftSize <= 0 || msFramePeriod <= 0.0)
    {
        return NULL;
    }
    return new Specgrams(frameLength, fftSize, msFramePeriod);
}

double Specgrams::msLength() const
{
    return frameLength * msFramePeriod;
}
