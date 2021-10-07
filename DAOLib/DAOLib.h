#ifndef DAOLIB_H
#define DAOLIB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QMessageBox>
#include <QDate>

#include "DAOLib_global.h"

class DAOLIB_EXPORT DAOLib
{
public:
    // Logowanie do bazy danych za pomocą uwierzytelniania Windows
    static bool connectToDatabase(const QString &driver,
                                  const QString &driverName,
                                  const QString &hostName,
                                  const QString &databaseName);
    static bool connectToDatabase(const QString &driver,
                                  const QString &hostName,
                                  const QString &userName,
                                  const QString &password,
                                  const QString &databaseName);

    static void closeConnection();
    static QSqlDatabase getDatabaseConnection();
    static QString getDatabaseName();
    static QString dbString(QString value);
    static QString dbDate(QDate date);

    static int executeNonQuery(const QString &sql);
    static QVariant executeScalar(const QString &sql, bool &ok);
    static QSqlQuery *executeQuery(const QString &sql, bool &ok);

private:

    // Prywatny konstruktor uniemożliwia utworzenie tej klasy.
    DAOLib();

    // Wszystkie metody są statyczne.
    static QSqlDatabase dbConnection;
    static QString serverName;
    static QString dbName;

};

#endif // DAOLIB_H
