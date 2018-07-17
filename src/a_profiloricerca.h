#ifndef A_PROFILORICERCA_H
#define A_PROFILORICERCA_H

#include <QWidget>
#include<QLabel>
#include"basic.h"

class a_profiloRicerca : public QWidget
{
    Q_OBJECT
public:
    explicit a_profiloRicerca(QWidget *parent = 0);
    a_profiloRicerca(account*,basic*,QWidget*, QWidget *parent = 0);

signals:

public slots:

private:
    QWidget* padre;
    QWidget* risC;
    QLabel* RPLabel;
    basic* utenteCercato;

};

#endif // A_PROFILORICERCA_H
