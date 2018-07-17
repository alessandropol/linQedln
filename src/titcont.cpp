#include "titcont.h"


#include<QHBoxLayout>
#include<QDateEdit>

titcont::titcont(vector<titolodistudio*>* VT,QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(370,340);

    stack=new QStackedWidget(this);
    pageComboBox = new QComboBox();
    QVBoxLayout* layoutG=new QVBoxLayout(this);
    pageComboBox->setMaximumWidth(330);

    int i=1;
    vector<titolodistudio*>::iterator it=VT->begin();
    titolodistudio* tit;

    for(;it!=VT->end();++it)
    {
        wid=new QWidget();
        wid->setFixedSize(350,270);

        tit=(*it);

        nomeTitolo=new QLabel(wid);



        nomeTitolo->setText(QString::fromStdString(tit->get_nome_titolo()));

        nomeTitolo->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setBold(1);
        nomeTitolo->setStyleSheet("QLabel { color : red; }");
        nomeTitolo->setFont(font);

        QLabel* inizio=new QLabel();
        QDateEdit *dataILine = new QDateEdit();
        inizio->setText("Data Inizio:");
        dataILine->setDate(QDate(tit->get_inizio_studi().get_anno(),tit->get_inizio_studi().get_mese(),tit->get_inizio_studi().get_giorno()));
        dataILine->setDisplayFormat("dd.MM.yyyy");
        dataILine->setReadOnly(1);
        dataILine->setFixedWidth(110);

        QLabel* fine=new QLabel();
        QDateEdit *dataFLine = new QDateEdit();
        fine->setText("Data Fine:");
        dataFLine->setDate(QDate(tit->get_fine_studi().get_anno(),tit->get_fine_studi().get_mese(),tit->get_fine_studi().get_giorno()));
        dataFLine->setDisplayFormat("dd.MM.yyyy");
        dataFLine->setReadOnly(1);
        dataFLine->setFixedWidth(110);

        voto=new QLabel(wid);
        votoline=new QLabel(wid);
        voto->setText("Voto Finale");
        votoline->setText(QString::number(tit->get_votofinale()));

        QHBoxLayout* inizioLayout=new QHBoxLayout();
        QHBoxLayout* fineLayout=new QHBoxLayout();
        QHBoxLayout* votoLayout=new QHBoxLayout();

        inizioLayout->addWidget(inizio);
        inizioLayout->addWidget(dataILine);
        fineLayout->addWidget(fine);
        fineLayout->addWidget(dataFLine);
        votoLayout->addWidget(voto);
        votoLayout->addWidget(votoline);


        QVBoxLayout* layout=new  QVBoxLayout(wid);
        layout->addWidget(nomeTitolo);
        layout->addLayout(inizioLayout);
        layout->addLayout(fineLayout);
        layout->addLayout(votoLayout);


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
