#include "User.h"

QString User::getName()
{
    return name;
}

QString User::getUserMessage()
{
    return usermessage;
}

QString User::getPassword()
{
    return password;
}
void User::setName(QString newname)
{
    name = newname;
}
void User::setUserMessage(QString newmessage)
{
    usermessage = newmessage;
}
void User::setPassword(QString newpassword)
{
    password = newpassword;
}
