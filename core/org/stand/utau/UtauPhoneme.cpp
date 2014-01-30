#include "UtauPhoneme.h"

using namespace org::stand::utau;

UtauPhoneme::UtauPhoneme(const QString &pronounce,
                         const QString &filename,
                         double msLeftBlank,
                         double msFixedLength,
                         double msRightBlank,
                         double msPreutterance,
                         double msOverlap) :
    pronounce(pronounce),
    filename(filename),
    msLeftBlank(msLeftBlank),
    msFixedLength(msFixedLength),
    msRightBlank(msRightBlank),
    msPreutterance(msPreutterance),
    msOverlap(msOverlap)
{
}

UtauPhoneme::UtauPhoneme(const UtauPhoneme &that) :
    UtauPhoneme(that.pronounce, that.filename, that.msLeftBlank, that.msFixedLength, that.msRightBlank, that.msPreutterance, that.msOverlap)
{
}

UtauPhoneme UtauPhoneme::copy() const
{
    return UtauPhoneme(*this);
}

bool UtauPhoneme::operator ==(const UtauPhoneme &other) const
{
    return this->filename == other.filename &&
            this->msFixedLength == other.msFixedLength &&
            this->msLeftBlank == other.msLeftBlank &&
            this->msOverlap == other.msOverlap &&
            this->msPreutterance == other.msPreutterance &&
            this->msRightBlank == other.msRightBlank &&
            this->pronounce == other.pronounce;
}
