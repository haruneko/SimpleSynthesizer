QT -= gui

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = lib

HEADERS += \
    core/org/stand/utau/UtauPhoneme.h \
    core/org/stand/utau/UtauOtoHash.h \
    core/world/common.h \
    core/world/constant_numbers.h \
    core/world/dio.h \
    core/world/fft.h \
    core/world/matlabfunctions.h \
    core/world/platinum.h \
    core/world/star.h \
    core/world/synthesis.h \
    core/world/synthesis_ap.h \
    core/world/tandem_ap.h \
    core/org/stand/world/World.h \
    core/org/stand/world/Specgrams.h \
    core/org/stand/world/Signal.h \
    core/org/stand/world/WaveUtil.h \
    core/org/stand/SimpleNote.h \
    core/org/stand/SimpleScore.h \
    core/org/stand/util/MusicalNote.h \
    core/org/stand/SimpleCorpus.h \
    core/org/stand/SimpleSynthesizer.h

SOURCES += \
    core/org/stand/utau/UtauPhoneme.cpp \
    core/org/stand/utau/UtauOtoHash.cpp \
    core/world/common.cpp \
    core/world/dio.cpp \
    core/world/fft.cpp \
    core/world/matlabfunctions.cpp \
    core/world/platinum.cpp \
    core/world/star.cpp \
    core/world/synthesis.cpp \
    core/world/synthesis_ap.cpp \
    core/world/tandem_ap.cpp \
    core/org/stand/world/World.cpp \
    core/org/stand/world/Specgrams.cpp \
    core/org/stand/world/Signal.cpp \
    core/org/stand/world/WaveUtil.cpp \
    core/org/stand/SimpleNote.cpp \
    core/org/stand/SimpleScore.cpp \
    core/org/stand/util/MusicalNote.cpp \
    core/org/stand/SimpleCorpus.cpp \
    core/org/stand/SimpleSynthesizer.cpp

INCLUDEPATH += \
    core

QMAKE_CXXFLAGS += -Wall -std=c++11
