#include "tabstudi.h"
#include"QHBoxLayout"

#include"objresult.h"
#include<QMessageBox>

tabStudi::tabStudi(int x,int y,account* user,QWidget *parent) :
    QWidget(parent),utente(user),risultatox(x),risultatoy(y)
{
    obj=0;
    res=0;
    padre=parent;
    risultatoW=0;
    this->setFixedSize(280, 250);

    QVBoxLayout* boxtab=new QVBoxLayout(this);

    QHBoxLayout* boxNome=new QHBoxLayout();
    nomeLabel=new QLabel();
    nomeLabel->setText("Nome Titolo:");
    nomeLine= new QLineEdit();
    nomeLine->setMaximumWidth(200);
    boxNome->addWidget(nomeLabel);
    boxNome->addWidget(nomeLine);

    QHBoxLayout* boxLivelloS=new QHBoxLayout();
    votoLabel=new QLabel();
    votoLabel->setText("Voto:");
    votoLine= new QLineEdit();
    votoLine->setMaximumWidth(40);

    boxLivelloS->addWidget(votoLabel);
    boxLivelloS->addWidget(votoLine);



    ricercaButton=new QPushButton();
    ricercaButton->setMaximumWidth(70);
    ricercaButton->setText("cerca");

    boxtab->addLayout(boxNome);
    boxtab->addLayout(boxLivelloS);
    boxtab->addWidget(ricercaButton);


    connect(ricercaButton, SIGNAL(clicked()), this, SLOT(cercaStudi()));

}

void tabStudi::cercaStudi()
{
   if(obj==0)
   {
       obj=new objsearchTitolo(nomeLine->text().toStdString(),votoLine->text().toInt());
       res=new objresult(utente->ricerca(obj));
   }
   else
   {
       delete (obj);
       delete(res);
       obj=new objsearchTitolo(nomeLine->text().toStdString(),votoLine->text().toInt());
       res=new objresult(utente->ricerca(obj));
   }

   if(res->errore==2)
   {
       QMessageBox* mess= new QMessageBox();
       mess->setWindowTitle("Errore di Ricerca");
       mess->setText("Privilegi non sufficenti per effettuare questa ricerca");
       mess->exec();
   }
   else
   {if(risultatoW==0)
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
}



