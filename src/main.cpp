#include "mainwindow.h"
#include <QApplication>
#include"objsearch.h"
#include"database_3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    objsearch::DB->leggiDB();
    MainWindow w;
    w.show();
    return a.exec();
}
