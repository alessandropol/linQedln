#include "modificacomp.h"

#include"competenza.h"

#include<QHBoxLayout>

modificaComp::modificaComp(basic* user,profiloWidget* PW, QWidget *parent): QWidget(parent),utente(user),profW(PW)
{

    this->setFixedSize(400,400);
    this->setWindowTitle("Modifica Competenza");

    QVBoxLayout* boxModifica=new QVBoxLayout(this);

    QHBoxLayout* boxElimina=new QHBoxLayout();
    elimina=new QLabel();
    elimina->setText("Elimina Competenza");

    combo=new QComboBox();

    pf2=dynamic_cast<profilo_2*>(utente->get_profilo());
    vector<competenza*>* VC=pf2->get_competenze();
    vector<competenza*>::iterator it=VC->begin();
    competenza* cmp;

    for(;it!=VC->end();++it)
    {
        cmp=(*it);
        combo->addItem(QString::fromStdString(cmp->get_nome_competenza()));
    }



    delButton=new QPushButton();
    delButton->setText("Elimina");

    boxElimina->addWidget(elimina);
    boxElimina->addWidget(combo);
    boxElimina->addWidget(delButton);
    //connect(delButton, SIGNAL(clicked(bool)), this, SLOT(deleteSlot()));

    aggiungi=new QLabel();
    aggiungi->setText("Aggiungi Competenza");

    boxModifica->addLayout(boxElimina);
    boxModifica->addWidget(aggiungi);

    QHBoxLayout* boxNome=new QHBoxLayout();
    nomeCompetenza=new QLabel();
    nomeCompetenza->setText("Nome Competenza:");
    nomeCompetenzaLine=new QLineEdit();
    nomeCompetenzaLine->setMaximumWidth(200);
    boxNome->addWidget(nomeCompetenza);
    boxNome->addWidget(nomeCompetenzaLine);

    QHBoxLayout* boxLivello=new QHBoxLayout();
    boxLivello=new QHBoxLayout();
    livello=new QLabel();
    livello->setText("Livello:");
    livelloLine=new QLineEdit();
    livelloLine->setMaximumWidth(200);
    boxLivello->addWidget(livello);
    boxLivello->addWidget(livelloLine);

    QHBoxLayout* boxDesc=new QHBoxLayout();
    desc=new QLabel();
    desc->setText("Descrizione:");
    descText=new QPlainTextEdit();
    descText->setFixedSize(200,130);
    boxDesc->addWidget(desc);
    boxDesc->addWidget(descText);

    boxModifica->addLayout(boxNome);
    boxModifica->addLayout(boxLivello);
    boxModifica->addLayout(boxDesc);
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

void modificaComp::deleteSlot()
{
    utente->cancella_competenza(combo->itemText(combo->currentIndex()).toStdString());
    combo->removeItem(combo->currentIndex());
}

void modificaComp::addSlot()
{
    utente->aggiungi_competenza(competenza(
              nomeCompetenzaLine->text().toStdString(),livelloLine->text().toInt(),descText->toPlainText().toStdString()));

    nomeCompetenzaLine->clear();
    livelloLine->acceptDrops();
    descText->clear();

}

void modificaComp::endSlot()
{
    profW->createTab();
    this->close();
}
