#ifndef UTAUOTOHASHTEST_H
#define UTAUOTOHASHTEST_H

#include "org/stand/AutoTest.h"
#include "org/stand/utau/UtauOtoHash.h"
#include "org/stand/utau/UtauPhoneme.h"

#include <QList>
#include <QTest>

Q_DECLARE_METATYPE(org::stand::utau::UtauOtoHash)

namespace org
{
namespace stand
{
namespace utau
{

class UtauOtoHashTest : public QObject
{
    Q_OBJECT
private:
    UtauOtoHash some(const UtauPhoneme &phoneme)
    {
        UtauOtoHash result;
        result.insert(phoneme.pronounce, phoneme);
        return result;
    }
    UtauOtoHash none()
    {
        return UtauOtoHash();
    }

private slots:
    void parseLine_should_parse_one_line_of_utau_oto_ini_data()
    {
        QTest::addColumn<QString>("input");
        QTest::addColumn<UtauOtoHash >("expected");

        QTest::newRow("  no alias") << "あ.wav=,98,50,51,100,150" << some(UtauPhoneme("あ", "あ.wav", 98, 50, 51, 100, 150));
        QTest::newRow("with alias") << "あ.wav=- あ,98,50,51,100,150" << some(UtauPhoneme("- あ", "あ.wav", 98, 50, 51, 100, 150));
        QTest::newRow("  invalid1") << "あ.wav=,98,50,51,100" << none();
        QTest::newRow("  invalid2") << "あ.wav=98,50,51,100,150" << none();
        QTest::newRow("  invalid3") << "totally invalid" << none();
    }

    void parseLine_should_parse_one_line_of_utau_oto_ini()
    {
        QFETCH(QString, input);
        QFETCH(UtauOtoHash, expected);
        QStringList ins;
        ins.append(input);

        UtauOtoHashFactory factory(QTextCodec::codecForName("UTF-8"));
        UtauOtoHash actual = factory.parse(ins);
        QCOMPARE(actual, expected);
    }
};

}
}
}

DECLARE_TEST(org::stand::utau::UtauOtoHashTest)

#endif // UTAUOTOHASHTEST_H
