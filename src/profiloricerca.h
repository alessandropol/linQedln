#ifndef PROFILORICERCA_H
#define PROFILORICERCA_H

#include <QWidget>
#include<QLabel>

#include"basic.h"

class profiloRicerca : public QWidget
{
    Q_OBJECT
public:
    explicit profiloRicerca(QWidget *parent = 0);
    profiloRicerca(basic*,basic*,bool f, QWidget *parent = 0);

signals:

public slots:

private:
     QWidget* IPwidget;
     QLabel* RPLabel;
     basic* utente;

};

#endif // PROFILORICERCA_H
