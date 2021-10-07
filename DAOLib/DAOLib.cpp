#include "DAOLib.h"

// Inicjalizacja statycznych zmiennych
QSqlDatabase DAOLib::dbConnection = QSqlDatabase();
QString DAOLib::serverName = QString();
QString DAOLib::dbName = QString();

// Inicjalizacja konstruktora klasy
DAOLib::DAOLib()
{
}

// Laczy z baza danych zwraca true gdy polaczono
bool DAOLib::connectToDatabase(const QString &driver, 
							   const QString &driverName,
							   const QString &hostName,
							   const QString &databaseName)
{
	bool isDBOpen = false;

	// Tworzy ciąg połączenia do MSSQL Serwer
	QString connectionString = driverName + ";";
	connectionString += "Server=" + hostName + ";";
	connectionString += "Database=" + databaseName + ";";

	// W przypadku uwierzytelniania systemu Windows
	connectionString += "Trusted_Connection=Yes;";

	dbConnection = QSqlDatabase::addDatabase(driver, databaseName);

	// Przypisuje ciag polaczenia
	dbConnection.setDatabaseName(connectionString);

	// Sprawdza czy polaczono
	isDBOpen = dbConnection.open();

	dbName = QString();
	serverName = QString();

	if (!isDBOpen)
	{
		QMessageBox::critical(nullptr, "Error: Database",
							  QString("Error opening the database: %1")
							  .arg(dbConnection.lastError().text()));
	}
	else
	{
		dbName = databaseName;
		serverName = hostName;
	}

	return isDBOpen;

}

// Do serwera MySQL np. connectToDatabase("QMYSQL", "localhost:3306", "root", "", "baza");
bool DAOLib::connectToDatabase(const QString &driver,
							   const QString &hostName,
							   const QString &userName,
							   const QString &password,
							   const QString &databaseName)
{
	bool isDBOpen = false;

	// Tworzy ciąg połączenia do MySQL Serwer
	dbConnection = QSqlDatabase::addDatabase(driver);
	dbConnection.setHostName(hostName);
	dbConnection.setUserName(userName);
	dbConnection.setPassword(password);

	// Przypisuje ciag polaczenia
	dbConnection.setDatabaseName(databaseName);

	// Sprawdza czy polaczono
	isDBOpen = dbConnection.open();

	dbName = QString();
	serverName = QString();

	if (!isDBOpen)
	{
		QMessageBox::critical(nullptr, "Error: Database",
							  QString("Error opening the database: %1")
							  .arg(dbConnection.lastError().text()));
	}
	else
	{
		dbName = databaseName;
		serverName = hostName;
	}

	return dbConnection.open();

}

// Zamyka polaczenie z baza danych
void DAOLib::closeConnection()
{
	dbConnection.close();
}

// Zwraca prywatna oraz statyczna zmienna
QSqlDatabase DAOLib::getDatabaseConnection()
{
	return dbConnection;
}

// Zwraca prywatna oraz statyczna zmienna
QString DAOLib::getDatabaseName()
{
	return dbName;
}

// Zwraca lancuch i zastepuje kazde wystapienie (') w ciagu znakow
// cudzyslow, podwojnym cudzyslowem ('')
QString DAOLib::dbString(QString value)
{
    return "'" + value.replace("'", "''") + "'";
}

// Zwraca date w postaci ciagu znakow, np. 2021-09-03
QString DAOLib::dbDate(QDate datum)
{
    return dbString(datum.toString("yyyy-MM-dd"));
}

// Zwraca liczbe wierszy z pytania do bazy danych
// W przypadku bledu pytania zwroci wartosc -1
int DAOLib::executeNonQuery(const QString &sql)
{

    int retValue = -1;

    QSqlQuery query = QSqlQuery(dbConnection);

    if (!query.exec(sql))
        QMessageBox::critical(nullptr, "Error: SQL",
                              QString("Error accessing the database: %1")
                              .arg(query.lastError().text()));
    else
        retValue = query.numRowsAffected();

    return retValue;

}

// Tworzy Variant danych (jakiegos nieznanego typu) oraz
// zwraca te dane gdy wystapi blad polaczenia z baza danych
QVariant DAOLib::executeScalar(const QString &sql, bool &ok)
{
    ok = false;
    QVariant retValue = 0;

    QSqlQuery query = QSqlQuery(dbConnection);
    bool qryValue = query.exec(sql);

    if (!qryValue)
    {
        QMessageBox::critical(nullptr, "Error: SQL",
                              QString("Error accessing the database: %1")
                              .arg(query.lastError().text()));
        return retValue;
    }

    // Ustawia pozycje na pierwszym zapisie danych
    query.first();
    ok = true;

    return query.value(0);

}

// Realizuje zapytanie do bazy danych
QSqlQuery *DAOLib::executeQuery(const QString &sql, bool &ok)
{
    QSqlQuery *query = new QSqlQuery(dbConnection);
    ok = query->exec(sql);
    return query;

}





