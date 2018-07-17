#include "modificatit.h"


#include<QHBoxLayout>



modificaTit::modificaTit(basic* user,profiloWidget* PW, QWidget *parent): QWidget(parent),utente(user),profW(PW)

{
    this->setFixedSize(400,400);
    this->setWindowTitle("Modifica Titolo di Studio");

    QVBoxLayout* boxModifica=new QVBoxLayout(this);

    QHBoxLayout* boxElimina=new QHBoxLayout();
    elimina=new QLabel();
    elimina->setText("Elimina Titolo");

    pf2=dynamic_cast<profilo_2*>(utente->get_profilo());
    vector<titolodistudio*>* VT=pf2->get_titolodistudio();
    vector<titolodistudio*>::iterator it=VT->begin();
    titolodistudio* tit;

    combo=new QComboBox();

    for(;it!=VT->end();++it)
    {
        tit=(*it);
        combo->addItem(QString::fromStdString(tit->get_nome_titolo()));
    }
    delButton=new QPushButton();
    delButton->setText("elimina");

    boxElimina->addWidget(elimina);
    boxElimina->addWidget(combo);
    boxElimina->addWidget(delButton);

    aggiungi=new QLabel();
    aggiungi->setText("Aggiungi Titolo di Studio");

    boxModifica->addLayout(boxElimina);
    boxModifica->addWidget(aggiungi);

    QHBoxLayout* boxNome=new QHBoxLayout();
    nomeTitolo=new QLabel();
    nomeTitolo->setText("Nome Titolo");
    nomeTitoloLine=new QLineEdit();
    nomeTitoloLine->setMaximumWidth(200);
    boxNome->addWidget(nomeTitolo);
    boxNome->addWidget(nomeTitoloLine);

    QHBoxLayout* boxInizio=new QHBoxLayout();
    dataInizio=new QLabel();
    dataInizio->setText("Data Inizio");
    dataInizioLine = new QDateEdit();
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

    QHBoxLayout* boxVoto=new QHBoxLayout();
    voto=new QLabel();
    voto->setText("Voto:");
    votoLine=new QLineEdit();
    votoLine->setMaximumWidth(200);
    boxVoto->addWidget(voto);
    boxVoto->addWidget(votoLine);

    boxModifica->addLayout(boxNome);
    boxModifica->addLayout(boxInizio);
    boxModifica->addLayout(boxFine);
    boxModifica->addLayout(boxVoto);

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


void modificaTit::deleteSlot()
{
    utente->cancella_titolo(combo->itemText(combo->currentIndex()).toStdString());
    combo->removeItem(combo->currentIndex());

}

void modificaTit::addSlot()
{
    utente->aggiungi_titolo( titolodistudio(nomeTitoloLine->text().toStdString(),dataInizioLine->date(),dataFineLine->date(),votoLine->text().toInt()));
    nomeTitoloLine->clear();
    dataInizioLine->clear();
    dataFineLine->clear();
    votoLine->clear();

}

void modificaTit::endSlot()
{
    profW->createTab();
    this->close();
}


