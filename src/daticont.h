#ifndef DATICONT_H
#define DATICONT_H

#include <QWidget>
#include<QLabel>
#include"dati_personali.h"

class datiCont : public QWidget
{
    Q_OBJECT
public:
    explicit datiCont(QWidget *parent = 0);
    datiCont(dati_personali*, QWidget *parent = 0);

signals:

public slots:

private:
    QWidget* datiWidget;

    QLabel* residenza;
    QLabel* residenzaLine;
    QLabel* nazionalita;
    QLabel* nazionalitaLine;
    QLabel* domicilio;
    QLabel* domicilioLine;

};

#endif // DATICONT_H
