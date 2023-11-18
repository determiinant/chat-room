#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User(){}
    ~User(){}
    QString getName();
    QString getUserMessage();
    QString getPassword();
    void setName(QString newname);
    void setUserMessage(QString newmessage);
    void setPassword(QString newpassword);
private:
    QString usermessage;
    QString name;
    QString password;
};

#endif // USER_H
