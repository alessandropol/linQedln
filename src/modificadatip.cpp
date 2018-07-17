#include "modificadatip.h"

#include<QHBoxLayout>
#include"infowidget.h"
#include"pageaccount.h"


modificaDatiP::modificaDatiP(basic* user,profiloWidget* PW, QWidget *parent): QWidget(parent),utente(user),profW(PW)

{
    this->setFixedSize(400,400);
    this->setWindowTitle("Modifica Dati Personali");

    residenza=new QLabel();
    residenzaLine=new QLineEdit();
    residenzaLine->setMaximumWidth(200);
    residenza->setText("Residenza:");

    nazionalita=new QLabel();
    nazionalitaLine=new QLineEdit();
    nazionalitaLine->setMaximumWidth(200);
    nazionalita->setText("Nazionalità:");

    domicilio=new QLabel();
    domicilioLine=new QLineEdit();
    domicilioLine->setMaximumWidth(200);
    domicilio->setText("Domicilio:");

    dataNascita=new QLabel();
    dataNascita->setText("Data di Nascita:");
    dataNascitaLine = new QDateEdit();
    dataNascitaLine->setDisplayFormat("dd.MM.yyyy");
    dataNascitaLine->setFixedWidth(110);


    nome=new QLabel();
    nome->setText("Nome:");
    nomeLine=new QLineEdit();
    nomeLine->setMaximumWidth(200);

    cognome=new QLabel();
    cognome->setText("Cognome:");
    cognomeLine=new QLineEdit();
    cognomeLine->setMaximumWidth(200);




    QHBoxLayout* resiLayout=new QHBoxLayout();
    QHBoxLayout* naziLayout=new QHBoxLayout();
    QHBoxLayout* domiLayout=new QHBoxLayout();
    QHBoxLayout* dataLayout=new QHBoxLayout();
    QHBoxLayout* nomeLayout=new QHBoxLayout();
    QHBoxLayout* cognomeLayout=new QHBoxLayout();

    resiLayout->addWidget(residenza);
    resiLayout->addWidget(residenzaLine);
    naziLayout->addWidget(nazionalita);
    naziLayout->addWidget(nazionalitaLine);
    domiLayout->addWidget(domicilio);
    domiLayout->addWidget(domicilioLine);
    dataLayout->addWidget(dataNascita);
    dataLayout->addWidget(dataNascitaLine);

    nomeLayout->addWidget(nome);
    nomeLayout->addWidget(nomeLine);
    cognomeLayout->addWidget(cognome);
    cognomeLayout->addWidget(cognomeLine);

    QVBoxLayout* datiLayout=new QVBoxLayout(this);
    datiLayout->addLayout(resiLayout);
    datiLayout->addLayout(naziLayout);
    datiLayout->addLayout(domiLayout);
    datiLayout->addLayout(dataLayout);
    datiLayout->addLayout(nomeLayout);
    datiLayout->addLayout(cognomeLayout);


    addButton=new QPushButton();
    addButton->setText("Modifica");
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(modSlot()));
    datiLayout->addWidget(addButton);

}

void modificaDatiP::modSlot()
{
    if(!nomeLine->text().isEmpty())
       utente->get_profilo()->get_datipersonali()->set_nome(nomeLine->text().toStdString());
    if(!cognomeLine->text().isEmpty())
        utente->get_profilo()->get_datipersonali()->set_cognome(cognomeLine->text().toStdString());
    if(!nazionalitaLine->text().isEmpty())
        utente->get_profilo()->get_datipersonali()->set_nazionalita(nazionalitaLine->text().toStdString());
    if(!domicilioLine->text().isEmpty())
        utente->get_profilo()->get_datipersonali()->set_domicilio(domicilioLine->text().toStdString());
    if(!residenzaLine->text().isEmpty())
        utente->get_profilo()->get_datipersonali()->set_residenza(residenzaLine->text().toStdString());
    if(!dataNascitaLine->text().isEmpty())
        utente->get_profilo()->get_datipersonali()->set_datanascita(dataNascitaLine->date());
    profW->createTab();

    pageAccount* pA=dynamic_cast<pageAccount*>(this->parent());
    infoWidget* infoW=dynamic_cast<infoWidget*>(pA->infoW);
    infoW->updateInfo();
    this->close();
}

