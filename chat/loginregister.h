#ifndef LOGINREGISTER_H
#define LOGINREGISTER_H

#include <QWidget>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include "User.h"
#include "connection.h"
#include "SystemFunction.h"
#include <mainwindow.h>
namespace Ui {
class LoginRegister;
}

class LoginRegister : public QWidget
{
    Q_OBJECT

public:
    explicit LoginRegister(QWidget *parent = nullptr);
    ~LoginRegister();
    User user;
    void setOpenForAction(int action);
    void initSock();
private slots:
    void on_lineEditUsername_textChanged(const QString &arg1);

    void on_lineEditPassword_textChanged(const QString &arg1);

    void on_back_clicked();

    void on_AcceptUser_clicked();

    void on_showPassword_clicked();

signals:
    void firstWindow(int action);
private:
    Ui::LoginRegister *ui;
    int openForAction = 0;
    QTcpSocket *socket;
    QByteArray Data;
    QVector<QTcpSocket *>sockets;
    connection *client_connection;
    MainWindow *mainwindow;
};

#endif // LOGINREGISTER_H
