#ifndef MODIFICATIT_H
#define MODIFICATIT_H

#include <QWidget>
#include<QComboBox>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QString>
#include<QLineEdit>
#include<QPlainTextEdit>
#include<QDateEdit>

#include"profilo_2.h"
#include"basic.h"
#include"profilowidget.h"




class modificaTit : public QWidget
{
    Q_OBJECT
public:
    explicit modificaTit(QWidget *parent = 0);
    modificaTit(basic*,profiloWidget*, QWidget *parent = 0);

signals:

public slots:
    void deleteSlot();
    void addSlot();
    void endSlot();


private:
    QComboBox* combo;

    QLabel* elimina;
    QLabel* aggiungi;

    QPushButton* delButton;
    QLabel* nomeTitolo;
    QLineEdit* nomeTitoloLine;
    QLabel* dataInizio;
    QDateEdit* dataInizioLine;
    QLabel* dataFine;
    QDateEdit* dataFineLine;
    QLabel* voto;
    QLineEdit* votoLine;
    QPushButton* addButton;
    QPushButton* endButton;

    profilo_2 * pf2;
    basic* utente;
    profiloWidget* profW;



};

#endif // MODIFICATIT_H
