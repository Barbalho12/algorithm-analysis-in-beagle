QT += core
QT -= gui

TARGET = AnalysisTime
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    mergesort.cpp \
    bubblesort.cpp \
    quicksort.cpp

HEADERS += \
    bubblesort.h \
    mergesort.h \
    quicksort.h

