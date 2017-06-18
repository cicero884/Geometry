#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T11:29:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = geometry
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    gamehoder.cpp \
    unit.cpp \
    scene.cpp \
    object.cpp \
    minion/tank.cpp \
    objects/card_slot.cpp \
    basic_set.cpp \
    template/attack.cpp \
    block.cpp \
    minion/bullet.cpp \
    objects/select_game_button.cpp \
    objects/select_minion_button.cpp \
    template/begin.cpp \
    minion/destroyer.cpp \
    minion/smasher.cpp \
    minion/protector.cpp \
    minion/shield.cpp \
    objects/war_fog.cpp

HEADERS  += mainwindow.h \
    main.h \
    gamehoder.h \
    unit.h \
    scene.h \
    object.h \
    minion/tank.h \
    objects/card_slot.h \
    basic_set.h \
    template/attack.h \
    block.h \
    minion/bullet.h \
    objects/select_game_button.h \
    objects/select_minion_button.h \
    template/begin.h \
    minion/destroyer.h \
    minion/smasher.h \
    minion/protector.h \
    minion/shield.h \
    objects/war_fog.h

FORMS    += mainwindow.ui

DISTFILES += \
    picture/background color.png \
    picture/word/you win.png

RESOURCES += \
    picture.qrc

