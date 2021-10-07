#ifndef ADDRESSBOOKBIRTHDAY_H
#define ADDRESSBOOKBIRTHDAY_H

#include <QObject>

#include "DAOLib.h"

class DAOLIB_EXPORT AddressBookBirthday
{
public:
    AddressBookBirthday();

    qint64 getCID() const;
    void setCID(qint64 newCID);

    int getDayInYear() const;
    void setDayInYear(const int& newDayInYear);

private:
    qint64 cID;
    int dayInYear;
};

#endif // ADDRESSBOOKBIRTHDAY_H
