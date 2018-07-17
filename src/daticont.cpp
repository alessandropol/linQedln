#include "daticont.h"

#include<QHBoxLayout>
#include<QString>
#include<QDateTimeEdit>
#include<QDate>

datiCont::datiCont(dati_personali* datiU,QWidget *parent) :    QWidget(parent)
{

    QWidget* datiWidget=new QWidget(this);
    datiWidget->setFixedSize(370,200);

    QPalette Pal2(palette());
    Pal2.setColor(QPalette::Background, Qt::gray);


    residenza=new QLabel();
    residenzaLine=new QLabel();
    residenza->setText("Residenza:");
    residenzaLine->setPalette(Pal2);
    residenzaLine->setText(QString::fromStdString(datiU->get_residenza()));

    nazionalita=new QLabel();
    nazionalitaLine=new QLabel();
    nazionalita->setText("Nazionalità:");
    nazionalitaLine->setPalette(Pal2);
    nazionalitaLine->setText(QString::fromStdString(datiU->get_nazionalita()));

    domicilio=new QLabel();
    domicilioLine=new QLabel();
    domicilio->setText("Domicilio:");
    domicilioLine->setPalette(Pal2);
    domicilioLine->setText(QString::fromStdString(datiU->get_domicilio()));

    QLabel* dataNascita=new QLabel();
    QDateEdit *dataNascitaLine = new QDateEdit();
    dataNascita->setFixedWidth(170);
    dataNascita->setText("Data di Nascita:");
    dataNascitaLine->setDate(QDate(datiU->get_datanascita().get_anno(),datiU->get_datanascita().get_mese(),datiU->get_datanascita().get_giorno()));
    dataNascitaLine->setDisplayFormat("dd.MM.yyyy");
    dataNascitaLine->setReadOnly(1);
    dataNascitaLine->setFixedWidth(110);






    QHBoxLayout* resiLayout=new QHBoxLayout();
    QHBoxLayout* naziLayout=new QHBoxLayout();
    QHBoxLayout* domiLayout=new QHBoxLayout();
    QHBoxLayout* dataLayout=new QHBoxLayout();

    dataLayout->setAlignment(Qt::AlignLeft);

    domiLayout->addWidget(domicilio);
    domiLayout->addWidget(domicilioLine);
    resiLayout->addWidget(residenza);
    resiLayout->addWidget(residenzaLine);
    naziLayout->addWidget(nazionalita);
    naziLayout->addWidget(nazionalitaLine);
    dataLayout->addWidget(dataNascita);
    dataLayout->addWidget(dataNascitaLine);

    QVBoxLayout* datiLayout=new QVBoxLayout(datiWidget);
    datiLayout->addLayout(domiLayout);
    datiLayout->addLayout(resiLayout);
    datiLayout->addLayout(naziLayout);
    datiLayout->addLayout(dataLayout);


}
