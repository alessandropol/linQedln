#include "pageadmin.h"
#include"infowidget.h"
#include"profilowidget.h"
#include"ricercawidget.h"
#include<QPushButton>
#include<QHBoxLayout>
#include<mainwindow.h>
#include"objsearch.h"
#include"database_3.h"

#include"a_infowidget.h"
#include"a_insertaccount.h"
#include"a_ricercawidget.h"

pageAdmin::pageAdmin(administrator* admin,QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("account administrator: Benvenuto");
    setFixedSize(1110,720);
    //setFixedSize(1110,720);
    QWidget* client_page=new QWidget(this);
    client_page->setObjectName("client_page");
    client_page->setFixedSize(800,600);

    A_infoWidget* info=new A_infoWidget(admin,this);
    info->show();

    a_insertAccount* insert=new a_insertAccount(admin,this);
    insert->show();


    a_ricercaWidget* ricerca=new a_ricercaWidget(admin,this);
    ricerca->show();//SISTEMARE RICECA CNO ELIMINA


    QPushButton* exit=new QPushButton(this);
    exit->setText("USCITA");
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    exit->setFixedHeight(25);
    exit->setFixedWidth(130);
    exit->setGeometry(970,692,40,40);
    exit->setFont(font);
    exit->show();

    connect(exit, SIGNAL(clicked()), this, SLOT(saveDB()));

}


void pageAdmin::saveDB()
{
   objsearch::DB->scriviDB();
   MainWindow* mw=new MainWindow();
   mw->show();
   this->close();
}

