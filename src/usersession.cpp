#include "usersession.h"

UserSession* UserSession::instance = nullptr;


UserSession::UserSession()
{

}

UserSession::~UserSession()
{
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
