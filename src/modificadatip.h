#ifndef MODIFICADATIP_H
#define MODIFICADATIP_H

#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QDateEdit>

#include"profilo_2.h"
#include"basic.h"
#include"profilowidget.h"

class modificaDatiP : public QWidget
{
    Q_OBJECT
public:
    explicit modificaDatiP(QWidget *parent = 0);
    modificaDatiP(basic*,profiloWidget*, QWidget *parent = 0);

signals:

public slots:
    void modSlot();

private:
    QLabel* residenza;
    QLineEdit* residenzaLine;
    QLabel* nazionalita;
    QLineEdit* nazionalitaLine;
    QLabel* domicilio;
    QLineEdit* domicilioLine;
    QLabel* dataNascita;
    QDateEdit* dataNascitaLine;
    QPushButton*   addButton;

    QLabel* nome;
    QLabel* cognome;
    QLineEdit* nomeLine;
    QLineEdit* cognomeLine;


    profilo_2 * pf2;
    basic* utente;
    profiloWidget* profW;



};

#endif // MODIFICADATIP_H
