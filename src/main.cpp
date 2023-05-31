#include "mainwindow.h"

#include <QApplication>

#include <tests/build_batch_test.h>
#include <tests/qtestrunner.h>





#ifndef QT_TEST_SINGLE


int main(int argc, char *argv[])
{

#ifdef  QT_TEST
    BuildBatchTest buildBatchTest;
    return buildBatchTest.runTest(argc,argv);

#else

    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    return a.exec();

#endif


}
#endif
