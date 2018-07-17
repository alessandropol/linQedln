#include "infowidget.h"

#include"QHBoxLayout"



infoWidget::infoWidget(basic* acc,QWidget *parent) :    QWidget(parent),utente(acc)
{
       dati_personali* datiU= utente->get_profilo()->get_datipersonali();

       this->setFixedSize(370,150);
       this->setGeometry(10,10,0,0);

       QPalette Pal(palette());
       Pal.setColor(QPalette::Background, Qt::yellow);
       this->setAutoFillBackground(true);
       this->setPalette(Pal);

       titoloInfo=new QLabel(this);
       nomeLabel=new QLabel(this);
       cognomeLabel=new QLabel(this);
       friendLabel=new QLabel(this);

       nomeLine=new QLabel(this);
       cognomeLine=new QLabel(this);
       friendLine=new QLabel(this);

       titoloInfo->setText("INFO");
       titoloInfo->setAlignment(Qt::AlignCenter);
       titoloInfo->setFixedWidth(350);
       titoloInfo->setFixedHeight(40);
       QFont font;
       font.setBold(1);
       font.setPointSize(30);
       titoloInfo->setFont(font);

       nomeLabel->setText("Nome");
       cognomeLabel->setText("Cognome");
       friendLabel->setText("Numero di Amici");

       nomeLine->setText(QString::fromStdString(datiU->get_nome()));
       cognomeLine->setText(QString::fromStdString(datiU->get_cognome()));
       setNumeroAmici();

       QHBoxLayout* nomeLayout=new QHBoxLayout();
       QHBoxLayout* cognomeLayout=new QHBoxLayout();
       QHBoxLayout* usernameLayout=new QHBoxLayout();

       nomeLayout->addWidget(nomeLabel);
       nomeLayout->addWidget(nomeLine);

       cognomeLayout->addWidget(cognomeLabel);
       cognomeLayout->addWidget(cognomeLine);

       usernameLayout->addWidget(friendLabel);
       usernameLayout->addWidget(friendLine);


       QVBoxLayout* infoLayou=new QVBoxLayout(this);
       infoLayou->addWidget(titoloInfo);
       infoLayou->addLayout(nomeLayout);
       infoLayou->addLayout(cognomeLayout);
       infoLayou->addLayout(usernameLayout);

}

void infoWidget::setNumeroAmici()
{
    friendLine->setText(QString::number(utente->get_reteamici()->size()));
}

void infoWidget::updateInfo()
{
    dati_personali* datiU= utente->get_profilo()->get_datipersonali();
    nomeLine->setText(QString::fromStdString(datiU->get_nome()));
    cognomeLine->setText(QString::fromStdString(datiU->get_cognome()));
}

