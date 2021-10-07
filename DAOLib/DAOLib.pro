QT += widgets sql
QT -= gui

TEMPLATE = lib
DEFINES += DAOLIB_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddressBookBirthday.cpp \
    AddressBookContact.cpp \
    AddressBookDAO.cpp \
    AddressBookGroup.cpp \
    DAOLib.cpp \
    DateStyledItemDelegate.cpp \

HEADERS += \
    AddressBookBirthday.h \
    AddressBookContact.h \
    AddressBookDAO.h \
    AddressBookGroup.h \
    DAOLib_global.h \
    DAOLib.h \
    DateStyledItemDelegate.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
