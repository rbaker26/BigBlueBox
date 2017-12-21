#ifndef USERSESSION_H
#define USERSESSION_H

//*********************************************************************************
#include <QString>
#include <QDate>
//*********************************************************************************

namespace bbb {
//*********************************************************************************
class UserSession
{
private:
    UserSession();
    ~UserSession();
    static UserSession* instance;

    //***********************************************************
    enum Roles
    {
        ROOT  = 0, // can add users + ADMIN + USER
        ADMIN = 1, // can change all item info + USER
        USER  = 2  // can change item quantities and checkout gear
    };
    //***********************************************************

    QString userName;
    QString password;

    Roles userRole;
    //QDate expDate;

public:
    static UserSession* getInstance();
    static void logout();

    void setUsername(QString userName);
    void setPassword(QString password);
    bool validateSessionInfo();

}; // end class
//*********************************************************************************
} // end namespace
#endif // USERSESSION_H
