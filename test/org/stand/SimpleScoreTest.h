#ifndef SIMPLESCORETEST_H
#define SIMPLESCORETEST_H

#include <QTest>
#include <QObject>

#include "org/stand/AutoTest.h"
#include "org/stand/SimpleScore.h"

Q_DECLARE_METATYPE(org::stand::SimpleScore)

namespace org
{
namespace stand
{

class SimpleScoreTest : public QObject
{
    Q_OBJECT
private:
    SimpleScore some(const SimpleNote &note)
    {
        SimpleScore score;
        score.append(note);
        return score;
    }

    SimpleScore none()
    {
        return SimpleScore();
    }

private slots:
    void parse_should_correctly_parse_lines_data()
    {
        QTest::addColumn<QString>("input");
        QTest::addColumn<SimpleScore>("expected");

        QTest::newRow("  valid1") << "pronounce,0,0,60" << some(SimpleNote("pronounce", 0, 0, 60));
        QTest::newRow("  valid2") << "pronounce,1,1.5,127" << some(SimpleNote("pronounce", 1, 1.5, 127));
        QTest::newRow("  valid3") << "あああああ,1,1.5,127" << some(SimpleNote("あああああ", 1, 1.5, 127));
        QTest::newRow("invalid1") << "pronounce,0,60" << none();
        QTest::newRow("invalid2") << "totally invalid." << none();
    }

    void parse_should_correctly_parse_lines()
    {
        QFETCH(QString, input);
        QFETCH(SimpleScore, expected);
        QStringList ins;
        ins.append(input);

        SimpleScoreFactory factory(QTextCodec::codecForName("utf-8"));
        QCOMPARE(factory.parse(ins), expected);
    }
};
}
}

DECLARE_TEST(org::stand::SimpleScoreTest)

#endif // SIMPLESCORETEST_H
