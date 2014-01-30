#include "AutoTest.h"

using namespace org::stand;

QHash<QString, QObject *> &QAutoTest::tests()
{
    static QHash<QString, QObject *> t;
    return t;
}

int QAutoTest::run(int argc, char *argv[])
{
    int ret = 0;
    foreach (QObject* test, tests().values())
    {
        ret |= QTest::qExec(test, argc, argv);
    }
    return ret;
}
