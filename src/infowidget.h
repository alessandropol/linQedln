#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include<QLabel>
#include"basic.h"

class infoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit infoWidget(QWidget *parent = 0);
    infoWidget(basic*, QWidget *parent = 0);

signals:

public slots:
    void setNumeroAmici();
    void updateInfo();



private:
    basic* utente;
    QLabel* titoloInfo;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* friendLabel;

    QLabel* nomeLine;
    QLabel* cognomeLine;
    QLabel* friendLine;

};

#endif // INFOWIDGET_H
