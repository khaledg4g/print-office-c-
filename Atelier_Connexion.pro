#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
QT += printsupport
QT += charts
QT += serialport
TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    client.cpp \
    commande.cpp \
    dialog.cpp \
    employe.cpp \
    fidelite.cpp \
    fournisseur.cpp \
    historique.cpp \
    login.cpp \
    mail.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    mainwindowc.cpp \
    mainwindowe.cpp \
    mainwindowf.cpp \
    mainwindowp.cpp \
    produit.cpp

HEADERS += \
    arduino.h \
    client.h \
    commande.h \
    dialog.h \
    employe.h \
    fidelite.h \
    fournisseur.h \
    historique.h \
    login.h \
    mail.h \
        mainwindow.h \
    connection.h \
    mainwindowc.h \
    mainwindowe.h \
    mainwindowf.h \
    mainwindowp.h \
    produit.h

FORMS += \
        dialog.ui \
        login.ui \
        mainwindow.ui \
        mainwindowc.ui \
        mainwindowe.ui \
        mainwindowf.ui \
        mainwindowp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
