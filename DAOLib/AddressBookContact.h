#ifndef ADDRESSBOOKCONTACT_H
#define ADDRESSBOOKCONTACT_H

#include <QObject>

#include "DAOLib.h"

class DAOLIB_EXPORT AddressBookContact
{
public:
    AddressBookContact();

    void setContactID(qint64 value);
    qint64 getContactID() const;

    void setContactName(const QString& value);
    QString getContactName() const;

    void setContactSurname(const QString& value);
    QString getContactSurname() const;

    void setContactTelephoneNumberCell(const QString& value);
    QString getContactTelephoneNumberCell() const;

    void setContactTelephoneNumberHome(const QString& value);
    QString getContactTelephoneNumberHome() const;

    void setContactEmail(const QString& value);
    QString getContactEmail() const;

    void setContactAddressPLZ(const QString& value);
    QString getContactAddressPLZ() const;

    void setContactAddressCity(const QString& value);
    QString getContactAddressCity() const;

    void setContactAddressStreet(const QString& value);
    QString getContactAddressStreet() const;

    void setContactBirthday(const QString& value);
    QString getContactBirthday() const;

    void setContactDayOfYear(const int& value);
    int getContactDayOfYear() const;

    void setContactGroup(const int& value);
    int getContactGroup() const;

    void setContactTimestamp(const QString& value);
    QString getContactTimestamp() const;

    // Used for relational databases
    void setContactGroupID(const int value);          // is correct
    int getContactGroupID() const;                    // ???

private:
    qint64 cID;
    QString cName, cSurname, cTelCell, cTelHome, cEmail, cBday;
    QString cAdrPLZ, cAdrCity, cAdrStr, cTimeStamp;

    int cDayOfYear, cGroup, cGID;

};

#endif // ADDRESSBOOKCONTACT_H
