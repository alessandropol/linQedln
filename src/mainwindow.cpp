#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QLineEdit>
#include <QFormLayout>
#include <QtWidgets>
#include<QString>


#include"account.h"
#include"objsearch.h"
#include"database_3.h"
#include"basic.h"


#include"pageadmin.h"
#include"administrator.h"



MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("pagina login");
    resize(800,600);

    QWidget* paginaLogin=new QWidget(this);
    paginaLogin->setFixedSize(400,400);

    label1=new QLabel("utente");
    login= new QLineEdit("");

    label2=new QLabel("password");
    password= new QLineEdit("");
    password->setEchoMode(QLineEdit::Password);

    QPushButton* buttonLogin= new QPushButton("login");

    QHBoxLayout* layoutUtente=new QHBoxLayout();
    QHBoxLayout* layoutPassword=new QHBoxLayout();
    QVBoxLayout* contenitore=new QVBoxLayout();


    layoutUtente->addWidget(label1);
    layoutUtente->addWidget(login);

    layoutPassword->addWidget(label2);
    layoutPassword->addWidget(password);

    QSpacerItem* s1= new QSpacerItem(20,40);

    contenitore->addLayout(layoutUtente);
    contenitore->addLayout(layoutPassword);
    contenitore->addWidget(buttonLogin);
    contenitore->addItem(s1);
    paginaLogin->setLayout(contenitore);

    connect(buttonLogin,SIGNAL(clicked()),this,SLOT(inizializzazione()));
    connect(login,SIGNAL(returnPressed()),this,SLOT(inizializzazione()));
    connect(password,SIGNAL(returnPressed()),this,SLOT(inizializzazione()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inizializzazione()
{
    objsearch obj(login->text().toStdString());
    database_3* myDB=dynamic_cast<database_3*>(objsearch::DB);
    account* acc=myDB->ricercaDB(&obj).singleresult;
    if(acc!=0)
    {
        if(login->text().toStdString() == acc->get_username() && password->text().toStdString() == acc->get_password())
        {
            basic* utente=dynamic_cast<basic*>(acc);
            pageAccount* accountW=new pageAccount(utente);
            accountW->show();
            this->hide();
        }
     }
     else
     {
        objsearchAdmin objA(login->text().toStdString());
        acc=myDB->ricercaDB(&objA).singleresult;
        if(acc!=0)
        {
            if(login->text().toStdString() == acc->get_username() && password->text().toStdString() == acc->get_password())
            {
                 administrator* admin=dynamic_cast<administrator*>(acc);
                 pageAdmin* adminW=new pageAdmin(admin);
                 adminW->show();
                 this->hide();

            }
        }
        else
        {
            QMessageBox* error= new QMessageBox();
            error->setWindowTitle("errore");
            error->setText("account o password invalidi");
            error->setObjectName("login problem");
            error->exec();
        }
     }
}




