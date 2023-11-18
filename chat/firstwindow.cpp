#include "firstwindow.h"
#include "ui_firstwindow.h"

firstwindow::firstwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::firstwindow)
{

}
firstwindow::firstwindow(QWidget *parent, int type = 0) :
    QWidget(parent),
    ui(new Ui::firstwindow)
{
    openForAction = type;
    ui->setupUi(this);
    if(type == 1)
    {
        ui->ConnectToChatRoom->setText("CONNECT TO CHATROOM");
        ui->CreateChatRoom->setText("CREATE CHATROOM");
    }
    else if(type == 0)
    {
        ui->ConnectToChatRoom->setText("REGISTER");
        ui->CreateChatRoom->setText("LOGIN");

        login = new LoginRegister();
        connect(login, &LoginRegister::firstWindow, this, &firstwindow::back);
    }
}

int firstwindow::getAction() const
{
    return openForAction;
}
firstwindow::~firstwindow()
{
    delete ui;
}
void firstwindow::on_CreateChatRoom_clicked() // login
{
    if(this->getAction() == 0) //якщо спершу були кнопки логін і реєстрація
    {
        login->setOpenForAction(1);
        login->show();
        this->close();
    }
}

void firstwindow::on_ConnectToChatRoom_clicked() //register
{
    if(this->getAction() == 0) //якщо спершу були кнопки логін і реєстрація
    {
        login->setOpenForAction(2);
        login->show();
        this->close();
    }
}
void firstwindow::back(int action)
{
    openForAction = action;
    if(openForAction == 0)
    {
        ui->ConnectToChatRoom->setText("REGISTER");
        ui->CreateChatRoom->setText("LOGIN");
    }
    this->show();
}
