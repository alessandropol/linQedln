#include "a_infowidget.h"
#include<QHBoxLayout>


A_infoWidget::A_infoWidget(administrator* acc,QWidget *parent) :    QWidget(parent),admin(acc)
{

    this->setFixedSize(370,150);
    this->setGeometry(10,10,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::blue);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    titoloInfo=new QLabel(this);
    nomeLabel=new QLabel(this);
    cognomeLabel=new QLabel(this);
    ruoloLabel=new QLabel(this);

    nomeLine=new QLabel(this);
    cognomeLine=new QLabel(this);
    ruoloLine=new QLabel(this);

    titoloInfo->setText("INFO");
    titoloInfo->setAlignment(Qt::AlignCenter);
    titoloInfo->setFixedWidth(350);
    titoloInfo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    titoloInfo->setFont(font);

    nomeLabel->setText("Nome:");
    cognomeLabel->setText("Cognome:");
    ruoloLabel->setText("Ruolo:");

    nomeLine->setText(QString::fromStdString(admin->get_nome()));
    cognomeLine->setText(QString::fromStdString(admin->get_cognome()));
    ruoloLine->setText(QString::fromStdString(admin->get_ruolo()));


    QHBoxLayout* nomeLayout=new QHBoxLayout();
    QHBoxLayout* cognomeLayout=new QHBoxLayout();
    QHBoxLayout* ruoloLayout=new QHBoxLayout();

    nomeLayout->addWidget(nomeLabel);
    nomeLayout->addWidget(nomeLine);

    cognomeLayout->addWidget(cognomeLabel);
    cognomeLayout->addWidget(cognomeLine);

    ruoloLayout->addWidget(ruoloLabel);
    ruoloLayout->addWidget(ruoloLine);


    QVBoxLayout* infoLayou=new QVBoxLayout(this);
    infoLayou->addWidget(titoloInfo);
    infoLayou->addLayout(nomeLayout);
    infoLayou->addLayout(cognomeLayout);
    infoLayou->addLayout(ruoloLayout);

}



