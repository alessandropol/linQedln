#include "linguacont.h"
#include<QHBoxLayout>
#include<QString>


linguacont::linguacont(vector<lingua*>* VL, QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(370,340);

    stack=new QStackedWidget(this);
    pageComboBox = new QComboBox();
    QVBoxLayout* layoutG=new QVBoxLayout(this);
    pageComboBox->setMaximumWidth(330);

    int i=1;
    vector<lingua*>::iterator it=VL->begin();
    lingua* lin;

    for(;it!=VL->end();++it)
    {
        lin=(*it);
        wid=new QWidget();
        wid->setFixedSize(350,270);

        nomeLingua=new QLabel(wid);
        nomeLingua->setText(QString::fromStdString(lin->get_nome_lingua()));

        nomeLingua->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setBold(1);
        nomeLingua->setStyleSheet("QLabel { color : red; }");
        nomeLingua->setFont(font);

        madreL=new QLabel(wid);
        madreL->setText("Madre Lingua");
        madreCH=new QCheckBox(wid);
        madreCH->setDisabled(1);
        if(lin->is_madre_lingua())
            madreCH->setChecked(1);

        livScritto=new QLabel(wid);
        livScritto->setText("Livello Scritto");
        QString liv(QString::number(lin->get_livello_scritto()));
        livScrittoline=new QLabel(wid);
        livScrittoline->setText(liv.append("/10"));

        livOrale=new QLabel(wid);
        livOraleline=new QLabel(wid);
        livOrale->setText("Livello Orale");
        liv=QString::number(lin->get_livello_orale());
        livOraleline->setText(liv.append("/10"));

        QHBoxLayout* madreLayout=new QHBoxLayout();
        QHBoxLayout* scrittoLayout=new QHBoxLayout();
        QHBoxLayout* oraleLayout=new QHBoxLayout();

        madreLayout->addWidget(madreL);
        madreLayout->addWidget(madreCH);
        scrittoLayout->addWidget(livScritto);
        scrittoLayout->addWidget(livScrittoline);
        oraleLayout->addWidget(livOrale);
        oraleLayout->addWidget(livOraleline);


        QVBoxLayout* layout=new  QVBoxLayout(wid);
        layout->addWidget(nomeLingua);
        layout->addLayout(madreLayout);
        layout->addLayout(scrittoLayout);
        layout->addLayout(oraleLayout);

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
