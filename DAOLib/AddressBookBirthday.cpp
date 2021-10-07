#include "AddressBookBirthday.h"

AddressBookBirthday::AddressBookBirthday()
{

}

qint64 AddressBookBirthday::getCID() const
{
    return cID;
}

void AddressBookBirthday::setCID(qint64 newCID)
{
    cID = newCID;
}

int AddressBookBirthday::getDayInYear() const
{
    return dayInYear;
}

void AddressBookBirthday::setDayInYear(const int &newDayInYear)
{
    dayInYear = newDayInYear;
}
