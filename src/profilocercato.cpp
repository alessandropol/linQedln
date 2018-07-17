#include "profilocercato.h"

#include<QLabel>
#include<QTabWidget>
#include<QHBoxLayout>
#include<QTreeView>
#include<QScrollArea>
#include<QPushButton>

#include"daticont.h"
#include"expcontainer.h"
#include"compcontainer.h"
#include"linguacont.h"
#include"titcont.h"
#include"profilo_2.h"

profiloCercato::profiloCercato(basic* utente,QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(370,460);
    this->setGeometry(0,170,0,0);


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::darkGreen);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    QLabel* titoloprofilo=new QLabel(this);
    titoloprofilo->setText("PROFILO UTENTE");
    titoloprofilo->setAlignment(Qt::AlignCenter);
    titoloprofilo->setFixedWidth(370);
    titoloprofilo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    titoloprofilo->setFont(font);

    QWidget *centralWidget = new QWidget(this);
    QTabWidget* tabProfilo=new QTabWidget(centralWidget);

    tabProfilo->setFixedSize(360, 400);
    tabProfilo->setGeometry(0,0,0,0);
    tabProfilo->setStyleSheet("QTabBar::tab {min-height: 50px; max-width: 70px; font-size: 9px; }");

    profilo_2* pf2=dynamic_cast<profilo_2*>(utente->get_profilo());

    tabProfilo->addTab(new datiCont(utente->get_profilo()->get_datipersonali()),"Dati\n Personali");
    if(pf2)
    {
        tabProfilo->addTab(new expContainer(pf2->get_esperienze()),"Esperienze");
        tabProfilo->addTab(new compcontainer(pf2->get_competenze()),"Competenze");
        tabProfilo->addTab(new linguacont(pf2->get_lingue()),"Lingua");
        tabProfilo->addTab(new titcont(pf2->get_titolodistudio()),"Titolo\n di Studio");
    }

    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->addWidget(titoloprofilo);
    layout->addWidget(tabProfilo);


}
