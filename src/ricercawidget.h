#ifndef RICERCAWIDGET_H
#define RICERCAWIDGET_H

#include <QWidget>
#include<QTabWidget>
#include<QLabel>
#include<QPushButton>


#include"basic.h"


class ricercaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ricercaWidget(QWidget *parent = 0);
    ricercaWidget(basic*,QWidget *parent = 0);

signals:

public slots:

private:
    QWidget* objWidget;
    QLabel* ricercaLabel;
    QTabWidget* tabProfilo;

    basic* utente;


};

#endif // RICERCAWIDGET_H
