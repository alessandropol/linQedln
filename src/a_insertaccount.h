#ifndef A_INSERTACCOUNT_H
#define A_INSERTACCOUNT_H

#include <QWidget>

#include<QLineEdit>
#include<QDateEdit>
#include<basic.h>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QRadioButton>

#include"administrator.h"
#include"business.h"
#include"basic.h"
#include"executive.h"
#include"QString"

class a_insertAccount : public QWidget
{
    Q_OBJECT
public:
    explicit a_insertAccount(QWidget *parent = 0);
    a_insertAccount(administrator*,QWidget *parent = 0);
    void updateNCR(QString,QString,QString);

signals:

public slots:
    void insACC();

private:

    administrator* admin;
    QLabel* titolo;
    QLabel* usernameLabel;
    QLabel* mailLabel;
    QLabel* passwordLabel;
    QLabel* dataILabel;

    QLabel* nome;
    QLineEdit* nomeLine;
    QLabel* cognome;
    QLineEdit* cognomeLine;
    QLabel* ruolo;
    QLineEdit* ruoloLine;

    QLineEdit* usernameLine;
    QLineEdit* mailLine;
    QLineEdit* passwordLine;
    QDateEdit* dataLine;

    QVBoxLayout* layoutB;
    QRadioButton* adminR;
    QRadioButton* basicR;
    QRadioButton* businR;
    QRadioButton* execuR;
    QPushButton* insertButton;

};

#endif // A_INSERTACCOUNT_H
