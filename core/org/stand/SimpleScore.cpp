#include <QFile>
#include <QTextStream>

#include "SimpleNote.h"

#include "SimpleScore.h"

using namespace org::stand;

SimpleScoreFactory::SimpleScoreFactory(QTextCodec *codec)
{
    textCodec = codec;
}

SimpleScore SimpleScoreFactory::read(const QFileInfo &fileinfo) const
{
    QFile file(fileinfo.absoluteFilePath());
    if(!file.open(QFile::ReadOnly))
    {
        return SimpleScore();
    }
    QTextStream stream(&file);
    stream.setCodec(textCodec);

    SimpleScore score;
    QList<QString> lines;
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        lines.append(line);
    }
    file.close();
    return parse(lines);
}

SimpleScore SimpleScoreFactory::parse(const QList<QString> &lines) const
{
    SimpleScore score;
    foreach(const QString &line, lines)
    {
        if(SimpleNote::canParseLine(line))
        {
            score.append(SimpleNote::parseLine(line));
        }
        else
        {
            printf("SimpleScoreFactory could not parse line: %s\n", line.toLocal8Bit().data());
        }
    }
    qSort(score);
    return score;
}
