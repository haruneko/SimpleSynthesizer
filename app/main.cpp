#include <QFileInfo>

#include "org/stand/SimpleCorpus.h"
#include "org/stand/SimpleScore.h"
#include "org/stand/SimpleSynthesizer.h"
#include "org/stand/world/WaveUtil.h"
#include "org/stand/world/World.h"

using namespace org::stand;

void synthesizeScore(const char *outPath, const char *scorePath, const char *otoPath)
{
    QFileInfo otoFileInfo(otoPath);
    QFileInfo scoreFileInfo(scorePath);

    SimpleSynthesizer synthesizer(otoFileInfo);
    world::Signal *signal = synthesizer.synthesize(SimpleScoreFactory().read(scoreFileInfo));

    if(!signal)
    {
        printf("invalid data;\n score path = `%s`\n oto path = `%s`\n", scorePath, otoPath);
        return;
    }

    world::WaveUtil().write(outPath, signal);
}

void simpleSynthesize(const char *outPath, const char *inPath)
{
    world::Signal *signal = world::WaveUtil().read(inPath);
    world::Specgrams *specgrams = world::World().analyze(signal, 5.0);
    for(int i = 0; i < specgrams->frameLength; i++)
    {
        specgrams->f0[i] = 440.0;
    }
    world::WaveUtil().write(outPath, world::World().synthesize(specgrams, 44100));
}

int main(int argc, char *argv[])
{
//    simpleSynthesize("c:\\projects\\momo_out.wav", "c:\\projects\\momo.wav");
    synthesizeScore("c:\\projects\\test.wav", "c:\\projects\\score.txt", "c:\\projects\\momotan\\oto.ini");
    return 0;
}
