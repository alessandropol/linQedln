#include "tabamici.h"
#include"QHBoxLayout"
#include"objresult.h"


tabAmici::tabAmici(int x,int y,basic* user,QWidget *parent) :
    QWidget(parent),utente(user),risultatox(x),risultatoy(y)
{
    padre=parent;
    risultatoW=0;
    QVBoxLayout* box=new QVBoxLayout(this);

    ricercaButton=new QPushButton();
    ricercaButton->setMaximumWidth(70);
    ricercaButton->setText("Cerca AMICI");
    ricercaButton->setFixedWidth(250);
    box->addWidget(ricercaButton);
    box->setAlignment(Qt::AlignCenter);


    connect(ricercaButton, SIGNAL(clicked()), this, SLOT(cercaAmici()));

}

void tabAmici::cercaAmici()
{

   objresult* res=new objresult(0,0,*utente->get_reteamici());

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



