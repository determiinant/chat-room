#include "loginregister.h"
#include "ui_loginregister.h"
#include <firstwindow.h>
LoginRegister::LoginRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginRegister)
{
    /*
    socket=new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()), Qt::DirectConnection);
    socket->connectToHost("127.0.0.1", 1919);
    sockets.push_back(socket);
    */
    ui->setupUi(this);

    ui->labelErrorUsername->hide();
    ui->labelErrorPassword->hide();
    ui->lineEditMessage->hide();
    initSock();
}
void LoginRegister::initSock()
{
    client_connection = new connection();
}

LoginRegister::~LoginRegister()
{
    delete client_connection;
    delete ui;
}

void LoginRegister::on_lineEditUsername_textChanged(const QString &arg1)
{
    this->user.setName(arg1);
}

void LoginRegister::on_lineEditPassword_textChanged(const QString &arg1)
{
    this->user.setPassword(arg1);
}

void LoginRegister::on_back_clicked()
{
    this->close();
    emit firstWindow(0);
}

void LoginRegister::on_AcceptUser_clicked()
{
    // call auth() or reg() and write in db
    // 1 - auth
    // 2 - reg

    if(!isValidName(user.getName()))
        ui->labelErrorUsername->show();
    else
        ui->labelErrorUsername->hide();

    if(isValidPassword(user.getPassword())==1)
    {
        ui->labelErrorPassword->setText("Error. Enter valid password");
        ui->labelErrorPassword->show();
    }
    else if(isValidPassword(user.getPassword())==2)
    {
        ui->labelErrorPassword->setText("Password must be at least 8 characters");
        ui->labelErrorPassword->show();
    }
    else if(isValidPassword(user.getPassword())==3)
    {
        ui->labelErrorPassword->setText("Password must contain at least one digit");
        ui->labelErrorPassword->show();
    }
    else
        ui->labelErrorPassword->hide();
    if(isValidName(user.getName()) && isValidPassword(user.getPassword())==-1)
    {
        bool check = false;
        if(openForAction==2)//якщо була нажата кнопка реєстрації
        {
            qDebug() << "client_connection send to server: " << QString("reg "+user.getName()+" "+user.getPassword()).toUtf8();
            client_connection->getSocket()->write(QString("reg "+user.getName()+" "+user.getPassword()).toUtf8());
            if(client_connection->getSocket()->waitForReadyRead(150))
            {
                qDebug() << "response from server: "<< client_connection->getMessage();
                ui->lineEditMessage->setText(client_connection->getMessage());
                if(ui->lineEditMessage->text()=="User is exists")
                {
                    ui->lineEditMessage->show();
                    check=true;
                }
                else
                {
                    ui->lineEditMessage->hide();
                    check=false;
                }
            }
        }
        else if(openForAction==1)
        {
            client_connection->getSocket()->write(QString("log "+user.getName()+" "+user.getPassword()).toUtf8());
            qDebug() << "client_connection send to server: " << QString("log "+user.getName()+" "+user.getPassword()).toUtf8();
            if(client_connection->getSocket()->waitForReadyRead(150))
            {
                ui->lineEditMessage->setText(client_connection->getMessage());
                qDebug() << "response from server: "<< client_connection->getMessage();
                if(ui->lineEditMessage->text()=="User is find")
                {
                    ui->lineEditMessage->hide();
                    check=false;
                }
                else
                {
                    ui->lineEditMessage->show();
                    check=true;
                }
            }
        }
        if(!check)
        {
            mainwindow = new MainWindow();
            mainwindow->setUser(&this->user);
            mainwindow->connectUser(client_connection);
            mainwindow->show();
            this->close();
            //emit firstWindow(1);
            //this->close();
        }
    }
}

void LoginRegister::on_showPassword_clicked()
{
     ui->lineEditPassword->setEchoMode(ui->showPassword->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}

void LoginRegister::setOpenForAction(int action)
{
    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
    ui->labelErrorUsername->hide();
    ui->labelErrorPassword->hide();
    ui->lineEditMessage->hide();
    openForAction = action;
    if(openForAction == 1)
        ui->AcceptUser->setText("LOGIN");
    else if(openForAction == 2)
        ui->AcceptUser->setText("REGISTER");
}

/*void LoginRegister::sockDisc() // server disconnected
{
    socket->deleteLater();
}
void LoginRegister::sockReady()
{
    Data = socket->readAll();
    QString text = QString(Data);
    qDebug()<<socket->socketDescriptor()<<" from loginregister "<<text;
    if(text=="User is exists")
        ui->lineEditMessage->setText("User is exists");
    else if(text=="User add into db")
        ui->lineEditMessage->setText("User add into db");
    else if(text=="User is find")
        ui->lineEditMessage->setText("User is find");
    else if(text=="User is not find")
        ui->lineEditMessage->setText("User is not find");
} */
