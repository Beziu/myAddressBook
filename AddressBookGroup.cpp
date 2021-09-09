#include "AddressBookGroup.h"

AddressBookGroup::AddressBookGroup()
{

}

void AddressBookGroup::setGroupID(int value)
{
    gID = value;
}

int AddressBookGroup::getGroupID() const
{
    return gID;
}

void AddressBookGroup::setGroupName(const QString &value)
{
    gName = value;
}

QString AddressBookGroup::getGroupName() const
{
    return gName;
}
