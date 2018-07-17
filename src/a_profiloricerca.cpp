#include "a_profiloricerca.h"

#include"QVBoxLayout"
#include"a_inforicercato.h"
#include"profilocercato.h"
#include"a_eliminautente.h"
#include"a_cambiatipologia.h"


a_profiloRicerca::a_profiloRicerca(account* user,basic* b ,QWidget *cogno,QWidget *parent) :
    QWidget(parent),utenteCercato(b)
{
    padre=parent;
    this->setFixedSize(690,310);
    this->setGeometry(10,360,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);



    RPLabel=new QLabel();

    RPLabel->setText("PROFILO CERCATO");
    RPLabel->setStyleSheet("QLabel { color : white; }");
    RPLabel->setFixedWidth(450);
    RPLabel->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    RPLabel->setFont(font);

    a_inforicercato* info;
    a_eliminaUtente* elimina;
    a_cambiaTipologia* cambia;


    administrator* admin2=dynamic_cast<administrator*>(user);
    if(admin2)
    {
        info=new a_inforicercato(b,this);
        elimina=new a_eliminaUtente(admin2,b,cogno,this);
        cambia=new a_cambiaTipologia(admin2,b,this);
    }



    QVBoxLayout* box=new QVBoxLayout(this);
    box->addWidget(info);
    box->addWidget(elimina);
    box->addWidget(cambia);



}



