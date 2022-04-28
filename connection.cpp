#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("rania44");//inserer mot de passe de cet utilisateur

if (db.open())
    return true;
        return false;
}
void Connection::closeconnect()
{db.close();}
