#include "connection.h"

connection::connection()
{
    socket=new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 1919);
    if(socket->waitForConnected(150))
    {
        sockets.push_back(socket);
        connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()), Qt::DirectConnection);
        connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()), Qt::DirectConnection);
        qDebug() << socket->socketDescriptor() << "Client connection init";
    }
    else
        socket->write("Can't connect!");
}
void connection::setMessage(QString message)
{
    this->message = message;
}

void connection::sockDisc() // server disconnected
{
    socket->deleteLater();
}
void connection::sockReady()
{
    QTcpSocket *senderSocket = dynamic_cast<QTcpSocket*>(sender());
    Data = senderSocket->readAll();
    QString text = QString(Data);
    if(text == "onl")
    {
        message="";
        return;
    }
    if(text == "delonl")
    {
        message="";
        type = REQUEST_TYPE::del_online;
        return;
    }
    message=text;
    qDebug()<<"from client "<<text;

    if(text=="User is exists")
    {
        message = "User is exists";
        type = REQUEST_TYPE::sys_mes;
        return;
    }
    else if(text=="User is not exists")
    {
        message = "User is not exists";
        type = REQUEST_TYPE::sys_mes;
    }
    else // mes to chat
    {
        QString newtext = text;
        if(newtext.contains("Connected "))
        {
            // видалити коннектед
            newtext.remove(0,QString("Connected ").size());
            message = newtext;

            type = REQUEST_TYPE::to_online;
            return;
        }
        if(text.size()>=90)
        {
            int size = text.size();
            int count = 1;
            while(size>=90)
            {
                newtext.insert(90*(count++)-1,'\n');
                size-=90;
            }
        }
        else
        {
            message = newtext;
            type = REQUEST_TYPE::mes;
        }
        qDebug()<<senderSocket->socketDescriptor()<<" from connection to mainwindow" << Data;
    }
}
QVector<QTcpSocket*> connection::getSockets()
{
    return sockets;
}
QTcpSocket* connection::getSocket()
{
    return socket;
}
QString connection::getMessage()
{
    return message;
}
