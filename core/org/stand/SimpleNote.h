#ifndef SIMPLENOTE_H
#define SIMPLENOTE_H

#include <QString>

namespace org
{
namespace stand
{

/**
 * @brief The SimpleNote class represents a single musical note.
 */
class SimpleNote
{
public:
    SimpleNote(const QString &pronounce, double msPosition, double msDuration, int note);
    SimpleNote(const SimpleNote &that);
    SimpleNote &operator =(const SimpleNote &other);

    virtual ~SimpleNote(){ }

    bool operator ==(const SimpleNote &other) const;
    bool operator <(const SimpleNote &other) const;

    double msEnd() const;

    QString pronounce;
    double msPosition;
    double msDuration;
    int note;

    static bool canParseLine(const QString &line);
    static SimpleNote parseLine(const QString &line);
};

}
}

#endif // SIMPLENOTE_H
