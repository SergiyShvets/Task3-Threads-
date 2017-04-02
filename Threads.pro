QT += core
QT -= gui

CONFIG += c++14 static

win32: INCLUDEPATH += C:/Qt/MyLibs/boost_1_62_0/
win32: LIBS += "-LC:/Qt/MyLibs/boost_1_62_0/stage/lib/"
win32: LIBS += -lboost_system-mgw53-mt-1_62
win32: LIBS += -lboost_filesystem-mgw53-mt-d-1_62


TARGET = Threads
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    linescounter.cpp \
    blanklinescounter.cpp \
    commentlinescounter.cpp \
    parser.cpp \
    totallinescounter.cpp \
    filemanager.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    linescounter.h \
    blanklinescounter.h \
    commentlinescounter.h \
    parser.h \
    totallinescounter.h \
    filemanager.h




