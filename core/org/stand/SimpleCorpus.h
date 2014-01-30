#ifndef SIMPLECORPUS_H
#define SIMPLECORPUS_H

#include <QDir>
#include <QFileInfo>
#include <QHash>

#include "org/stand/utau/UtauOtoHash.h"
#include "org/stand/world/Specgrams.h"

namespace org
{
namespace stand
{
namespace world
{
class World;
}

class SimpleCorpus
{
public:
    virtual ~SimpleCorpus();

    virtual const world::Specgrams *get(const QString &pronounce);
    virtual const utau::UtauPhoneme *phonemeInfo(const QString &pronounce) const;

private:
    SimpleCorpus(const utau::UtauOtoHash &oto, const QDir &otoDir, double msFramePeriod, world::World *world);

    QHash<QString, world::Specgrams *> data;
    world::World *world;

    utau::UtauOtoHash oto;
    QDir otoDir;
    double msFramePeriod;

    friend class SimpleCorpusFactory;
};

class SimpleCorpusFactory
{
public:
    SimpleCorpusFactory(double msFramePeriod = 5.0, utau::UtauOtoHashFactory otoFactory = utau::UtauOtoHashFactory());
    virtual ~SimpleCorpusFactory(){ }

    virtual SimpleCorpus *create(const QFileInfo &fileinfo) const;

private:
    utau::UtauOtoHashFactory otoFactory;
    double msFramePeriod;
};

}
}

#endif // SIMPLECORPUS_H
