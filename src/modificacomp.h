#ifndef MODIFICACOMP_H
#define MODIFICACOMP_H

#include <QWidget>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QString>
#include<QLineEdit>
#include<QPlainTextEdit>
#include"competenza.h"
#include"profilo_2.h"
#include"basic.h"
#include<profilowidget.h>



class modificaComp : public QWidget
{
    Q_OBJECT
public:
    explicit modificaComp(QWidget *parent = 0);
    modificaComp(basic*,profiloWidget*, QWidget *parent = 0);

signals:

public slots:
    void deleteSlot();
    void addSlot();
    void endSlot();

private:

    basic* utente;
    profiloWidget* profW;

    QComboBox* combo;
    QLabel* elimina;
    QPushButton* delButton;
    QLabel* aggiungi;
    QLabel* nomeCompetenza;
    QLineEdit* nomeCompetenzaLine;
    QLabel* livello;
    QLineEdit* livelloLine;
    QLabel* desc;
    QPlainTextEdit* descText;
    QPushButton* addButton;
    QPushButton* endButton;

    profilo_2* pf2;



};

#endif // MODIFICACOMP_H
