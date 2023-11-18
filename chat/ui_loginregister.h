/********************************************************************************
** Form generated from reading UI file 'loginregister.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINREGISTER_H
#define UI_LOGINREGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginRegister
{
public:
    QToolButton *toolButton;
    QFrame *frame;
    QPushButton *AcceptUser;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLabel *labelErrorUsername;
    QLabel *labelErrorPassword;
    QCheckBox *showPassword;
    QLineEdit *lineEditMessage;
    QPushButton *back;

    void setupUi(QWidget *LoginRegister)
    {
        if (LoginRegister->objectName().isEmpty())
            LoginRegister->setObjectName(QString::fromUtf8("LoginRegister"));
        LoginRegister->resize(788, 712);
        LoginRegister->setStyleSheet(QString::fromUtf8("*{\n"
"font-family:century gothic;\n"
"font-size:24px;\n"
"}\n"
"QFrame\n"
"{\n"
"background:#333		;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:#F08080	;;\n"
"border-radius:15px;\n"
"}\n"
"QToolButton\n"
"{\n"
"background:#F08080	;;\n"
"border-radius:60px;\n"
"}\n"
"QLabel\n"
"{\n"
"color:white;\n"
"font-size:18px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color:#333;\n"
"border-radius:15px;\n"
"background:#ffffff	;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#717072;\n"
"border-bottom:1px solid #717072;\n"
"}\n"
"QPushButton#back\n"
"{\n"
"border-radius:20px;\n"
"}"));
        toolButton = new QToolButton(LoginRegister);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(320, 100, 121, 121));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/usericon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(64, 64));
        frame = new QFrame(LoginRegister);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(90, 160, 611, 471));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        AcceptUser = new QPushButton(frame);
        AcceptUser->setObjectName(QString::fromUtf8("AcceptUser"));
        AcceptUser->setGeometry(QRect(90, 400, 401, 41));
        lineEditUsername = new QLineEdit(frame);
        lineEditUsername->setObjectName(QString::fromUtf8("lineEditUsername"));
        lineEditUsername->setGeometry(QRect(70, 140, 461, 41));
        lineEditPassword = new QLineEdit(frame);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(70, 250, 461, 41));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        labelErrorUsername = new QLabel(frame);
        labelErrorUsername->setObjectName(QString::fromUtf8("labelErrorUsername"));
        labelErrorUsername->setGeometry(QRect(70, 190, 461, 21));
        labelErrorPassword = new QLabel(frame);
        labelErrorPassword->setObjectName(QString::fromUtf8("labelErrorPassword"));
        labelErrorPassword->setGeometry(QRect(70, 310, 461, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("century gothic"));
        labelErrorPassword->setFont(font);
        showPassword = new QCheckBox(frame);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(470, 260, 61, 21));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        showPassword->setIcon(icon1);
        lineEditMessage = new QLineEdit(frame);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        lineEditMessage->setGeometry(QRect(82, 360, 381, 24));
        back = new QPushButton(LoginRegister);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(30, 40, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon2);
        back->raise();
        frame->raise();
        toolButton->raise();

        retranslateUi(LoginRegister);

        QMetaObject::connectSlotsByName(LoginRegister);
    } // setupUi

    void retranslateUi(QWidget *LoginRegister)
    {
        LoginRegister->setWindowTitle(QCoreApplication::translate("LoginRegister", "Dialog", nullptr));
        toolButton->setText(QCoreApplication::translate("LoginRegister", "...", nullptr));
        AcceptUser->setText(QCoreApplication::translate("LoginRegister", "OK", nullptr));
        lineEditUsername->setText(QString());
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("LoginRegister", "Username", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("LoginRegister", "Password", nullptr));
        labelErrorUsername->setText(QCoreApplication::translate("LoginRegister", "Error. Enter valid username", nullptr));
        labelErrorPassword->setText(QCoreApplication::translate("LoginRegister", "Error. Enter valid password", nullptr));
        showPassword->setText(QString());
        back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginRegister: public Ui_LoginRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINREGISTER_H
