#ifndef SIMPLESCORE_H
#define SIMPLESCORE_H

#include <QFileInfo>
#include <QTextCodec>
#include "SimpleNote.h"

namespace org
{
namespace stand
{

typedef QList<SimpleNote> SimpleScore;

class SimpleScoreFactory
{
public:
    explicit SimpleScoreFactory(QTextCodec *codec = QTextCodec::codecForName("Shift-JIS"));
    virtual ~SimpleScoreFactory(){ }

    virtual SimpleScore read(const QFileInfo &fileinfo) const;
    virtual SimpleScore parse(const QList<QString> &lines) const;

private:
    QTextCodec *textCodec;
};

}
}

#endif // SIMPLESCORE_H
