#include "ricercawidget.h"

#include<QHBoxLayout>

#include"tabcognome.h"
#include"tabcompetenza.h"
#include"tablingua.h"
#include"tabstudi.h"
#include"tabamici.h"

ricercaWidget::ricercaWidget(basic* user,QWidget *parent) :
    QWidget(parent),utente(user)
{
    this->setFixedSize(710, 680);
    this->setGeometry(390,10,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::darkRed);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    //WIDGET OBJRICERCA
    objWidget=new QWidget(this);
    objWidget->setFixedSize(320,350);
    this->setGeometry(390,10,0,0);

    QVBoxLayout* boxOBJ=new QVBoxLayout(objWidget);

    Pal.setColor(QPalette::Background, Qt::white);
    ricercaLabel=new QLabel();
    ricercaLabel->setText("RICERCA");
    ricercaLabel->setAlignment(Qt::AlignCenter);
    ricercaLabel->setFixedWidth(300);
    ricercaLabel->setFixedHeight(40);
    ricercaLabel->setStyleSheet("QLabel { color : white; }");


    QFont font;
    font.setBold(1);
    font.setPointSize(30);
    ricercaLabel->setFont(font);

    boxOBJ->addWidget(ricercaLabel);

    tabProfilo=new QTabWidget();

    tabProfilo->setFixedSize(300, 300);
    tabProfilo->setGeometry(400,0,0,0);
    tabProfilo->setStyleSheet("QTabBar::tab {min-height: 50px; max-width: 60px; font-size: 9px; }");

    tabProfilo->addTab(new tabCognome(0,365,utente,this),"Ricerca\n per\nCOGNOME");
    tabProfilo->addTab(new tabCompetenza(0,365,utente,this),"Ricerca\n per\nCOMP.");
    tabProfilo->addTab(new tabLingua(0,365,utente,this),"Ricerca\n per\nLINGUA");
    tabProfilo->addTab(new tabStudi(0,365,utente,this),"Ricerca\n per\nSTUDI");
    tabProfilo->addTab(new tabAmici(0,365,utente,this),"Trova\nAMICI");



    boxOBJ->addWidget(tabProfilo);

}
