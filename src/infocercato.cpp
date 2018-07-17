#include "infocercato.h"

#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<infowidget.h>
#include<pageaccount.h>

infocercato::infocercato(basic* Ulog,basic* utente,bool f,QWidget *parent) :
    QWidget(parent),utenteINLog(Ulog),utenteCercato(utente)
{

    this->setFixedSize(370,150);
    this->setGeometry(320,0,0,0);


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::darkGreen);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    QLabel* titoloInfo=new QLabel(this);
    QLabel* nomeLabel=new QLabel(this);
    QLabel* cognomeLabel=new QLabel(this);


    QLabel* nomeLine=new QLabel(this);
    QLabel* cognomeLine=new QLabel(this);

    nomeLabel->setStyleSheet("QLabel { color : white; }");
    cognomeLabel->setStyleSheet("QLabel { color : white; }");



    titoloInfo->setText("INFO UTENTE");
    titoloInfo->setAlignment(Qt::AlignCenter);
    titoloInfo->setFixedWidth(350);
    titoloInfo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    titoloInfo->setFont(font);

    nomeLabel->setText("Nome:");
    cognomeLabel->setText("Cognome:");



    nomeLine->setText(QString::fromStdString(utente->get_profilo()->get_datipersonali()->get_nome()));
    cognomeLine->setText(QString::fromStdString(utente->get_profilo()->get_datipersonali()->get_cognome()));

    nomeLine->setStyleSheet("QLabel { color : red; }");
    cognomeLine->setStyleSheet("QLabel { color : red; }");


    QHBoxLayout* nomeLayout=new QHBoxLayout();
    QHBoxLayout* cognomeLayout=new QHBoxLayout();


    nomeLayout->addWidget(nomeLabel);
    nomeLayout->addWidget(nomeLine);

    cognomeLayout->addWidget(cognomeLabel);
    cognomeLayout->addWidget(cognomeLine);


    QHBoxLayout* boxFriend=new QHBoxLayout();
    QPushButton* friendB=new QPushButton();
    friendB->setText("Aggiungi / Rimuovi Amico");
    friendB->setFixedWidth(200);
    check=new QCheckBox();
    check->setChecked(f);
    check->setDisabled(1);

    boxFriend->addWidget(friendB);
    boxFriend->addWidget(check);


    QVBoxLayout* infoLayou=new QVBoxLayout(this);
    infoLayou->addWidget(titoloInfo);
    infoLayou->addLayout(nomeLayout);
    infoLayou->addLayout(cognomeLayout);
    infoLayou->addLayout(boxFriend);

     connect(friendB, SIGNAL(clicked(bool)),this, SLOT(ARfriend()));
     //connect(friendB, SIGNAL(clicked(bool)),infoWidget(), SLOT(ARfriend()));



}

void infocercato::ARfriend()
{
    if(check->isChecked())
    {
        check->setChecked(0);
        utenteINLog->delete_friend(utenteCercato);
    }
    else
    {
        check->setChecked(1);
        utenteINLog->add_friend(utenteCercato);
    }

    pageAccount* page=dynamic_cast<pageAccount*>(this->parentWidget()->parentWidget()->parentWidget());
    infoWidget* pointer=dynamic_cast<infoWidget*>(page->infoW);
    pointer->setNumeroAmici();
}
