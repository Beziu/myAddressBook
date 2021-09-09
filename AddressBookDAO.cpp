#include "AddressBookDAO.h"

AddressBookDAO::AddressBookDAO()
{

}

// +--------------------------------------------------+
// |                    CONTACTS                      |
// +--------------------------------------------------+

bool AddressBookDAO::insertContact(const QString &cName, const QString &cSurname, const QString &cTelCell,
                                   const QString &cTelHome, const QString &cEmail, const QString &cAdrPLZ,
                                   const QString &cAdrCity, const QString &cAdrStr, const QString &cBday)
{
   QString SQL = "INSERT INTO Contacts ";
   SQL += "(CNAME, CSURNAME, CTELEPHONECELL, CTELEPHONEHOME, CEMAIL, ";
   SQL += "CADDRESSPLZ, CADDRESSCITY, CADDRESSSTREET, CBIRTHDAY) VALUES (";
   SQL += DAOLib::dbString(cName) + ", ";
   SQL += DAOLib::dbString(cSurname) + ", ";
   SQL += DAOLib::dbString(cTelCell) + ", ";
   SQL += DAOLib::dbString(cTelHome) + ", ";
   SQL += DAOLib::dbString(cEmail) + ", ";
   SQL += DAOLib::dbString(cAdrPLZ) + ", ";
   SQL += DAOLib::dbString(cAdrCity) + ", ";
   SQL += DAOLib::dbString(cAdrStr) + ", ";
   if (cBday.length() == 0)
      SQL += " NULL)";
   else
      SQL += DAOLib::dbString(cBday) + ")";

   return DAOLib::executeNonQuery(SQL) > 0;
}


bool AddressBookDAO::contactExists(const QString &cName, const QString &cSurname, const QString &cTelCell,
                                   const QString &cTelHome, const QString &cEmail, const QString &cAdrPLZ,
                                   const QString &cAdrCity, const QString &cAdrStr, const QString &cBday)
{
   bool OK;
   QString SQL = "SELECT COUNT(*) FROM Contacts";
   SQL += " WHERE CNAME = " + DAOLib::dbString(cName);
   SQL += " AND CSURNAME = " + DAOLib::dbString(cSurname);
   SQL += " AND CTELEPHONECELL = " + DAOLib::dbString(cTelCell);
   SQL += " AND CTELEPHONEHOME = " + DAOLib::dbString(cTelHome);
   SQL += " AND CEMAIL = " + DAOLib::dbString(cEmail);
   SQL += " AND CADDRESSPLZ = " + DAOLib::dbString(cAdrPLZ);
   SQL += " AND CADDRESSCITY = " + DAOLib::dbString(cAdrCity);
   SQL += " AND CADDRESSSTREET = " + DAOLib::dbString(cAdrStr);
   SQL += " AND CBIRTHDAY = " + DAOLib::dbString(cBday);

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return false;
   else
      return count.toInt() > 0;
}


bool AddressBookDAO::updateContact(const qint64 key, const QString &cName, const QString &cSurname,
                                   const QString &cTelCell, const QString &cTelHome,
                                   const QString &cEmail, const QString &cAdrPLZ,
                                   const QString &cAdrCity, const QString &cAdrStr,
                                   const QString &cBday)
{
   QString SQL = "UPDATE Contacts SET";
   SQL += " CNAME = " + DAOLib::dbString(cName);
   SQL += ", CSURNAME = " + DAOLib::dbString(cSurname);
   SQL += ", CTELEPHONECELL = " + DAOLib::dbString(cTelCell);
   SQL += ", CTELEPHONEHOME = " + DAOLib::dbString(cTelHome);
   SQL += ", CEMAIL = " + DAOLib::dbString(cEmail);
   SQL += ", CADDRESSPLZ = " + DAOLib::dbString(cAdrPLZ);
   SQL += ", CADDRESSCITY = " + DAOLib::dbString(cAdrCity);
   SQL += ", CADDRESSSTREET = " + DAOLib::dbString(cAdrStr);
   SQL += ", CBIRTHDAY = ";
   if (cBday.length() == 0)
      SQL += "NULL";
   else
      SQL += DAOLib::dbString(cBday);
   SQL += " WHERE CID = " + QString::number(key);

   return DAOLib::executeNonQuery(SQL) > 0;
}


bool AddressBookDAO::deleteContact(const qint64 key)
{
   QString SQL = "DELETE FROM Contacts ";
   SQL += "WHERE CID = " + QString::number(key);

   return DAOLib::executeNonQuery(SQL) > 0;
}


void AddressBookDAO::deleteAllContacts()
{
   QString SQL = "TRUNCATE TABLE Contacts";
   DAOLib::executeNonQuery(SQL);
}


