#ifndef USERSESSION_H
#define USERSESSION_H

// showing / hiding the tool boxes is prob the best way to handle the auth
// or enabling or disabling

//*********************************************************************************
#include <QString>
#include <QDateTime>
//*********************************************************************************
#include "dbconnect.h"
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
        ROOT  = 0,  // can add users + ADMIN + USER
        ADMIN = 1,  // can change all item info + USER
        USER  = 2,  // can change item quantities and checkout gear + GUEST
        GUEST = 3   // can view inventory and make reports
    };
    //***********************************************************

    //***********************************************************
    struct AuthSessionInfo
    {
        QString authUserName;
        Roles   authUserRole;
        QDateTime loginTime;
    };
    //***********************************************************

    static QString userName;
    static QString password;

    static Roles userRole;
    //QDate expDate;

     static AuthSessionInfo getSessionInfoFromDb();
public:
    static UserSession* getInstance();
    static void logout();

    static void submitUsername(QString userName);
    static void submitPassword(QString password);
    static Roles getRoll();
    static bool validateSessionInfo();


}; // end class
//*********************************************************************************
} // end namespace
#endif // USERSESSION_H
