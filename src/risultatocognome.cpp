#include "risultatocognome.h"

#include<QHBoxLayout>
#include"profilocercato.h"





risultatoCognome::risultatoCognome(int x,int y,account* user,objresult* res,QWidget *parent) :
    QWidget(parent),risultato(res),utente(user)
{
    pr=0;
    padre=parent;
    this->setFixedSize(320,330 );
    this->setGeometry(x,y,0,0);

    QVBoxLayout* boxOBJ=new QVBoxLayout(this);

    QLabel* ricercaLabel=new QLabel();
    ricercaLabel->setText("RISULTATO");
    ricercaLabel->setAlignment(Qt::AlignCenter);
    ricercaLabel->setFixedWidth(320);
    ricercaLabel->setFixedHeight(40);
    ricercaLabel->setStyleSheet("QLabel { color : white; }");
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    ricercaLabel->setFont(font);

    boxOBJ->addWidget(ricercaLabel);

    int numeroRighe=13;


    //il numero di righe è 20, se ci sono più risultati, aggiungo le righe
    table= new QTableWidget(numeroRighe, 3);
    table->setFixedSize(300,270);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QScrollBar* scroll= table->horizontalScrollBar();
    scroll->hide();

    QFont font2;
    font2.setPointSize(10);
    table->horizontalHeader()->setFont(font2);

    table->setHorizontalHeaderItem(0,new QTableWidgetItem("Cognome"));
    table->setHorizontalHeaderItem(1,new QTableWidgetItem("Nome"));
    table->setHorizontalHeaderItem(2,new QTableWidgetItem("Vedi Profilo"));

    QHeaderView *vHeader = table->verticalHeader();
    vHeader->setDefaultSectionSize(28);
    vHeader->sectionResizeMode(QHeaderView::Fixed);
    QHeaderView *hHeader = table->horizontalHeader();
    hHeader->setDefaultSectionSize(87);
    hHeader->sectionResizeMode(QHeaderView::Fixed);

    signalMapper = new QSignalMapper();


    vector<account*>::iterator it=risultato->multiresult.begin();
    account* acc=0;

    if(risultato->singleresult)
    {
        table->setRowCount(numeroRighe);

        basic* ba=dynamic_cast<basic*>(risultato->singleresult);
        if(ba)
        {
            table->setItem(0,0,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_cognome())));
            table->setItem(0,1,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_nome())));
            table->setItem(0,2,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_cognome())));
            QPushButton* pButton = new QPushButton(QString::fromStdString(ba->get_username()));
            connect(pButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(pButton, QString::fromStdString((acc->get_username())));
            table->setCellWidget(0, 2, pButton);
        }
    }
    else
    {
        int righe=0;
        numeroRighe+=risultato->multiresult.size();
        table->setRowCount(numeroRighe);
        for(;it!=risultato->multiresult.end();++it)
        {
            acc=(*it);
            basic* ba=dynamic_cast<basic*>(acc);
            if(ba)
            {
                table->setItem(righe,0,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_cognome())));
                table->setItem(righe,1,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_nome())));
                table->setItem(righe,2,new QTableWidgetItem(QString::fromStdString(ba->get_profilo()->get_datipersonali()->get_cognome())));

                QPushButton* pButton = new QPushButton(QString::fromStdString(acc->get_username()));
                connect(pButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(pButton, QString::fromStdString((acc->get_username())));
                table->setCellWidget(righe, 2, pButton);
            }
            righe++;
        }
    }



       connect(signalMapper, SIGNAL(mapped(QString)),
               this, SIGNAL(clicked(QString)));

       connect(this, SIGNAL(clicked(QString)),this, SLOT(clickedSlot(QString)));



       boxOBJ->addWidget(table);


       //connect(Pview, SIGNAL(clicked()),this, SLOT(vediProfilo()));


}

void risultatoCognome::clickedSlot(QString t)
{
    basic* ricB,*utenteB;
    account* acc;

    //seleziono il risultato
    if(risultato->singleresult)
        acc=risultato->singleresult;//se è singolo prendo quello
    else
    {//altrimenti seleziono il risultato che combacia con il pulsante premuto
        vector<account*>::iterator it=risultato->multiresult.begin();
        for(;it!=risultato->multiresult.end();++it)
        {
                if((*it)->get_username()==t.toStdString())
                    acc=(*it);
        }
    }

    ricB=dynamic_cast<basic*>(acc);//controllo se è un admin o utente
    bool amico=false;
    utenteB=dynamic_cast<basic*>(utente);
    if(ricB!=0 && utenteB!=0)
    {
        if(utenteB->find_friend(ricB))
            amico=true;
        if(pr==0)//controllo se è già stata creata
            pr=new profiloRicerca(utenteB,ricB,amico,padre);
        else
        {
            pr->close();
            pr=new profiloRicerca(utenteB,ricB,amico,padre);
        }
        pr->show();
    }
    else// se è administratore
    {
            if(pr==0)//controllo se è già stata creata
                prA=new a_profiloRicerca(utente,ricB,this,padre);
            else
            {
                prA->close();
                prA=new a_profiloRicerca(utente,ricB,this,padre);
            }
            prA->show();
            utenteCercato=ricB;

    }

}

void risultatoCognome::chiudi()
{
    this->close();
}

