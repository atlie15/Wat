QT += core
QT -= gui

TARGET = Nerd
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    nerd.cpp \
    interface.cpp

HEADERS += \
    nerd.h \
    interface.h

