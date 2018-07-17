#include "a_insertaccount.h"
#include"profilo_2.h"
#include"objresult.h"
#include"objsearch.h"
#include<QMessageBox>

a_insertAccount::a_insertAccount(administrator* user,QWidget *parent) :
    QWidget(parent),admin(user)
{
    this->setFixedSize(370,520);
    this->setGeometry(10,170,0,0);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::magenta);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    titolo=new QLabel();
    titolo->setText("INSERISCI ACCOUNT");
    //titolo->setAlignment(Qt::AlignCenter);
    titolo->setFixedWidth(370);
    titolo->setFixedHeight(40);
    QFont font;
    font.setBold(1);
    font.setPointSize(27);
    titolo->setFont(font);

    QHBoxLayout* boxUser=new QHBoxLayout();
    usernameLabel=new QLabel();
    usernameLine=new QLineEdit();
    usernameLine->setFixedWidth(220);
    usernameLabel->setText("Username:");
    boxUser->addWidget((usernameLabel));
    boxUser->addWidget((usernameLine));

    QHBoxLayout* boxPass=new QHBoxLayout();
    passwordLabel=new QLabel();
    passwordLine=new QLineEdit();
    passwordLine->setFixedWidth(220);
    passwordLabel->setText("Password:");
    boxPass->addWidget((passwordLabel));
    boxPass->addWidget((passwordLine));

    QHBoxLayout* boxMail=new QHBoxLayout();
    mailLabel=new QLabel();
    mailLine=new QLineEdit();
    mailLine->setFixedWidth(220);
    mailLabel->setText("E-Mail:");
    boxMail->addWidget((mailLabel));
    boxMail->addWidget((mailLine));

    QHBoxLayout* boxData=new QHBoxLayout();
    dataILabel=new QLabel();
    dataLine=new QDateEdit();
    dataLine->setFixedWidth(220);
    dataILabel->setText("Data Iscrizione:");
    dataLine->setDate(QDate::currentDate());
    boxData->addWidget((dataILabel));
    boxData->addWidget((dataLine));

    layoutB=new QVBoxLayout(this);
    layoutB->addWidget(titolo);
    layoutB->addLayout(boxUser);
    layoutB->addLayout(boxPass);
    layoutB->addLayout(boxMail);
    layoutB->addLayout(boxData);


    adminR=new QRadioButton();
    basicR=new QRadioButton();
    businR=new QRadioButton();
    execuR=new QRadioButton();

    adminR->setText("Utente Amministratore");
    basicR->setText("Utente Basic");
    businR->setText("Utente Business");
    execuR->setText("Utente Executive");

    QVBoxLayout* boxAdmin=new QVBoxLayout();
    boxAdmin->addWidget(adminR);

    nome=new QLabel();
    nome->setText("         Nome:");
    nomeLine=new QLineEdit();
    nomeLine->setMaximumWidth(200);

    cognome=new QLabel();
    cognome->setText("         Cognome:");
    cognomeLine=new QLineEdit();
    cognomeLine->setMaximumWidth(200);

    ruolo=new QLabel();
    ruolo->setText("         Ruolo:");
    ruoloLine=new QLineEdit();
    ruoloLine->setMaximumWidth(200);

    QHBoxLayout* nomeLayout=new QHBoxLayout();
    QHBoxLayout* cognomeLayout=new QHBoxLayout();
    QHBoxLayout* ruoloLayout=new QHBoxLayout();
    nomeLayout->addWidget(nome);
    nomeLayout->addWidget(nomeLine);
    cognomeLayout->addWidget(cognome);
    cognomeLayout->addWidget(cognomeLine);
    ruoloLayout->addWidget(ruolo);
    ruoloLayout->addWidget(ruoloLine);

    QVBoxLayout* datiLayout=new QVBoxLayout(this);
    datiLayout->addLayout(nomeLayout);
    datiLayout->addLayout(cognomeLayout);
    datiLayout->addLayout(ruoloLayout);

    boxAdmin->addLayout(datiLayout);

    QVBoxLayout* boxRadio=new QVBoxLayout();
    boxRadio->addWidget(basicR);
    boxRadio->addWidget(businR);
    boxRadio->addWidget(execuR);
    boxRadio->addLayout(boxAdmin);

    insertButton=new QPushButton();
    insertButton->setText("Inserisci");
    insertButton->setFixedWidth(150);



    layoutB->addLayout(boxRadio);
    layoutB->addWidget(insertButton);


    connect(insertButton, SIGNAL(clicked()), this,SLOT(insACC()));
}


void a_insertAccount::insACC()
{
    objsearch obj(usernameLine->text().toStdString());
    objresult res=admin->ricerca(&obj);

   if(res.errore==1)
   {
       account newAccount(usernameLine->text().toStdString(),mailLine->text().toStdString(),passwordLine->text().toStdString(),dataLine->date());
       if(adminR->isChecked())
       {
           administrator* newAdmin=new administrator(newAccount,nomeLine->text().toStdString(),cognome->text().toStdString(),ruolo->text().toStdString());
           admin->inserisci_account(newAdmin);
       }

       if(basicR->isChecked())
       {
           basic* newBasic=new basic(new profilo_2(),newAccount,"basic");
           admin->inserisci_account(newBasic);
       }
       if(businR->isChecked())
       {
           business* newBusiness=new business(new profilo_2(),newAccount,"basic");
           admin->inserisci_account(newBusiness);
       }
       if(execuR->isChecked())
       {
           executive* newExecutive=new executive(new profilo_2(),newAccount,"basic");
           admin->inserisci_account(newExecutive);
       }
   }
   else
   {
       QMessageBox* mess= new QMessageBox();
       mess->setWindowTitle("Errore di inserimento");
       mess->setText("Username occupato, cambiare nome");
       mess->show();
       mess->exec();

   }
   nomeLine->clear();

   cognomeLine->clear();
   passwordLine->clear();

   ruoloLine->clear();

   usernameLine->clear();
   mailLine->clear();


}
