#include "SimpleCorpus.h"
#include "SimpleNote.h"
#include "SimpleScore.h"

#include "org/stand/world/Signal.h"
#include "org/stand/world/Specgrams.h"
#include "org/stand/world/World.h"

#include "org/stand/util/MusicalNote.h"

#include "SimpleSynthesizer.h"

using namespace org::stand;


SimpleSynthesizer::SimpleSynthesizer(const QFileInfo &otoFilepath, int samplingFrequency, const SimpleCorpusFactory &corpusFactory) :
    samplingFrequency(samplingFrequency), corpus(corpusFactory.create(otoFilepath))
{
}

SimpleSynthesizer::~SimpleSynthesizer()
{
    delete corpus;
}

world::Signal *SimpleSynthesizer::synthesize(const SimpleScore &score)
{
    if(score.isEmpty())
    {
        return NULL;
    }
    double msLength = score.last().msEnd();
    int samples = msLength * samplingFrequency / 1000.0 + 0.5;

    world::Signal *result = new world::Signal(samples, samplingFrequency);
    result->clear();

    foreach(const SimpleNote &note, score)
    {
        printf("now synthesizing -> %s\n", note.pronounce.toUtf8().data());
        world::Signal *signalForNote = this->signalForNote(note);

        addNoteSignalToResult(result, signalForNote, note);

        delete signalForNote;
    }
    return result;
}

world::Signal *SimpleSynthesizer::signalForNote(const SimpleNote &note)
{
    const world::Specgrams *specgrams = corpus->get(note.pronounce);
    if(!specgrams)
    {
        return NULL;
    }
    const utau::UtauPhoneme *phoneme = corpus->phonemeInfo(note.pronounce);
    int frameLength = (note.msDuration + phoneme->msPreutterance) / specgrams->msFramePeriod;
    world::Specgrams *buffer = world::Specgrams::create(frameLength, specgrams->fftSize, specgrams->msFramePeriod);

    for(int i = 0; i < buffer->frameLength; i++)
    {
        int sourceIndex = i + phoneme->msLeftBlank / specgrams->msFramePeriod;
        sourceIndex = qMin(qMax(sourceIndex, 0), specgrams->frameLength);
        buffer->f0[i] = util::MusicalNote::frequencyFromNote(note.note);

        for(int j = 0; j < buffer->fftSize; j++)
        {
            buffer->specgram[i][j] = specgrams->specgram[sourceIndex][j];
        }
        for(int j = 0; j < buffer->fftSize; j++)
        {
            buffer->residual[i][j] = specgrams->residual[sourceIndex][j];
        }
    }

    world::Signal *result = world::World().synthesize(buffer, samplingFrequency);
    delete buffer;

    return result;
}

void SimpleSynthesizer::addNoteSignalToResult(world::Signal *result, const world::Signal *signalForNote, const SimpleNote &note)
{
    const utau::UtauPhoneme *phoneme = corpus->phonemeInfo(note.pronounce);

    int resultBegin = qMax((int)(note.msPosition * samplingFrequency / 1000.0), 0);
    int resultEnd = note.msEnd() * samplingFrequency / 1000.0 + 0.5;

    for(int i = resultBegin, j = 0; i < resultEnd && j < signalForNote->length; i++, j++)
    {
        result->wave[i] += signalForNote->wave[j];
    }
}
