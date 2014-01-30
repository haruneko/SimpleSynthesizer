#ifndef UTAUOTOHASH_H
#define UTAUOTOHASH_H

#include <QFileInfo>
#include <QHash>
#include <QTextCodec>

#include "UtauPhoneme.h"

namespace org
{
namespace stand
{
namespace utau
{
/**
 * @brief The UtauOtoHash class represents UTAU oto.ini.
 */
typedef QHash<QString, UtauPhoneme> UtauOtoHash;

class UtauOtoHashFactory
{
public:
    explicit UtauOtoHashFactory(QTextCodec *codec = QTextCodec::codecForName("Shift-JIS"));
    UtauOtoHashFactory(const UtauOtoHashFactory &other);
    UtauOtoHashFactory &operator =(const UtauOtoHashFactory &other);

    virtual ~UtauOtoHashFactory(){}

    virtual UtauOtoHash read(const QFileInfo &fileinfo) const;
    virtual UtauOtoHash parse(const QList<QString> &otoList) const;
protected:
    QTextCodec *textCodec;
};

}
}
}

#endif // UTAUOTOHASH_H
