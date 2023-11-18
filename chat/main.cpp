#include "firstwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    firstwindow window(nullptr, 0);
    window.setWindowTitle("Chat");
    window.setWindowIcon(QIcon("iconchat.ico"));
    window.show();
    return a.exec();
}
