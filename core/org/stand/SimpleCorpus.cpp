#include "org/stand/utau/UtauPhoneme.h"
#include "org/stand/world/WaveUtil.h"
#include "org/stand/world/World.h"

#include "SimpleCorpus.h"

using namespace org::stand;

SimpleCorpusFactory::SimpleCorpusFactory(double msFramePeriod, utau::UtauOtoHashFactory otoFactory) :
    otoFactory(otoFactory), msFramePeriod(msFramePeriod)
{
}

SimpleCorpus *SimpleCorpusFactory::create(const QFileInfo &fileinfo) const
{
    SimpleCorpus *result = new SimpleCorpus(otoFactory.read(fileinfo), fileinfo.dir(), msFramePeriod, new world::World);
    return result;
}

SimpleCorpus::SimpleCorpus(const utau::UtauOtoHash &oto, const QDir &otoDir, double msFramePeriod, world::World *world) :
    oto(oto), otoDir(otoDir), msFramePeriod(msFramePeriod), world(world)
{
}

SimpleCorpus::~SimpleCorpus()
{
    qDeleteAll(data);
    delete world;
}

const world::Specgrams *SimpleCorpus::get(const QString &pronounce)
{
    if(!data.contains(pronounce))
    {
        if(oto.contains(pronounce))
        {
            world::WaveUtil waveUtil;
            QFileInfo fileinfo(otoDir.filePath(oto.find(pronounce).value().filename));
            data[pronounce] = world->analyze(waveUtil.read(fileinfo.absoluteFilePath().toLocal8Bit().data()), msFramePeriod);
        }
        else
        {
            // Pronounce doesn't exists. Explicit null will be inserted.
            data[pronounce] = NULL;
        }
    }

    return data[pronounce];
}

const utau::UtauPhoneme *SimpleCorpus::phonemeInfo(const QString &pronounce) const
{
    if(!oto.contains(pronounce))
    {
        return NULL;
    }
    return &(oto.find(pronounce).value());
}
