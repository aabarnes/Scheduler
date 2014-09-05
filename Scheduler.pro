#-------------------------------------------------
#
# Project created by QtCreator 2013-11-28T12:53:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scheduler
TEMPLATE = app


SOURCES += main.cpp\
    CalendarWeekWidget.cpp \
    SignInDialog.cpp \
    Schedulerdialog.cpp \
    TimeSlot.cpp \
    ColorButton.cpp

HEADERS  += \
    CalendarWeekWidget.h \
    SignInDialog.h \
    Schedulerdialog.h \
    TimeSlot.h \
    ColorButton.h

FORMS    += \
    CalendarWeekWidget.ui \
    SignInDialog.ui \
    Schedulerdialog.ui \
    TimeSlot.ui \
