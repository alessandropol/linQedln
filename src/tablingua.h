#ifndef TABLINGUA_H
#define TABLINGUA_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QCheckBox>

#include"basic.h"
#include"profilo_2.h"
#include"risultatocognome.h"
#include"objsearchlingua.h"




class tabLingua : public QWidget
{
    Q_OBJECT
public:
    explicit tabLingua(QWidget *parent = 0);
    tabLingua(int,int,account*,QWidget *parent = 0);

signals:

public slots:
    void cercaLingua();

private:

    int risultatox;
    int risultatoy;
    account* utente;
    QWidget* padre;


    QLabel* nomeLabel;
    QLineEdit* nomeLine;
    QLabel* livelloSLabel;
    QLineEdit* livelloSLine;
    QLabel* livelloOLabel;
    QLineEdit* livelloOLine;
    QLabel* madreLabel;
    QCheckBox* madreLine;
    QPushButton* ricercaButton;

    risultatoCognome* risultatoW;


    objsearchLingua* obj;
    objresult* res;





};

#endif // TABLINGUA_H
