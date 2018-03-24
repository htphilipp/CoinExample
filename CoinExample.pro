#-------------------------------------------------
#
# Project created by QtCreator 2017-02-04T16:24:10
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CoinExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    logprob.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    logprob.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-logProb-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/release/ -llogProb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-logProb-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/debug/ -llogProb
else:unix: LIBS += -L$$PWD/../../../build-logProb-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/ -llogProb

INCLUDEPATH += $$PWD/../../../LogProbProj/logProb
DEPENDPATH += $$PWD/../../../LogProbProj/logProb
