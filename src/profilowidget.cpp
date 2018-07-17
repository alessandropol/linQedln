#include "profilowidget.h"

#include<QScrollArea>

#include"daticont.h"
#include"expcontainer.h"
#include"compcontainer.h"
#include"linguacont.h"
#include"titcont.h"
#include"modificaexp.h"
#include"modificacomp.h"
#include"modificalin.h"
#include"modificatit.h"
#include"modificadatip.h"

#include"dati_personali.h"
#include"profilo_2.h"

profiloWidget::profiloWidget(basic* acc,QWidget *parent) :    QWidget(parent),utente(acc)
{
    this->setFixedSize(370,520);
    this->setGeometry(10,170,0,0);
    questa=this;



    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    titoloprofilo=new QLabel(this);
    titoloprofilo->setText("PROFILO");
    titoloprofilo->setAlignment(Qt::AlignCenter);
    titoloprofilo->setFixedWidth(370);
    titoloprofilo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    titoloprofilo->setFont(font);

    centralWidget = new QWidget(this);

    pf2=dynamic_cast<profilo_2*>(utente->get_profilo());


    datiButton=new QPushButton();
    datiButton->setText("Modifica\n Dati Pers.");
    datiButton->setStyleSheet("QPushButton {font-size: 8pt; min-height: 20px; min-width: 64;}");
    expButton=new QPushButton();
    expButton->setText("Modifica\n Esperienza");
    expButton->setStyleSheet("QPushButton {font-size: 8pt; min-height: 20px; min-width: 64;}");
    compButton=new QPushButton();
    compButton->setText("Modifica\n Competenza");
    compButton->setStyleSheet("QPushButton {font-size: 8pt; min-height: 20px; min-width: 64;}");
    lingButton=new QPushButton();
    lingButton->setText("Modifica\n Lingua");
    lingButton->setStyleSheet("QPushButton {font-size: 8pt; min-height: 20px; min-width: 64;}");
    titButton=new QPushButton();
    titButton->setText("Modifica\n Titolo");
    titButton->setStyleSheet("QPushButton {font-size: 8pt; min-height: 20px; min-width: 64;}");

    layoutB=new QHBoxLayout();
    layoutB->addWidget(datiButton);
    layoutB->addWidget(expButton);
    layoutB->addWidget(compButton);
    layoutB->addWidget(lingButton);
    layoutB->addWidget(titButton);

    layout=new QVBoxLayout(this);

    if(pf2)
       createTab();


    connect(expButton, SIGNAL(clicked()), this,SLOT(modExp()));
    connect(compButton, SIGNAL(clicked()), this,SLOT(modCmp()));
    connect(lingButton, SIGNAL(clicked()), this,SLOT(modLin()));
    connect(titButton, SIGNAL(clicked()), this,SLOT(modTit()));
    connect(datiButton, SIGNAL(clicked()), this,SLOT(modDati()));


}

void profiloWidget::setPLayout()
{
    if(layoutB)
    {
        layoutB->~QHBoxLayout();
        layoutB=new QHBoxLayout();
        layoutB->addWidget(datiButton);
        layoutB->addWidget(expButton);
        layoutB->addWidget(compButton);
        layoutB->addWidget(lingButton);
        layoutB->addWidget(titButton);

    }

    layout->addWidget(titoloprofilo);
    layout->addWidget(tabProfilo);
    layout->addLayout(layoutB);
}

void profiloWidget::createTab()
{
    tabProfilo=new QTabWidget();
    tabProfilo=new QTabWidget(centralWidget);
    tabProfilo->setFixedSize(360, 400);
    tabProfilo->setGeometry(0,0,0,0);
    tabProfilo->setStyleSheet("QTabBar::tab {min-height: 50px; max-width: 70px; font-size: 9px; }");
    tabProfilo->addTab(new datiCont(utente->get_profilo()->get_datipersonali()),"Dati\n Personali");
    tabProfilo->addTab(new expContainer(pf2->get_esperienze()),"Esperienze");
    tabProfilo->addTab(new compcontainer(pf2->get_competenze()),"Competenze");
    tabProfilo->addTab(new linguacont(pf2->get_lingue()),"Lingua");
    tabProfilo->addTab(new titcont(pf2->get_titolodistudio()),"Titolo\n di Studio");
    setPLayout();
    tabProfilo->show();
}

void profiloWidget::modExp()
{
    modificaExp* window1=new modificaExp(utente,questa);
    window1->show();
    for(int i=0;i<tabProfilo->count();i++)
    {
        QWidget *tab=tabProfilo->widget(i);
        tab->~QWidget();
    }
    tabProfilo->~QTabWidget();
}

void profiloWidget::modCmp()
{
    modificaComp* window2=new modificaComp(utente,questa);
    window2->show();
    for(int i=0;i<tabProfilo->count();i++)
    {
        QWidget *tab=tabProfilo->widget(i);
        tab->~QWidget();
    }
    tabProfilo->~QTabWidget();
}

void profiloWidget::modLin()
{
    modificaLin* window3=new modificaLin(utente,questa);
    window3->show();
    for(int i=0;i<tabProfilo->count();i++)
    {
        QWidget *tab=tabProfilo->widget(i);
        tab->~QWidget();
    }
    tabProfilo->~QTabWidget();
}


void profiloWidget::modTit()
{
    modificaTit* window3=new modificaTit(utente,questa);
    window3->show();
    for(int i=0;i<tabProfilo->count();i++)
    {
        QWidget *tab=tabProfilo->widget(i);
        tab->~QWidget();
    }
    tabProfilo->~QTabWidget();
}

void profiloWidget::modDati()
{
    modificaDatiP* window4=new modificaDatiP(utente,questa);
    window4->show();
    for(int i=0;i<tabProfilo->count();i++)
    {
        QWidget *tab=tabProfilo->widget(i);
        tab->~QWidget();
    }
    tabProfilo->~QTabWidget();
}
