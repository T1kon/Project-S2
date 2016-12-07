#-------------------------------------------------
#
# Project created by QtCreator 2016-12-07T14:52:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectS_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ship.cpp \
    bullet.cpp \
    meteor.cpp \
    shipai.cpp \
    shipplayer.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    ship.h \
    bullet.h \
    meteor.h \
    shipai.h \
    shipplayer.h \
    game.h

FORMS    += mainwindow.ui
