#include <QtMath>

#include "MusicalNote.h"

using namespace org::stand::util;

double MusicalNote::frequencyFromNote(double note, double A4Frequency)
{
    return pow(2.0, (note - A4Note) / 12.0) * A4Frequency;
}

double MusicalNote::noteFromFrequency(double frequency, double A4Frequency)
{
    return A4Note + 12.0 * log2(frequency / A4Frequency);
}
