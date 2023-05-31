QT += testlib

# 批量测试则开启 QT_TEST 宏
# DEFINES += QT_TEST

# 对单个文件进行测试,则开启 QT_TEST_SINGLE 宏
# 并找到对那个的测试文件,打开 QTEST_MAIN
# DEFINES += QT_TEST_SINGLE

SOURCES +=\
    $$PWD/test_add.cpp \
    $$PWD/test_add2.cpp


HEADERS += \
    $$PWD/build_batch_test.h \
    $$PWD/qtestrunner.h \
    $$PWD/test_add.h \ \
    $$PWD/test_add2.h
