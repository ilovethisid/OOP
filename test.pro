TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    Window.cpp \
    window.cpp \
    Player.cpp \
    Block.cpp \
    Map.cpp \
    Gametimer.cpp

HEADERS += \
    Window.h \
    window.h \
    Player.h \
    Block.h \
    Map.h \
    Gametimer.h
