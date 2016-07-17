CONFIG += console c++14
QT += core

include (LibDS/LibDS.pri)

TARGET = ConsoleDS

CONFIG += debug_and_release

SOURCES += \
  src/Main.cpp \
  src/ConsoleDS.cpp

HEADERS += \
  src/ConsoleDS.h
