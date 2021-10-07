QT       += core gui
#QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src\BirthdayDialog.cpp \
    src\BirthdayWindow.cpp \
    src\ContactDialog.cpp \
    src\GroupsDialog.cpp \
    src\GroupsWindow.cpp \
    main.cpp \
    src\MainWindow.cpp

HEADERS += \
    src\BirthdayDialog.h \
    src\BirthdayWindow.h \
    src\ContactDialog.h \
    src\GroupsDialog.h \
    src\GroupsWindow.h \
    src\MainWindow.h

FORMS += \
    src\BirthdayDialog.ui \
    src\BirthdayWindow.ui \
    src\ContactDialog.ui \
    src\GroupsDialog.ui \
    src\GroupsWindow.ui \
    src\MainWindow.ui

TRANSLATIONS += \
    src\translations\myAddressBook_en.ts \
    src\translations\myAddressBook_pl.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
   Readme.md \
   src\translations\myAddressBook_en.ts

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/build-DAOLib/release/ -lDAOLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/build-DAOLib/debug/ -lDAOLib

INCLUDEPATH += $$PWD/DAOLib
DEPENDPATH += $$PWD/DAOLib
