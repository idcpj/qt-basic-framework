#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <QList>
#include <QTimer>
#include <QCoreApplication>
#include <QtTest>
#include <QString>


/*
Taken from https://stackoverflow.com/questions/1524390/what-unit-testing-framework-should-i-use-for-qt
BEWARE: there are some concerns doing so, see  https://bugreports.qt.io/browse/QTBUG-23067
*/
class TestRunner : public QObject
{
    Q_OBJECT

public:
    TestRunner() : m_overallResult(0)
    {
        QDir dir;
        if (!dir.exists(mTestLogFolder))
        {

            if (!dir.mkdir(mTestLogFolder)){
                qFatal("Cannot create folder %s ", qPrintable(mTestLogFolder));
            }

        }
    }

    void addTest(QObject * test)
    {
        test->setParent(this);
        m_tests.append(test);
    }

    bool runTests(int argc, char * argv[])
    {
        QCoreApplication app(argc, argv);
        QTimer::singleShot(0, this, SLOT(run()));
        app.exec();

        return m_overallResult == 0;
    }

    private slots:
    void run()
    {
        doRunTests();
        QCoreApplication::instance()->quit();
    }

private:
    void doRunTests()
    {
        // BEWARE: we assume either no command line parameters or evaluate first parameter ourselves
        // usage:
        //    help:                                        "TestSuite.exe -help"
        //    run all test classes (with logging):         "TestSuite.exe"
        //    print all test classes:                      "TestSuite.exe -classes"
        //    run one test class with QtTest parameters:   "TestSuite.exe testClass [options] [testfunctions[:testdata]]...
        if (QCoreApplication::arguments().size() > 1 && QCoreApplication::arguments()[1] == "-help")
        {
            qDebug() << "Usage:";
            qDebug().noquote() << "run all test classes (with logging):\t\t" << qAppName();
            qDebug().noquote() << "print all test classes:\t\t\t\t" << qAppName() << "-classes";
            qDebug().noquote() << "run one test class with QtTest parameters:\t" << qAppName() << "testClass [options][testfunctions[:testdata]]...";
            qDebug().noquote() << "get more help for running one test class:\t" << qAppName() << "testClass -help";
            exit(0);
        }

        foreach(QObject * test, m_tests)
        {
            QStringList arguments;
            QString testName = test->metaObject()->className();

            if (QCoreApplication::arguments().size() > 1)
            {
                if (QCoreApplication::arguments()[1] == "-classes")
                {
                    // only print test classes
                    qDebug().noquote() << testName;
                    continue;
                }
                else
                if (QCoreApplication::arguments()[1] != testName)
                {
                    continue;
                }
                else
                {
                    arguments = QCoreApplication::arguments();
                    arguments.removeAt(1);
                }
            }
            else
            {
                arguments.append(QCoreApplication::arguments()[0]);
                // log to console
                arguments.append("-o"); arguments.append("-,txt");
                // log to file as TXT
                arguments.append("-o"); arguments.append(mTestLogFolder % "/" % testName % ".log,txt");
                // log to file as XML
                arguments.append("-o"); arguments.append(mTestLogFolder % "/" % testName % ".xml,xunitxml");
            }
            m_overallResult |= QTest::qExec(test, arguments);
        }
    }

    QList<QObject *> m_tests;
    int m_overallResult;
    const QString mTestLogFolder = "testLogs";
};

#endif // TESTRUNNER_H
