QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectGUI
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ATMsystem.cpp \
    account.cpp \
    transaction.cpp \
    customer.cpp \
    admin.cpp

HEADERS += \
    mainwindow.h \
    ATMsystem.h \
    account.h \
    transaction.h \
    customer.h \
    admin.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
