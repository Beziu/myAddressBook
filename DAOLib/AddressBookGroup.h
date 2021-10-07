#ifndef ADDRESSBOOKGROUP_H
#define ADDRESSBOOKGROUP_H

#include <QObject>

#include "DAOLib.h"

class DAOLIB_EXPORT AddressBookGroup
{
public:
    AddressBookGroup();

    void setGroupID(int value);
    int getGroupID() const;

    void setGroupName(const QString& value);
    QString getGroupName() const;

private:
    int gID;
    QString gName;

};

#endif // ADDRESSBOOKGROUP_H
