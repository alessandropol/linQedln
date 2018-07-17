 #include "modificaexp.h"



#include<QHBoxLayout>
#include<string>
#include"data.h"
#include"profilowidget.h"

modificaExp::modificaExp(QWidget *parent): QWidget(parent){}

modificaExp::modificaExp(basic* user,profiloWidget* PW, QWidget *parent): QWidget(parent),utente(user),profW(PW)
{
    this->setFixedSize(400,400);
    this->setWindowTitle("Modifica Esperienza");

    QVBoxLayout* boxModifica=new QVBoxLayout(this);

    QHBoxLayout* boxElimina=new QHBoxLayout();
    elimina=new QLabel();
    elimina=new QLabel();
    elimina->setText("Elimina esperienza");

    profilo_2 * pf2=dynamic_cast<profilo_2*>(utente->get_profilo());
    vector<esperienza*>* VE=pf2->get_esperienze();
    vector<esperienza*>::iterator it=VE->begin();
    esperienza* exp;

    combo=new QComboBox();

    for(;it!=VE->end();++it)
    {
        exp=(*it);
        combo->addItem(QString::fromStdString(exp->get_azienda()));
    }


    delButton=new QPushButton();
    delButton->setText("elimina");

    boxElimina->addWidget(elimina);
    boxElimina->addWidget(combo);
    boxElimina->addWidget(delButton);    

    aggiungi=new QLabel();
    aggiungi->setText("Aggiungi Esperienza");

    boxModifica->addLayout(boxElimina);
    boxModifica->addWidget(aggiungi);

    QHBoxLayout* boxNome=new QHBoxLayout();
    nomeAzienda=new QLabel();
    nomeAzienda->setText("Nome Azienda");
    nomeAziendaLine=new QLineEdit();
    nomeAziendaLine->setMaximumWidth(200);
    boxNome->addWidget(nomeAzienda);
    boxNome->addWidget(nomeAziendaLine);

    QHBoxLayout* boxInizio=new QHBoxLayout();

    dataInizio=new QLabel();
    dataInizio->setText("Data Inizio");

    dataInizioLine = new QDateEdit();


    //dataI->setFixedWidth(170);
    dataInizioLine->setDisplayFormat("dd.MM.yyyy");
    dataInizioLine->setFixedWidth(110);

    boxInizio->addWidget(dataInizio);
    boxInizio->addWidget(dataInizioLine);


    QHBoxLayout* boxFine=new QHBoxLayout();
    dataFine=new QLabel();
    dataFine->setText("Data Fine");
    dataFineLine = new QDateEdit();
    dataFineLine->setDisplayFormat("dd.MM.yyyy");
    dataFineLine->setFixedWidth(110);

    boxFine->addWidget(dataFine);
    boxFine->addWidget(dataFineLine);

    QHBoxLayout* boxRuolo=new QHBoxLayout();
    ruolo=new QLabel();
    ruolo->setText("Ruolo:");
    ruoloLine=new QLineEdit();
    ruoloLine->setMaximumWidth(200);
    boxRuolo->addWidget(ruolo);
    boxRuolo->addWidget(ruoloLine);

    QHBoxLayout* boxDesc=new QHBoxLayout();
    desc=new QLabel();
    desc->setText("Descrizione:");
    descText=new QPlainTextEdit();
    descText->setFixedSize(200,130);
    boxDesc->addWidget(desc);
    boxDesc->addWidget(descText);

    boxModifica->addLayout(boxNome);
    boxModifica->addLayout(boxInizio);
    boxModifica->addLayout(boxFine);
    boxModifica->addLayout(boxRuolo);
    boxModifica->addLayout(boxDesc);

    addButton=new QPushButton();
    addButton->setText("Aggiungi");

    endButton=new QPushButton();
    endButton->setText("Fine");

    boxModifica->addWidget(addButton);
    boxModifica->addWidget(endButton);

    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addSlot()));
    connect(endButton, SIGNAL(clicked(bool)), this, SLOT(endSlot()));
    connect(delButton, SIGNAL(clicked(bool)), this, SLOT(deleteSlot()));


}

void modificaExp::deleteSlot()
{
    utente->cancella_esperienza(combo->itemText(combo->currentIndex()).toStdString());
    combo->removeItem(combo->currentIndex());
}

void modificaExp::addSlot()
{
    utente->aggiungi_esperienza(esperienza(string(nomeAziendaLine->text().toStdString()),
                  QDate(dataInizioLine->date()),QDate(dataFineLine->date()),
                            string(ruoloLine->text().toStdString()),string(descText->toPlainText().toStdString())));

    nomeAziendaLine->clear();
    dataInizioLine->clear();
    dataFineLine->clear();
    ruoloLine->clear();
    descText->clear();
}

void modificaExp::endSlot()
{
    profW->createTab();
    this->close();
}