int AddressBookDAO::getContactsCount()
{
   bool OK;
   QString SQL = "SELECT COUNT(*) FROM Contacts";

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return 0;
   else
      return count.toInt();
}


QSqlTableModel *AddressBookDAO::readContactsIntoTableModel()
{
	QSqlTableModel* tableModel = new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());

	tableModel->setTable("Contacts");
	// Zmiany w tabeli są dokonywane tylko przez manualnie
	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel->select();

	return tableModel;
}


QSqlTableModel *AddressBookDAO::searchContacts(const QString &byFilter)
{
	QSqlTableModel* tableModel = new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());

	QString filterString = "CNAME like '%%1%' OR CSURNAME like '%%1%'";
	filterString += " OR CTELEPHONECELL like '%%1%' OR CEMAIL like '%%1%'";

	tableModel->setTable("Contacts");
	tableModel->setFilter(filterString.arg(byFilter));
	// Zmiany w tabeli są dokonywane tylko przez manualnie
	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel->select();

	return tableModel;
}


AddressBookContact *AddressBookDAO::readContact(const qint64 key)
{
   AddressBookContact* answerDB = nullptr;
   bool OK;

//   QString SQL = "SELECT (CID, CNAME, CSURNAME, CTELEPHONECELL, CTELEPHONEHOME, ";
//   SQL += "CEMAIL, CADDRESSPLZ, CADDRESSCITY, CADDRESSSTREET, ";
//   SQL += "CBIRTHDAY, CTIMESTAMP) FROM Contacts ";
   QString SQL = "SELECT * FROM Contacts ";
   SQL += "WHERE CID = " + QString::number(key);

   QSqlQuery* query = DAOLib::executeQuery(SQL, OK);
   if (!OK)
   {
       delete query;
       return answerDB;
   }

   query->first();

   answerDB = new AddressBookContact();
   answerDB->setContactID(query->value("CID").toLongLong());
   answerDB->setContactName(query->value("CNAME").toString());
   answerDB->setContactSurname(query->value("CSURNAME").toString());
   answerDB->setContactTelephoneNumberCell(query->value("CTELEPHONECELL").toString());
   answerDB->setContactTelephoneNumberHome(query->value("CTELEPHONEHOME").toString());
   answerDB->setContactEmail(query->value("CEMAIL").toString());
   answerDB->setContactAddressPLZ(query->value("CADDRESSPLZ").toString());
   answerDB->setContactAddressCity(query->value("CADDRESSCITY").toString());
   answerDB->setContactAddressStreet(query->value("CADDRESSSTREET").toString());
   answerDB->setContactBirthday(query->value("CBIRTHDAY").toString());
   //answerDB->setContactTimestamp(query->value("CTIMESTAMP").toString());

   delete query;
   return answerDB;
}



// +--------------------------------------------------+
// |                    GROUPS                        |
// +--------------------------------------------------+

bool AddressBookDAO::insertGroup(const QString &gName)
{
   QString SQL = "INSERT INTO Groups ";
   SQL += "(GNAME) ";
   SQL += "VALUES (";
   SQL += DAOLib::dbString(gName) + ")";

   return DAOLib::executeNonQuery(SQL) > 0;
}


bool AddressBookDAO::groupExists(const QString &gName)
{
   bool OK;
   QString SQL = "SELECT COUNT(*) FROM Groups WHERE";
   SQL += " GNAME = " + DAOLib::dbString(gName);

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return false;
   else
      return count.toInt() > 0;
}


bool AddressBookDAO::updateGroup(const int key, const QString &gName)
{
   QString SQL = "UPDATE Groups SET";
   SQL += " GNAME = " + DAOLib::dbString(gName);
   SQL += " WHERE GID = " + QString::number(key);

   return DAOLib::executeNonQuery(SQL) > 0;
}


bool AddressBookDAO::deleteGroup(const int key)
{
   QString SQL = "DELETE FROM Groups ";
   SQL += "WHERE GID = " + QString::number(key);

   return DAOLib::executeNonQuery(SQL) > 0;
}


int AddressBookDAO::getGroupsCount()
{
   bool OK;
   QString SQL = "SELECT COUNT(*) FROM Groups";

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return 0;
   else
      return count.toInt();
}


int AddressBookDAO::getContactsInGroupCount(const int gid)
{
   bool OK;
   QString SQL = "SELECT COUNT(*) FROM ContactGroup ";
   SQL += "WHERE GID = " + QString::number(gid);

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return 0;
   else
      return count.toInt();
}


int AddressBookDAO::getGroupID(const QString gName)
{
   bool OK;
   QString SQL = "SELECT GID FROM Groups WHERE GNAME = ";
   SQL += DAOLib::dbString(gName);

   QVariant count = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return 0;
   else
      return count.toInt();
}


