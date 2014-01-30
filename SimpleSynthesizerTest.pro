include(SimpleSynthesizerCore.pro)

QT += testlib core
QT -= gui

CONFIG += console
CONFIG += test

TEMPLATE = app

HEADERS += \
    test/org/stand/AutoTest.h \
    test/org/stand/utau/UtauOtoHashTest.h \
    test/org/stand/SimpleScoreTest.h \
    test/org/stand/util/MusicalNoteTest.h

SOURCES += \
    test/main.cpp \
    test/org/stand/AutoTest.cpp

INCLUDEPATH += \
    core \
    test

QMAKE_CXXFLAGS += -Wall -std=c++11
