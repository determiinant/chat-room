#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>
#include <QDialog>
#include <QTime>
#include <QScrollArea>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "connection.h"
#include <QTimer>
#include <QTime>
#include <User.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setUser(User *u);
    void connectUser(connection *con_user);
    ~MainWindow();
private:
    User user;
    QByteArray Data;
    QVector<QTcpSocket *>sockets;

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_SendButton_clicked();
    void EnterPressed();
 //   void sockReady();
  //  void sockDisc();
    bool isValidMessage(const QString &message);
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> names; //показувати при кожних повідомленнях
    connection *client_connection;
    QTimer *timer;
};


#endif // MAINWINDOW_H
