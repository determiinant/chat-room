/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstwindow
{
public:
    QPushButton *CreateChatRoom;
    QPushButton *ConnectToChatRoom;
    QFrame *framefirst;
    QFrame *framefirst_2;
    QPushButton *CreateChatRoom_2;
    QPushButton *ConnectToChatRoom_2;

    void setupUi(QWidget *firstwindow)
    {
        if (firstwindow->objectName().isEmpty())
            firstwindow->setObjectName(QString::fromUtf8("firstwindow"));
        firstwindow->resize(562, 629);
        firstwindow->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background:url(:/background.jpg);\n"
"}\n"
"QPushButton\n"
"{\n"
"font-family:century gothic;\n"
"background:#F08080	;\n"
"color:white;\n"
"font-size:24px;\n"
"border-radius:15px;\n"
"}\n"
"QFrame#framefirst\n"
"{\n"
"background:url(:/icon.png)\n"
"}"));
        CreateChatRoom = new QPushButton(firstwindow);
        CreateChatRoom->setObjectName(QString::fromUtf8("CreateChatRoom"));
        CreateChatRoom->setGeometry(QRect(110, 450, 351, 51));
        ConnectToChatRoom = new QPushButton(firstwindow);
        ConnectToChatRoom->setObjectName(QString::fromUtf8("ConnectToChatRoom"));
        ConnectToChatRoom->setGeometry(QRect(110, 520, 351, 51));
        framefirst = new QFrame(firstwindow);
        framefirst->setObjectName(QString::fromUtf8("framefirst"));
        framefirst->setGeometry(QRect(-10, 0, 581, 211));
        framefirst->setStyleSheet(QString::fromUtf8("background:url(:/icon.jpg)"));
        framefirst->setFrameShape(QFrame::NoFrame);
        framefirst->setFrameShadow(QFrame::Raised);
        framefirst_2 = new QFrame(framefirst);
        framefirst_2->setObjectName(QString::fromUtf8("framefirst_2"));
        framefirst_2->setGeometry(QRect(0, 0, 581, 211));
        framefirst_2->setFrameShape(QFrame::NoFrame);
        framefirst_2->setFrameShadow(QFrame::Raised);
        CreateChatRoom_2 = new QPushButton(framefirst);
        CreateChatRoom_2->setObjectName(QString::fromUtf8("CreateChatRoom_2"));
        CreateChatRoom_2->setGeometry(QRect(120, 450, 351, 51));
        ConnectToChatRoom_2 = new QPushButton(framefirst);
        ConnectToChatRoom_2->setObjectName(QString::fromUtf8("ConnectToChatRoom_2"));
        ConnectToChatRoom_2->setGeometry(QRect(120, 520, 351, 51));

        retranslateUi(firstwindow);

        QMetaObject::connectSlotsByName(firstwindow);
    } // setupUi

    void retranslateUi(QWidget *firstwindow)
    {
        firstwindow->setWindowTitle(QCoreApplication::translate("firstwindow", "Dialog", nullptr));
        CreateChatRoom->setText(QCoreApplication::translate("firstwindow", "LOGIN", nullptr));
        ConnectToChatRoom->setText(QCoreApplication::translate("firstwindow", "REGISTER", nullptr));
        CreateChatRoom_2->setText(QCoreApplication::translate("firstwindow", "CREATE CHATROOM", nullptr));
        ConnectToChatRoom_2->setText(QCoreApplication::translate("firstwindow", "CONNECT TO CHATROOM ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firstwindow: public Ui_firstwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
