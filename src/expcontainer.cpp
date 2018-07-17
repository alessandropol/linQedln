#include "expcontainer.h"

#include<QHBoxLayout>
#include<QString>
#include<QDateEdit>


expContainer::expContainer(vector<esperienza*>* VE, QWidget *parent): QWidget(parent)
{
    this->setFixedSize(370,340);
    stack=new QStackedWidget(this);
    pageComboBox = new QComboBox();
    pageComboBox->setMaximumWidth(330);

    QVBoxLayout* layoutG=new QVBoxLayout(this);

    vector<esperienza*>::iterator it= VE->begin();
    esperienza* exp=0;
    int i=1;
    for(;it!=VE->end();++it)
    {
        exp=(*it);

        QWidget* wid=new QWidget();
        wid->setFixedSize(350,270);

        QLabel* azienda=new QLabel(wid);

        azienda->setText(QString::fromStdString(exp->get_azienda()));

        azienda->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setBold(1);
        azienda->setStyleSheet("QLabel { color : red; }");
        azienda->setFont(font);

        QLabel* dataI=new QLabel();
        QDateEdit *dataILine = new QDateEdit();
        //dataI->setFixedWidth(170);
        dataI->setText("Data Inizio:");
        dataILine->setDate(QDate(exp->get_data_inizio().get_anno(),exp->get_data_inizio().get_mese(),exp->get_data_inizio().get_giorno()));
        dataILine->setDisplayFormat("dd.MM.yyyy");
        dataILine->setReadOnly(1);
        dataILine->setFixedWidth(110);

        QLabel* dataF=new QLabel();
        QDateEdit *dataFLine = new QDateEdit();
        //dataF->setFixedWidth(170);
        dataF->setText("Data Fine:");
        dataFLine->setDate(QDate(exp->get_data_fine().get_anno(),exp->get_data_fine().get_mese(),exp->get_data_fine().get_giorno()));
        dataFLine->setDisplayFormat("dd.MM.yyyy");
        dataFLine->setReadOnly(1);
        dataFLine->setFixedWidth(110);

        QLabel* ruolo=new QLabel(wid);
        QLabel* ruololine=new QLabel(wid);
        ruolo->setText("Ruolo:");
        ruololine->setText(QString::fromStdString(exp->get_ruolo()));

        QLabel* descrizione=new QLabel(wid);
        descrizione->setText("Descrizione:");

        QPlainTextEdit* descText=new QPlainTextEdit(wid);
        descText->insertPlainText(QString::fromStdString(exp->get_descrizione()));
        descText->setFixedSize(200,130);
        descText->setReadOnly(true);


        QHBoxLayout* dataILayout=new QHBoxLayout();
        QHBoxLayout* dataFLayout=new QHBoxLayout();
        QHBoxLayout* ruoloLayout=new QHBoxLayout();
        QHBoxLayout* descLayout=new QHBoxLayout();

        dataILayout->addWidget(dataI);
        dataILayout->addWidget(dataILine);
        dataFLayout->addWidget(dataF);
        dataFLayout->addWidget(dataFLine);
        ruoloLayout->addWidget(ruolo);
        ruoloLayout->addWidget(ruololine);
        descLayout->addWidget(descrizione);
        descLayout->addWidget(descText);


        QVBoxLayout* layout=new  QVBoxLayout(wid);
        layout->addWidget(azienda);
        layout->addLayout(ruoloLayout);
        layout->addLayout(dataILayout);
        layout->addLayout(dataFLayout);
        layout->addLayout(descLayout);

        stack->addWidget(wid);
        QString pageN("Page ");
        pageN.append(QString::number(i));
        pageComboBox->addItem(pageN);
        pageComboBox->setFixedWidth(100);
        i++;
    }

    connect(pageComboBox, SIGNAL(activated(int)), stack, SLOT(setCurrentIndex(int)));
    layoutG->addWidget(stack);
    layoutG->addWidget(pageComboBox);


}
