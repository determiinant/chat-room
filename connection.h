#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>

class connection : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QByteArray Data;
    QVector<QTcpSocket *>sockets;
    QString message;

public:
    connection();
    enum REQUEST_TYPE
    {
        del_online = -2,
        no_update = -1,
        sys_mes, // 0
        mes, // 1
        to_online,  // 2
        //can add log, reg
    };
    QTcpSocket * getSocket();
    QVector<QTcpSocket*> getSockets();
    QString getMessage();
    REQUEST_TYPE type;
    void setMessage(QString message);

private slots:

    void sockReady();
    void sockDisc();
};

#endif // CONNECTION_H
