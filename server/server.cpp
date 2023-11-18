#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("mydb");
    db.setUserName("root");
    db.setPassword("t@rgarienn2056");
    if(!db.open())
        qDebug()<<db.lastError().text();
    else
        qDebug()<<"Sucsess!";
    //зєднуємось з сервером
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection,this,&Server::Connection);
    if(tcpServer->listen(QHostAddress::Any,1919))//QHostAdress - адреса по якій запущений сервер
        qDebug()<<"Listening...";
    else
        qDebug()<<"Not listening";
}
Server::~Server(){}

void Server::Connection()
{
    socket = tcpServer->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()),this, SLOT(sockReady()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()),Qt::DirectConnection);

    qDebug() << socket->socketDescriptor() << " Client connected";
    sockets.insert(socket);
}

void Server::sockReady()
{
    QTcpSocket *senderSocket = dynamic_cast<QTcpSocket*>(sender());
  //  sockets.push_back(senderSocket);
    QByteArray data = senderSocket->readAll();
    QString stream = QString(data);
    qDebug()<<"Server read:" << data;
    if(stream.contains("reg"))
    {
        QPair<QString, QString> p = removeString(stream, "reg");
        QSqlQuery query = QSqlQuery(db);
        QString str  = QString("SELECT EXISTS (SELECT * FROM users WHERE Username = '%1');").arg(p.first);
        qDebug()<<"Username "<<p.first;
        qDebug()<<"Password "<<p.second;
        query.prepare(str);
        query.exec();
        query.next();
        if(query.value(0)!=0)
        {
            qDebug()<<"User is exists";
            socket->write("User is exists");
        }
        else
        {
            qDebug()<<"User is not exists";
            query.prepare("INSERT INTO  users (Username, Pass) VALUES(?, ?)"); // подготавливаем запрос
            query.addBindValue(p.first);// заполняем вопросительные знаки значениями
            query.addBindValue(p.second);
            if (!query.exec()) // выполняем готовый запрос
                qDebug()<<query.lastError().databaseText();
            else
            {
                qDebug()<<"User add into db";
                senderSocket->write("User add into db");
            }
        }
    }
    else if(stream.contains("log"))
    {
        QPair<QString, QString> p = removeString(stream, "log");
        QSqlQuery query= QSqlQuery(db);
        QString str = QString("SELECT EXISTS (SELECT * FROM users WHERE Username = '%1' AND Pass = '%2');").arg(p.first, p.second);
        qDebug()<<"Username "<<p.first;
        qDebug()<<"Password "<<p.second;
        query.prepare(str);
        query.exec();
        query.next();
        if(query.value(0)!=0)
        {
            qDebug()<<"User is find, login sucsessfull";
            senderSocket->write("User is find");
        }
        else
        {
            qDebug()<<"User is not find, login failed";
            senderSocket->write("User is not find");
        }
    }
    else if(stream.contains("onl"))
    {
        for(auto el : sockets)
        {
            for(auto i = users.begin();i!=users.end();++i)
            {
                qDebug() << "Send user" << "Connected "+ i.value().toUtf8();
                el->write("Connected "+ i.value().toUtf8());
                el->waitForReadyRead(50);
            }
        }
    }
    else
    {
        if(stream.contains("Connected "))
        {
            QString st =stream;
            st.remove(0,QString("Connected ").size());
            users[senderSocket] = st;
        }
        qDebug()<<senderSocket->socketDescriptor()<<" Data in "<< data;
        for(auto el : sockets)
            el->write(data);
    }
}
void Server::sockDisc() // user disconnected
{
    for(auto el = sockets.begin();el!=sockets.end();++el)
    {
        if((*el)->socketDescriptor() == -1)
            sockets.erase(el);
    }
    for(auto el = users.begin();el!=users.end();++el)
    {
        if((el.key())->socketDescriptor() == -1)
            users.erase(el);
    }
    for(auto el : sockets)
    {
        el->write("delonl");
        el->waitForReadyRead(50);
        for(auto i = users.begin();i!=users.end();++i)
        {
            qDebug() << "Send user" << i.value().toUtf8();
            el->write("Connected "+ i.value().toUtf8());
            el->waitForReadyRead(50);
        }
    }
    qDebug() <<" Disconnect";

   // sockets[j]->close();
 //   sockets.erase(sockets.find(socket));
   // (*sockets.find(socket))->close();
}
QPair<QString, QString> Server::removeString(QString &stream, QString rem)
{
    QPair<QString, QString> p;
    stream.remove(rem+" ");
    int pos = 0;
    QString username, password;
    for(int i =0;i<stream.size();++i)
    {
        if(stream[i]!=" ")
            username+=stream[i];
        else
        {
            pos = i;
            break;
        }
    }
    for(int i=pos+1;i<stream.size();++i)
        password+=stream[i];
    p.first=username;
    p.second=password;
    return p;
}
