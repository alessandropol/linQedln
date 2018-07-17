#ifndef MODIFICAEXP_H
#define MODIFICAEXP_H

#include <QWidget>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QString>
#include<QLineEdit>
#include<QPlainTextEdit>
#include<QDateEdit>


#include<vector>
#include"basic.h"
#include"esperienza.h"
#include"profilo_2.h"
#include"profilowidget.h"

using std::vector;

class modificaExp : public QWidget
{
    Q_OBJECT
public:
    explicit modificaExp(QWidget *parent = 0);
    modificaExp(basic*,profiloWidget*, QWidget *parent = 0);

signals:

public slots:
    void deleteSlot();
    void addSlot();
    void endSlot();



private:

    basic* utente;
    profiloWidget* profW;

    QComboBox* combo;


    QLabel* aggiungi;

    QLabel* nomeAzienda;
    QLineEdit* nomeAziendaLine;

    QLabel* dataInizio;
    QDateEdit* dataInizioLine;

    QLabel* dataFine;
    QDateEdit* dataFineLine;

    QLabel* ruolo;
    QLineEdit* ruoloLine;

    QLabel* desc;
    QPlainTextEdit* descText;

    QPushButton* addButton;
    QPushButton* delButton;
    QPushButton* endButton;
    QLabel* elimina;

};

#endif // MODIFICAEXP_H
