#ifndef MUSICALNOTE_H
#define MUSICALNOTE_H

namespace org
{
namespace stand
{
namespace util
{

namespace MusicalNote
{
const static double A4Frequency = 440.0;
const static double A4Note = 69.0;

double noteFromFrequency(double frequency, double A4Frequency = A4Frequency);

double frequencyFromNote(double note, double A4Frequency = A4Frequency);

}

}
}
}

#endif // MUSICALNOTE_H
