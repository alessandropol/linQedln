#include "a_ricercawidget.h"

#include<QHBoxLayout>

#include"tabcognome.h"
#include"tabcompetenza.h"
#include"tablingua.h"
#include"tabstudi.h"
#include"tabamici.h"
#include"taball.h"

a_ricercaWidget::a_ricercaWidget(administrator* user,QWidget *parent) :
    QWidget(parent),admin(user)
{
    this->setFixedSize(710, 680);
    this->setGeometry(390,10,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::red);
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
    tabProfilo->setStyleSheet("QTabBar::tab {min-height: 50px; max-width: 58px; font-size: 9px; }");

    tabProfilo->addTab(new tabCognome(340,0,admin,this),"Ricerca\n per\nCOGNOME");
    tabProfilo->addTab(new tabCompetenza(340,0,admin,this),"Ricerca\n per\nCOMP.");
    tabProfilo->addTab(new tabLingua(340,0,admin,this),"Ricerca\n per\nLINGUA");
    tabProfilo->addTab(new tabStudi(340,0,admin,this),"Ricerca\n per\nSTUDI");
    tabProfilo->addTab(new tabAll(340,0,admin,this),"Ricerca\nTUTTI");

    boxOBJ->addWidget(tabProfilo);

}
