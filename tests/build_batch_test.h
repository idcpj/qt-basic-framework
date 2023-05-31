#ifndef BUILD_BATCH_TEST_H
#define BUILD_BATCH_TEST_H

#include "qtestrunner.h"
#include "test_add.h"
#include "test_add2.h"


class BuildBatchTest {

private:
    TestRunner testRunner;

public:
     BuildBatchTest()
        :testRunner()
    {
         testRunner.addTest(new testAdd);
         testRunner.addTest(new testAdd2);

    }

     int runTest(int argc, char *argv[]){
         bool pass = testRunner.runTests(argc, argv);
         qDebug() << "Overall result: " << (pass ? "PASS" : "FAIL");
         return pass?0:1;
     }

};

#endif // BUILD_BATCH_TEST_H
