#include "usersession.h"
using namespace bbb;

UserSession* UserSession::instance = nullptr;


UserSession::UserSession()
{

}

UserSession::~UserSession()
{
    // logout deletes the instance pointer
    logout();
}

UserSession* UserSession::getInstance()
{
    if(instance == nullptr)
    {
        instance = new UserSession();
    }
    return instance;
}


void UserSession::logout()
{
    if(instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void UserSession::setUsername(QString userName)
{
    this->userName = userName;
}


void UserSession::setPassword(QString password)
{
    this->password = password;
}


bool UserSession::validateSessionInfo()
{
    // sql query to check the passed name&pw to the values in the db.
    return true;
}
