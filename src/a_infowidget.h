#ifndef A_INFOWIDGET_H
#define A_INFOWIDGET_H

#include <QWidget>
#include<QLabel>

#include"administrator.h"



class A_infoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit A_infoWidget(QWidget *parent = 0);
    A_infoWidget(administrator*,QWidget *parent = 0);

signals:

public slots:

private:
private:
    administrator* admin;
    QLabel* titoloInfo;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* ruoloLabel;

    QLabel* nomeLine;
    QLabel* cognomeLine;
    QLabel* ruoloLine;


};

#endif // A_INFOWIDGET_H
