#ifndef UTAUPHONEME_H
#define UTAUPHONEME_H

#include <QString>

namespace org
{
namespace stand
{
namespace utau
{

/**
 * @brief The UtauPhoneme class represents a single UTAU phoneme in oto.ini.
 */
class UtauPhoneme
{
public:
    UtauPhoneme(const QString &pronounce,
                const QString &filename,
                double msLeftBlank,
                double msFixedLength,
                double msRightBlank,
                double msPreutterance,
                double msOverlap);
    UtauPhoneme(const UtauPhoneme &that);
    virtual ~UtauPhoneme(){}

    bool operator ==(const UtauPhoneme &that) const;

    UtauPhoneme copy() const;

    QString pronounce;
    QString filename;

    double msLeftBlank;
    double msFixedLength;
    double msRightBlank;
    double msPreutterance;
    double msOverlap;
};

}
}
}

#endif // UTAUPHONEME_H
