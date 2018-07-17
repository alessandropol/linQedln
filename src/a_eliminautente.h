#ifndef A_ELIMINAUTENTE_H
#define A_ELIMINAUTENTE_H

#include <QWidget>
#include"basic.h"
#include"administrator.h"
#include<QPushButton>

class a_eliminaUtente : public QWidget
{
    Q_OBJECT
public:
    explicit a_eliminaUtente(QWidget *parent = 0);
    a_eliminaUtente(administrator*, basic*,QWidget*,QWidget *parent = 0);

signals:

public slots:
    void delUtente();

private:
    administrator* admin;
    basic* utente;
    QPushButton* delButton;
    QWidget* padreC;



};

#endif // A_ELIMINAUTENTE_H
