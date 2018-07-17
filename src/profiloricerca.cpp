#include "profiloricerca.h"

#include<QHBoxLayout>

#include"infowidget.h"
#include"profilocercato.h"
#include"infocercato.h"

profiloRicerca::profiloRicerca(basic* Ulog,basic* user,bool f,QWidget *parent) :
    QWidget(parent),utente(user)
{
    this->setFixedSize(450,680);
    this->setGeometry(320,0,0,0);

    IPwidget=new QWidget();

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::darkGreen);
    this->setAutoFillBackground(true);

    QVBoxLayout* boxPR=new QVBoxLayout(this);

    RPLabel=new QLabel();

    RPLabel->setText("PROFILO CERCATO");
    RPLabel->setStyleSheet("QLabel { color : white; }");
    RPLabel->setFixedWidth(450);
    RPLabel->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    RPLabel->setFont(font);

    infocercato* info=new infocercato(Ulog,utente,f);
    profiloCercato *profilo=new profiloCercato(utente);

    QVBoxLayout* box=new QVBoxLayout();
    box->addWidget(info);
    box->addWidget(profilo);


    boxPR->addWidget(RPLabel);
    boxPR->addWidget(IPwidget);
    boxPR->addLayout(box);



}
