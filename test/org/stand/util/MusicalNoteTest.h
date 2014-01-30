#ifndef MUSICALNOTETEST_H
#define MUSICALNOTETEST_H

#include <QObject>
#include <QTest>

#include "org/stand/AutoTest.h"
#include "org/stand/util/MusicalNote.h"

namespace org
{
namespace stand
{
namespace util
{

class MusicalNoteTest : public QObject
{
    Q_OBJECT
private slots:
    void frequency_from_note_should_pass_all_test_cases_data()
    {
        QTest::addColumn<double>("input");
        QTest::addColumn<double>("expected");
        QTest::newRow("C4") << 60.0 << 261.6255653005986;
        QTest::newRow("C+4") << 61.0 << 277.1826309768721;
        QTest::newRow("D4") << 62.0 << 293.6647679174076;
        QTest::newRow("D+4") << 63.0 << 311.12698372208087;
        QTest::newRow("E4") << 64.0 << 329.6275569128699;
        QTest::newRow("F4") << 65.0 << 349.2282314330039;
        QTest::newRow("F+4") << 66.0 << 369.9944227116344;
        QTest::newRow("G4") << 67.0 << 391.99543598174927;
        QTest::newRow("G+4") << 68.0 << 415.3046975799451;
        QTest::newRow("A4") << 69.0 << 440.0;
        QTest::newRow("A+4") << 70.0 << 466.1637615180899;
        QTest::newRow("B4") << 71.0 << 493.8833012561241;
    }

    void frequency_from_note_should_pass_all_test_cases()
    {
        QFETCH(double, input);
        QFETCH(double, expected);

        QCOMPARE(MusicalNote::frequencyFromNote(input), expected);
    }

    void note_from_frequency_should_pass_all_test_cases_data()
    {
        QTest::addColumn<double>("input");
        QTest::addColumn<double>("expected");
        QTest::newRow("C4") << 261.6255653005986 << 60.0;
        QTest::newRow("C+4") << 277.1826309768721 << 61.0;
        QTest::newRow("D4") << 293.6647679174076 << 62.0;
        QTest::newRow("D+4") << 311.12698372208087 << 63.0;
        QTest::newRow("E4") << 329.6275569128699 << 64.0;
        QTest::newRow("F4") << 349.2282314330039 << 65.0;
        QTest::newRow("F+4") << 369.9944227116344 << 66.0;
        QTest::newRow("G4") << 391.99543598174927 << 67.0;
        QTest::newRow("G+4") << 415.3046975799451 << 68.0;
        QTest::newRow("A4") << 440.0 << 69.0;
        QTest::newRow("A+4") << 466.1637615180899 << 70.0;
        QTest::newRow("B4") << 493.8833012561241 << 71.0;
    }

    void note_from_frequency_should_pass_all_test_cases()
    {
        QFETCH(double, input);
        QFETCH(double, expected);

        QCOMPARE(MusicalNote::noteFromFrequency(input), expected);
    }
};

}
}
}

DECLARE_TEST(org::stand::util::MusicalNoteTest)

#endif // MUSICALNOTETEST_H
