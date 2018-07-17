#ifndef TABAMICI_H
#define TABAMICI_H

#include <QWidget>
#include<QPushButton>
#include"basic.h"

#include<risultatocognome.h>

class tabAmici : public QWidget
{
    Q_OBJECT
public:
    explicit tabAmici(QWidget *parent = 0);
    tabAmici(int,int,basic*,QWidget *parent = 0);


signals:

public slots:
    void cercaAmici();

private:
    QPushButton* ricercaButton;
    QWidget* padre;
    basic* utente;
    risultatoCognome* risultatoW;
    int risultatox;
    int risultatoy;




};

#endif // TABAMICI_H
