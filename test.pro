TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

SOURCES += \
    main.cpp \
    Window.cpp \
    window.cpp \
    Player.cpp \
    Block.cpp \
    Map.cpp \
    GameTimer.cpp \
    Interface.cpp \
    GameSound.cpp

HEADERS += \
    Window.h \
    window.h \
    Player.h \
    Block.h \
    Map.h \
    MyFunc.h \
    GameTimer.h \
    Interface.h \
    GameSound.h

RESOURCES += \
    resources.qrc

DISTFILES += \
    model.qmodel
