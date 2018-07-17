#include "taball.h"

#include<QHBoxLayout>

tabAll::tabAll(int x,int y,administrator* user,QWidget *parent) :
    QWidget(parent),admin(user),risultatox(x),risultatoy(y)
{
    padre=parent;
    risultatoW=0;
    obj=0;
    res=0;
    QVBoxLayout* box=new QVBoxLayout(this);

    ricercaButton=new QPushButton();
    ricercaButton->setMaximumWidth(70);
    ricercaButton->setText("Cerca Tutti");
    ricercaButton->setFixedWidth(250);
    box->addWidget(ricercaButton);
    box->setAlignment(Qt::AlignCenter);


    connect(ricercaButton, SIGNAL(clicked()), this, SLOT(cercaTutti()));

}

void tabAll::cercaTutti()
{

    if(obj==0)//per non creare objsearch per ogni ricerca
    {
        obj=new objsearchAdmin("","","","",true);
        res=new objresult(admin->ricerca(obj));
    }
    else
    {
        delete (obj);
        delete(res);
        obj=new objsearchAdmin("","","","",1);
        res=new objresult(admin->ricerca(obj));
    }

   if(risultatoW==0)
   {
       risultatoW=new risultatoCognome(risultatox,risultatoy,admin,res,padre);
       risultatoW->show();
   }
   else
   {
       risultatoW->close();
       risultatoW=new risultatoCognome(risultatox,risultatoy,admin,res,padre);
       risultatoW->show();
   }
}

