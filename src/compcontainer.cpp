#include "compcontainer.h"

#include<QHBoxLayout>

compcontainer::compcontainer(vector<competenza*>* VC, QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(370,340);

    stack=new QStackedWidget(this);
    pageComboBox = new QComboBox();
    QVBoxLayout* layoutG=new QVBoxLayout(this);
    pageComboBox->setMaximumWidth(330);


    vector<competenza*>::iterator it= VC->begin();

    competenza* cmp;
    int i=1;

    for(;it!=VC->end();++it)
    {
        cmp=(*it);
        wid=new QWidget();
        wid->setFixedSize(350,270);

        nomeComp=new QLabel(wid);
        nomeComp->setText(QString::fromStdString(cmp->get_nome_competenza()));

        nomeComp->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setBold(1);
        nomeComp->setStyleSheet("QLabel { color : red; }");
        nomeComp->setFont(font);

        livComp=new QLabel(wid);
        livComp->setText("Livello Competenza");
        livCompline=new QLabel(wid);
        QString LC(QString::number(cmp->get_livello_competenza()));
        LC.append("/10");
        livCompline->setText(LC);

        descrizioneComp=new QLabel(wid);
        descrizioneComp->setText("Descrizione");

        descText=new QPlainTextEdit(wid);
        descText->insertPlainText(QString::fromStdString(cmp->get_descrizione_competenza()));
        descText->setFixedSize(200,130);
        descText->setReadOnly(true);

        QHBoxLayout* livelloLayout=new QHBoxLayout();
        QHBoxLayout* descLayout=new QHBoxLayout();

        livelloLayout->addWidget(livComp);
        livelloLayout->addWidget(livCompline);
        descLayout->addWidget(descrizioneComp);
        descLayout->addWidget(descText);


        QVBoxLayout* layout=new  QVBoxLayout(wid);
        layout->addWidget(nomeComp);
        layout->addLayout(livelloLayout);
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
