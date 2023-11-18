#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSslSocket>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
class Server : public QObject
{
    Q_OBJECT
public:
     Server(QObject *parent = 0);
    ~Server();
    QSet<QTcpSocket*> sockets; //сокети всіх клієнтів

    QMap<QTcpSocket*, QString> users;
    QTcpSocket *socket; //сокет клієнта
    QTcpServer *tcpServer;
    QByteArray Data; //дані які ми будемо відправляти по сокету в мережу
    QString username;
public slots:
    void Connection(); //опис дій  в випадку підключення нового клієнта
    //socket_fd - унікальний номер нашого зєднання
    void sockReady();//готовність сокета читати дані
    void sockDisc(); //відключення клієнта від сокета
    QPair<QString, QString> removeString(QString &stream, QString rem);
private:
    QSqlDatabase db;
};

#endif // SERVER_H
