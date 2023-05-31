#include <QTest>
#include <src/tools/cal.h>
#include "test_add.h"




void testAdd::toadd()
{
    Cal cal;
    QCOMPARE(cal.add(1,2),4);
}


void testAdd::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void testAdd::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void testAdd::bench_simple()
{
   QString str1 = QLatin1String("This is a test string");
   QString str2 = QLatin1String("This is a test string");

   QCOMPARE(str1.localeAwareCompare(str2), 0);

   QBENCHMARK {
       str1.localeAwareCompare(str2);
   }
}


//QTEST_MAIN(testAdd);
