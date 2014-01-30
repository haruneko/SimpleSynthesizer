#ifndef SIMPLESYNTHESIZER_H
#define SIMPLESYNTHESIZER_H

#include "SimpleScore.h"

namespace org
{
namespace stand
{
namespace world
{
class Signal;
}

class SimpleCorpus;
class SimpleCorpusFactory;
class SipmleNote;

class SimpleSynthesizer
{
public:
    SimpleSynthesizer(const QFileInfo &otoFilepath, int samplingFrequency = 44100, const SimpleCorpusFactory &corpusFactory = SimpleCorpusFactory());
    virtual ~SimpleSynthesizer();
    virtual world::Signal *synthesize(const SimpleScore &score);

private:
    world::Signal *signalForNote(const SimpleNote &note);
    void addNoteSignalToResult(world::Signal *result, const world::Signal *signalForNote, const SimpleNote &note);

    SimpleCorpus *corpus;
    int samplingFrequency;
};

}
}

#endif // SIMPLESYNTHESIZER_H
