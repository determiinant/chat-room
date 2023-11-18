/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *SendButton;
    QListWidget *listWidget;
    QListWidget *users_online;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(985, 638);
        QIcon icon;
        icon.addFile(QString::fromUtf8("iconchat.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"font-family:century gothic;\n"
"font-size:24px;\n"
"}\n"
"QListWidget\n"
"{\n"
"background:#333;\n"
"color:#717072;\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 510, 761, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("century gothic"));
        lineEdit->setFont(font);
        SendButton = new QPushButton(centralwidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setGeometry(QRect(770, 510, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("century gothic"));
        font1.setBold(true);
        font1.setWeight(75);
        SendButton->setFont(font1);
        SendButton->setAutoDefault(true);
        SendButton->setFlat(false);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 761, 511));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"background:white;\n"
"}"));
        listWidget->setFlow(QListView::TopToBottom);
        users_online = new QListWidget(centralwidget);
        users_online->setObjectName(QString::fromUtf8("users_online"));
        users_online->setGeometry(QRect(770, 0, 191, 511));
        users_online->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"background-color:white;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 985, 35));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), lineEdit, SLOT(setText(QString)));

        SendButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
