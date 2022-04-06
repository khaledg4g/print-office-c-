#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{/*bool test=false;*/
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("system");
db.setPassword("rania44");

if (db.open())
/*test=true;*/
return true;
return false;



    /*  return  test;*/
}
