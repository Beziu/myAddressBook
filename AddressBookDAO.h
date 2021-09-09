#ifndef ADDRESSBOOKDAO_H
#define ADDRESSBOOKDAO_H

#include <QObject>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>

#include "DAOLib.h"
#include "AddressBookContact.h"
#include "AddressBookGroup.h"

class DAOLIB_EXPORT AddressBookDAO
{
public:
   static QSqlTableModel* readContactsIntoTableModel();
   static QSqlTableModel* readGroupsIntoTableModel();

   static AddressBookGroup *readGroup(const int key);
   static AddressBookContact *readContact(const qint64 key);

   static bool insertContact(const QString& cName, const QString& cSurname,
                             const QString& cTelCell, const QString& cTelHome,
                             const QString& cEmail, const QString& cAdrPLZ,
                             const QString& cAdrCity, const QString& cAdrStr,
                             const QString& cBday);

   static bool insertGroup(const QString& gName);

   static bool insertContactToGroup(const qint64 cid, const int gid);

   static bool contactExists(const QString& cName, const QString& cSurname,
                             const QString& cTelCell, const QString& cTelHome,
                             const QString& cEmail, const QString& cAdrPLZ,
                             const QString& cAdrCity, const QString& cAdrStr,
                             const QString& cBday);

   static bool groupExists(const QString& gName);

   static bool updateContact(const qint64 key, const QString& cName, const QString& cSurname,
                             const QString& cTelCell, const QString& cTelHome,
                             const QString& cEmail, const QString& cAdrPLZ,
                             const QString& cAdrCity, const QString& cAdrStr,
                             const QString& cBday);

   static bool updateGroup(const int key, const QString& gName);

   static void deleteAllContacts();
   static bool deleteContact(const qint64 key);
   static bool deleteGroup(const int key);
   static bool deleteContactFromGroup(const qint64 cid, const int gid);
   static bool deleteContactFromAllGroups(const qint64 cid);
   static bool deleteAllContactsReletionWhitGroup(const int gid);

   static int getContactsCount();
   static int getGroupsCount();
   static int getContactsInGroupCount(const int gid);
   static int getGroupID(const QString gName);
   static bool getAllGroupsIDFromContactID(const qint64 cid);

   static bool checkContactInGroup(const qint64 cid, const int gid);

   static qint64 getLastIdentity();

   static QSqlTableModel* searchContacts(const QString &byFilter);

   static QSqlQueryModel* readContactsFromSelectedGroup(const int gid);

private:
   AddressBookDAO();

};

#endif // ADDRESSBOOKDAO_H
