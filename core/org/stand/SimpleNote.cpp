#include <QStringList>

#include "SimpleNote.h"

using namespace org::stand;

SimpleNote::SimpleNote(const QString &pronounce, double position, double msDuration, int note) :
    pronounce(pronounce), msPosition(position), msDuration(msDuration), note(note)
{
}

SimpleNote::SimpleNote(const SimpleNote &that) :
    SimpleNote(that.pronounce, that.msPosition, that.msDuration, that.note)
{
}

SimpleNote &SimpleNote::operator =(const SimpleNote &that)
{
    this->pronounce = that.pronounce;
    this->msPosition = that.msPosition;
    this->msDuration = that.msDuration;
    this->note = that.note;
    return (*this);
}

SimpleNote SimpleNote::parseLine(const QString &line)
{
    QStringList params = line.split(",");
    return SimpleNote(params[0], params[1].toDouble(), params[2].toDouble(), params[3].toInt());
}

bool SimpleNote::canParseLine(const QString &line)
{
    return line.split(",").size() == 4;
}

double SimpleNote::msEnd() const
{
    return msPosition + msDuration;
}

bool SimpleNote::operator ==(const SimpleNote &other) const
{
    return this->msDuration == other.msDuration &&
            this->msPosition == other.msPosition &&
            this->note == other.note &&
            this->pronounce == other.pronounce;
}

bool SimpleNote::operator <(const SimpleNote &other) const
{
    return this->msEnd() < other.msEnd();
}
