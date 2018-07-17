#include "tabcognome.h"

#include<QHBoxLayout>



tabCognome::tabCognome(int x,int y,account* user,QWidget *parent):
    QWidget(parent),utente(user),risultatox(x),risultatoy(y)
{
     padre=parent;
     risultatoW=0;
     obj=0;
     res=0;
     this->setFixedSize(280, 280);

     QVBoxLayout* boxtab=new QVBoxLayout(this);

     QHBoxLayout* boxNome=new QHBoxLayout();
     nomeLabel=new QLabel();
     nomeLabel->setText("Nome");
     nomeLine= new QLineEdit();
     nomeLine->setMaximumWidth(200);
     boxNome->addWidget(nomeLabel);
     boxNome->addWidget(nomeLine);

     QHBoxLayout* boxCognome=new QHBoxLayout();
     cognomeLabel=new QLabel();
     cognomeLabel->setText("Cognome");
     cognomeLine= new QLineEdit();
     cognomeLine->setMaximumWidth(200);

     boxCognome->addWidget(cognomeLabel);
     boxCognome->addWidget(cognomeLine);


     ricercaButton=new QPushButton();
     ricercaButton->setMaximumWidth(70);
     ricercaButton->setText("cerca");

     boxtab->addLayout(boxNome);
     boxtab->addLayout(boxCognome);
     boxtab->addWidget(ricercaButton);

     connect(ricercaButton, SIGNAL(clicked()), this, SLOT(cercaCognome()));

}

void tabCognome::cercaCognome()
{
    if(obj==0)//per non creare objsearch per ogni ricerca
    {
        obj=new objsearchUtente(cognomeLine->text().toStdString(),nomeLine->text().toStdString());
        res=new objresult(utente->ricerca(obj));
    }
    else
    {
        delete (obj);
        delete(res);
        obj=new objsearchUtente(cognomeLine->text().toStdString(),nomeLine->text().toStdString());
        res=new objresult(utente->ricerca(obj));
    }
    //per non creare dupplicati della tabella dei risultati
    if(risultatoW==0)
    {
            risultatoW=new risultatoCognome(risultatox,risultatoy,utente,res,padre);
            risultatoW->show();
    }
    else
    {
        risultatoW->close();
        risultatoW=new risultatoCognome(risultatox,risultatoy,utente,res,padre);
        risultatoW->show();
    }
}

