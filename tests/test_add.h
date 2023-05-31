#ifndef TEST_ADD_H
#define TEST_ADD_H

#include <QObject>

class testAdd : public QObject
{

Q_OBJECT

private slots:

    //在第一个测试函数执行前调用。
    void initTestCase(){}
    // 在最后一个测试函数执行后调用。
    void cleanupTestCase(){}
    // 在每一个测试函数执行前调用。
    void init(){}
    // 在每一个测试函数执行后调用。
    void cleanup(){}

    //第三方方法测试
    void toadd();

    // 数据驱动测试
    void toUpper_data();
    void toUpper();

    // bench 测试
    void bench_simple();
};

#endif // TEST_ADD_H
