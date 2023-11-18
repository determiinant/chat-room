#include "SystemFunction.h"

bool isValidName(const QString &name)
{
    if(name.size()==0)
        return false;
    for(const auto &el : name)
    {
        if(!el.isSpace())
            return true;
    }
    return false;
}

int isValidPassword(const QString& p)
{
       std::string password = p.toStdString();
       if(password.size()==0 || password.find(' ') != std::string::npos)
           return ERR::NOT_VALID;
       if (!((password.length() >= 8) && (password.length() <= 15)))
           return ERR::NOT_ENOUGH_CHARACTERS;
       int count = 0;
       for(int i = 0; i <= 9; i++)
       {
           std::string str1 = std::to_string(i);
           if (password.find(str1) != std::string::npos)
               count = 1;
       }
       if (count == 0)
           return ERR::NO_DIGITS;
       return -1;
}
