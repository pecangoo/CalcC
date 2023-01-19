QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additional_foos.cpp \
    dialog.cpp \
    in_polish.c \
    list.c \
    main.cpp \
    mainwindow.cpp \
    parcer.c \
    polish_arifmetic.c \
    qcustomplot.cpp \
    run_core.c

QT       += printsupport

HEADERS += \
    additional_foos.h \
    dialog.h \
    in_polish.h \
    list.h \
    mainwindow.h \
    parcer.h \
    polish_arifmetic.h \
    qcustomplot.h \
    run_core.h

FORMS += \
    dialog.ui \
    mainwindow.ui

QT       += printsupport

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
