#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::connectUser(connection *con_user)
{
    client_connection = con_user;
    timer = new QTimer();
    client_connection->setMessage("");
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(5); //
    //client_connection->type = connection::REQUEST_TYPE::to_online;
    client_connection->getSocket()->write(QString("Connected "+user.getName()).toUtf8());
    client_connection->getSocket()->waitForReadyRead(50);
    client_connection->getSocket()->write("onl");
    client_connection->getSocket()->waitForReadyRead(50);
    //connect(client_connection->getSocket(), SIGNAL(readyRead()), this, SLOT(sockReady()), Qt::DirectConnection);
}
void MainWindow::setUser(User *u)
{
    this->user = *u;
}
void MainWindow::slotTimerAlarm()
{
    if(client_connection->type == connection::REQUEST_TYPE::del_online)
        ui->users_online->clear();
    else if(client_connection->type == connection::REQUEST_TYPE::to_online)
    {
        QList<QListWidgetItem*> match = ui->users_online->findItems(client_connection->getMessage(), Qt::MatchExactly);
        if(match.size() == 0)
            ui->users_online->addItem(client_connection->getMessage());
    }
    else if(client_connection->type == connection::REQUEST_TYPE::mes)
    {
        if(client_connection->getMessage() != "")
            ui->listWidget->addItem(client_connection->getMessage());
    }
    client_connection->type = connection::REQUEST_TYPE::no_update;
}

MainWindow::~MainWindow()
{
    delete client_connection;
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    user.setUserMessage(arg1);
}
void MainWindow::EnterPressed()
{
    this->on_SendButton_clicked();
}
bool MainWindow::isValidMessage(const QString &message)
{
    for(const auto &el : message)
    {
        if(!el.isSpace())
            return true;
    }
    return false;
}
void MainWindow::on_SendButton_clicked()
{
    if(isValidMessage(user.getUserMessage()))
    {
        QTime time = QTime::currentTime();
        //client_connection->type = connection::REQUEST_TYPE::mes;
        client_connection->getSocket()->write(QString(user.getUserMessage() + "\t" + user.getName()+"\t"+time.toString(Qt::SystemLocaleShortDate)).toUtf8());
        client_connection->getSocket()->waitForReadyRead(75);
        //ui->listWidget->addItem(client_connection->getMessage());
        //таймер аби обновлювало постійно
        //на сервер. а сервак назад повідомлення нв сокреді той що в мейні
    }
    ui->lineEdit->setText("\0");
}

/*void MainWindow::sockDisc() // server disconnected
{
    socket->deleteLater();
}
void MainWindow::sockReady()
{
    Data = client_connection->getSocket()->readAll();
    ui->listWidget->addItem(QString(Data));
}*/
