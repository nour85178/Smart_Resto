
#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT       += core gui multimedia
QT       += core gui network printsupport
QT       += core gui sql charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion smtp
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
    admin.cpp \
    client.cpp \
    departement.cpp \
    employe.cpp \
    fourniture.cpp \
    integration.cpp \
    login.cpp \
    mailing.cpp \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    reclamation.cpp \
    depense.cpp \
    dialogfinance.cpp \
    dialogproduit.cpp \
    dialogstat.cpp \
    produit.cpp \
    revenu.cpp \
    arduino.cpp \
    updatedepense.cpp \
    updateproduit.cpp \
    updaterevenu.cpp \
    smtp.cpp \
    vehicule.cpp

HEADERS += \
    admin.h \
    client.h \
    departement.h \
    employe.h \
    fourniture.h \
    integration.h \
    login.h \
    mailing.h \
        mainwindow.h \
    connexion.h \
    reclamation.h \
    depense.h \
    dialogfinance.h \
    dialogproduit.h \
    dialogstat.h \
    produit.h \
    revenu.h \
    arduino.h \
    updatedepense.h \
    updateproduit.h \
    updaterevenu.h \
    smtp.h \
    vehicule.h

FORMS += \
        integration.ui \
        login.ui \
        dialogfinance.ui \
        dialogproduit.ui \
        dialogstat.ui \
        updatedepense.ui \
        updateproduit.ui \
        updaterevenu.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
