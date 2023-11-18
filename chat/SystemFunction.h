#ifndef SYSTEMFUNCTION_H
#define SYSTEMFUNCTION_H
#include <QString>
#include <QWidget>
#include <User.h>

enum ERR
{
    NOT_VALID = 1,
    NOT_ENOUGH_CHARACTERS = 2,
    NO_DIGITS = 3
};

bool isValidName(const QString &name);
int isValidPassword(const QString& p);

#endif // SYSTEMFUNCTION_H