QSqlTableModel *AddressBookDAO::readGroupsIntoTableModel()
{
	QSqlTableModel* tableModel = new QSqlTableModel(nullptr, DAOLib::getDatabaseConnection());

	tableModel->setTable("Groups");
	// Zmiany w tabeli są dokonywane tylko przez program.
	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel->select();

	return tableModel;
}


AddressBookGroup *AddressBookDAO::readGroup(const int key)
{
   AddressBookGroup* answerDB = nullptr;
   bool OK;

   QString SQL = "SELECT GID, GNAME FROM Groups";
   SQL += " WHERE GID = " + QString::number(key);

   QSqlQuery* query = DAOLib::executeQuery(SQL, OK);
   if (!OK)
   {
       delete query;
       return answerDB;
   }

   query->first();

   answerDB = new AddressBookGroup();
   answerDB->setGroupID(query->value("GID").toInt());
   answerDB->setGroupName(query->value("GNAME").toString());

   delete query;
   return answerDB;
}



// +--------------------------------------------------+
// |               CONTACTS + GROUPS                  |
// +--------------------------------------------------+


// Adds the selected contact to the selected group.
// Adds relation contact <--> group.
bool AddressBookDAO::insertContactToGroup(const qint64 cid, const int gid)
{
   QString SQL = "INSERT INTO ContactGroup ";
   SQL += "(CID, GID) ";
   SQL += "VALUES (";
   SQL += QString::number(cid) + ", ";
   SQL += QString::number(gid) + ")";

   return DAOLib::executeNonQuery(SQL) > 0;
}


// Removes the selected contact from the selected group.
// Removes relation contact <--> group.
bool AddressBookDAO::deleteContactFromGroup(const qint64 cid, const int gid)
{
   QString SQL = "DELETE FROM ContactGroup";
   SQL += " WHERE CID = " + QString::number(cid);
   SQL += " AND GID = " + QString::number(gid);

   return DAOLib::executeNonQuery(SQL) > 0;
}


// Removes the selected contact from all groups to which the contact belongs.
// Used after the selected contact has been deleted.
bool AddressBookDAO::deleteContactFromAllGroups(const qint64 cid)
{
   QString SQL = "DELETE FROM ContactGroup";
   SQL += " WHERE CID = " + QString::number(cid);

   return DAOLib::executeNonQuery(SQL) > 0;
}


// Removes all contacts from the selected group.
// Used after the selected group has been deleted.
bool AddressBookDAO::deleteAllContactsReletionWhitGroup(const int gid)
{
   QString SQL = "DELETE FROM ContactGroup";
   SQL += " WHERE GID = " + QString::number(gid);

   return DAOLib::executeNonQuery(SQL) > 0;
}


// Returns a list of the groups where the contact belongs.
bool AddressBookDAO::getAllGroupsIDFromContactID(const qint64 cid)
{
   QString SQL = "SELECT GID FROM ContactGroup ";
   SQL += "WHERE CID = " + QString::number(cid);

   return DAOLib::executeNonQuery(SQL) > 0;
}


// Checks if the contact belongs to the selected group.
bool AddressBookDAO::checkContactInGroup(const qint64 cid, const int gid)
{
   QString SQL = "SELECT GID FROM ContactGroup ";
   SQL += "WHERE CID = " + QString::number(cid);
   SQL += " AND GID = " + QString::number(gid);

   return DAOLib::executeNonQuery(SQL) > 0;
}


QSqlQueryModel *AddressBookDAO::readContactsFromSelectedGroup(const int gid)
{
   QSqlQueryModel* queryModel = new QSqlQueryModel;

   QString SQL = "SELECT Contacts.CID, CNAME, CSURNAME, CTELEPHONECELL, CTELEPHONEHOME, ";
   SQL += "CEMAIL, CADDRESSPLZ, CADDRESSCITY, CADDRESSSTREET, CBIRTHDAY ";
   SQL += "FROM Contacts, ContactGroup ";
   SQL += "WHERE ContactGroup.CID = Contacts.CID AND ContactGroup.GID = ";
   SQL += QString::number(gid) + " ORDER BY CSURNAME";

   queryModel->setQuery(SQL, DAOLib::getDatabaseConnection());

   return queryModel;
}



// +--------------------------------------------------+
// |                     OTHER                        |
// +--------------------------------------------------+


qint64 AddressBookDAO::getLastIdentity()
{
   QString SQL = "SELECT @@IDENTITY";
   bool OK;

   QVariant identity = DAOLib::executeScalar(SQL, OK);

   if (!OK)
      return -1;
   else
      return identity.toLongLong();
}






