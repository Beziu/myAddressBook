#include "AddressBookContact.h"

AddressBookContact::AddressBookContact()
{

}

void AddressBookContact::setContactID(qint64 value)
{
   cID = value;
}

qint64 AddressBookContact::getContactID() const
{
   return cID;
}

void AddressBookContact::setContactName(const QString &value)
{
   cName = value;
}

QString AddressBookContact::getContactName() const
{
   return cName;
}

void AddressBookContact::setContactSurname(const QString &value)
{
   cSurname = value;
}

QString AddressBookContact::getContactSurname() const
{
   return cSurname;
}

void AddressBookContact::setContactTelephoneNumberCell(const QString &value)
{
   cTelCell = value;
}

QString AddressBookContact::getContactTelephoneNumberCell() const
{
   return cTelCell;
}

void AddressBookContact::setContactTelephoneNumberHome(const QString &value)
{
   cTelHome = value;
}

QString AddressBookContact::getContactTelephoneNumberHome() const
{
   return cTelHome;
}

void AddressBookContact::setContactEmail(const QString &value)
{
   cEmail = value;
}

QString AddressBookContact::getContactEmail() const
{
   return cEmail;
}

void AddressBookContact::setContactAddressPLZ(const QString &value)
{
   cAdrPLZ = value;
}

QString AddressBookContact::getContactAddressPLZ() const
{
   return cAdrPLZ;
}

void AddressBookContact::setContactAddressCity(const QString &value)
{
   cAdrCity = value;
}

QString AddressBookContact::getContactAddressCity() const
{
   return cAdrCity;
}

void AddressBookContact::setContactAddressStreet(const QString &value)
{
   cAdrStr = value;
}

QString AddressBookContact::getContactAddressStreet() const
{
   return cAdrStr;
}

void AddressBookContact::setContactBirthday(const QString &value)
{
   cBday = value;
}

QString AddressBookContact::getContactBirthday() const
{
   return cBday;
}

void AddressBookContact::setContactDayOfYear(const int &value)
{
   cDayOfYear = value;
}

int AddressBookContact::getContactDayOfYear() const
{
   return cDayOfYear;
}

void AddressBookContact::setContactGroup(const int &value)
{
   cGroup = value;
}

int AddressBookContact::getContactGroup() const
{
   return cGroup;
}

void AddressBookContact::setContactTimestamp(const QString &value)
{
   cTimeStamp = value;
}

QString AddressBookContact::getContactTimestamp() const
{
   return cTimeStamp;
}

void AddressBookContact::setContactGroupID(const int value)
{
   cGID = value;
}

int AddressBookContact::getContactGroupID() const
{
   return cGID;
}
