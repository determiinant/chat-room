#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include <QDialog>
#include <loginregister.h>
namespace Ui {
class firstwindow;
}

class firstwindow : public QWidget
{
    Q_OBJECT

public:
    explicit firstwindow(QWidget *parent = nullptr);
    firstwindow(QWidget *parent, int type);
    ~firstwindow();
    void back(int action);
    int getAction() const;

private slots:
    void on_CreateChatRoom_clicked();
    void on_ConnectToChatRoom_clicked();

private:
    Ui::firstwindow *ui;
    int openForAction = 0;
    LoginRegister *login;
};

#endif // FIRSTWINDOW_H
