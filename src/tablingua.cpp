#include "tablingua.h"

#include<QHBoxLayout>

#include"objresult.h"
#include<QMessageBox>


tabLingua::tabLingua(int x,int y,account* user,QWidget *parent) :
    risultatox(x),risultatoy(y),utente(user),QWidget(parent)
{    
    padre=parent;
    risultatoW=0;
    this->setFixedSize(280, 250);

    QVBoxLayout* boxtab=new QVBoxLayout(this);

    QHBoxLayout* boxNome=new QHBoxLayout();
    nomeLabel=new QLabel();
    nomeLabel->setText("Lingua:");
    nomeLine= new QLineEdit();
    nomeLine->setMaximumWidth(200);
    boxNome->addWidget(nomeLabel);
    boxNome->addWidget(nomeLine);

    QHBoxLayout* boxLivelloS=new QHBoxLayout();
    livelloSLabel=new QLabel();
    livelloSLabel->setText("Livello Scritto:");
    livelloSLine= new QLineEdit();
    livelloSLine->setMaximumWidth(40);

    boxLivelloS->addWidget(livelloSLabel);
    boxLivelloS->addWidget(livelloSLine);

    QHBoxLayout* boxLivelloO=new QHBoxLayout();
    livelloOLabel=new QLabel();
    livelloOLabel->setText("Livello Orale:");
    livelloOLine= new QLineEdit();
    livelloOLine->setMaximumWidth(40);

    boxLivelloO->addWidget(livelloOLabel);
    boxLivelloO->addWidget(livelloOLine);

    ricercaButton=new QPushButton();
    ricercaButton->setMaximumWidth(70);
    ricercaButton->setText("cerca");


    QVBoxLayout* box1=new QVBoxLayout();
    box1->addLayout(boxLivelloO);
    box1->addWidget(ricercaButton);


    QHBoxLayout* boxMadre=new QHBoxLayout();
    madreLabel=new QLabel();
    madreLabel->setText("Madre Lingua:");
    madreLine= new QCheckBox();

    boxMadre->addWidget(madreLabel);
    boxMadre->addWidget(madreLine);


    boxtab->addLayout(boxNome);
    boxtab->addLayout(boxMadre);
    boxtab->addLayout(boxLivelloS);
    boxtab->addLayout(box1);


    connect(ricercaButton, SIGNAL(clicked()), this, SLOT(cercaLingua()));

}

void tabLingua::cercaLingua()
{
   if(obj==0)
   {
       obj=new objsearchLingua(nomeLine->text().toStdString(),madreLine->isChecked(),livelloSLine->text().toInt(),livelloOLine->text().toInt());
       res=new objresult(utente->ricerca(obj));
   }
   else
   {
       delete (obj);
       delete(res);
       obj=new objsearchLingua(nomeLine->text().toStdString(),madreLine->isChecked(),livelloSLine->text().toInt(),livelloOLine->text().toInt());
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
   {
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
}


