#include "a_eliminautente.h"
#include<QLabel>
#include<QHBoxLayout>
#include"risultatocognome.h"

a_eliminaUtente::a_eliminaUtente(administrator* ad,basic* b, QWidget* p, QWidget *parent) :
    QWidget(parent),admin(ad),utente(b),padreC(parent)
{

    this->setFixedSize(690,70);
    this->setGeometry(0,70,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    QLabel* titoloInfo=new QLabel();

    titoloInfo->setText("ELIMINA UTENTE");
    titoloInfo->setFixedWidth(350);
    titoloInfo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    titoloInfo->setFont(font);

    delButton=new QPushButton();
    delButton->setText("ELIMINA UTENTE");
    delButton->setFixedHeight(50);


    QHBoxLayout* infoLayou=new QHBoxLayout(this);
    infoLayou->addWidget(titoloInfo);
    infoLayou->addWidget(delButton);

    connect(delButton, SIGNAL(clicked()), this, SLOT(delUtente()));
    connect(delButton, SIGNAL(clicked()),p,SLOT(chiudi()));

}

void a_eliminaUtente::delUtente()
{
    admin->elimina_account(utente);
    delButton->setDisabled(1);
    padreC->close();

}
