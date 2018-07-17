#ifndef TABCOMPETENZA_H
#define TABCOMPETENZA_H

#include <QWidget>

#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

#include"basic.h"
#include"profilo_2.h"
#include"risultatocognome.h"
#include"objsearchcompetenze.h"


class tabCompetenza : public QWidget
{
    Q_OBJECT
public:
    explicit tabCompetenza(QWidget *parent = 0);
    tabCompetenza(int,int,account*,QWidget *parent = 0);


signals:

public slots:
    void cercaCompetenza();

private:

    account* utente;
    QWidget* padre;

    int risultatox;
    int risultatoy;

    QLabel* nomeLabel;
    QLineEdit* nomeLine;
    QLabel* livelloLabel;
    QLineEdit* livelloLine;
    QPushButton* ricercaButton;
    risultatoCognome* risultatoW;

    objsearchCompetenze* obj;
    objresult* res;

};

#endif // TABCOMPETENZA_H
