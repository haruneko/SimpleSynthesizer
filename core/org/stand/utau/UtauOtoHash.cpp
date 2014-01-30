#include <QFile>
#include <QTextCodec>
#include <QTextStream>

#include "UtauOtoHash.h"

using namespace org::stand::utau;

UtauOtoHashFactory::UtauOtoHashFactory(QTextCodec *codec)
    : textCodec(codec)
{
}

UtauOtoHashFactory::UtauOtoHashFactory(const UtauOtoHashFactory &other)
    : UtauOtoHashFactory(other.textCodec)
{
}

UtauOtoHashFactory &UtauOtoHashFactory::operator =(const UtauOtoHashFactory &other)
{
    this->textCodec = other.textCodec;
    return (*this);
}

UtauOtoHash UtauOtoHashFactory::read(const QFileInfo &fileinfo) const
{
    QFile file(fileinfo.absoluteFilePath());
    if(!file.open(QFile::ReadOnly))
    {
        return UtauOtoHash();
    }
    QTextStream stream(&file);
    stream.setCodec(textCodec);

    QList<QString> otoList;
    while(!stream.atEnd())
    {
        otoList.append(stream.readLine());
    }
    file.close();
    return parse(otoList);
}

UtauOtoHash UtauOtoHashFactory::parse(const QList<QString> &otoList) const
{
    UtauOtoHash result;
    foreach(const QString &line, otoList)
    {
        QStringList params = line.split(",");
        if(params.size() != 6)
        {
            continue;
        }
        QStringList fileAndAlias = params[0].split("=");
        if(fileAndAlias.size() != 2)
        {
            continue;
        }
        QString filename = fileAndAlias[0];
        QString pronounce = fileAndAlias[1].isEmpty() ? fileAndAlias[0].split(".")[0] : fileAndAlias[1];
        double msLeftBlank = params[1].toDouble();
        double msFixedLength = params[2].toDouble();
        double msRightBlank = params[3].toDouble();
        double msPreutterance = params[4].toDouble();
        double msOverlap = params[5].toDouble();
        result.insert(pronounce, UtauPhoneme(pronounce, filename, msLeftBlank, msFixedLength, msRightBlank, msPreutterance, msOverlap));
    }
    return result;
}
