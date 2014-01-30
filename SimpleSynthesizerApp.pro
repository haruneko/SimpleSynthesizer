include(SimpleSynthesizerCore.pro)

CONFIG += console

TEMPLATE = app

HEADERS +=

SOURCES += \
    app/main.cpp

INCLUDEPATH += \
    core \
    app

QMAKE_CXXFLAGS += -Wall -std=c++11
