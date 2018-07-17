#ifndef TABALL_H
#define TABALL_H

#include <QWidget>
#include"administrator.h"

#include<risultatocognome.h>

#include"objsearchadmin.h"


class tabAll : public QWidget
{
    Q_OBJECT
public:
    explicit tabAll(QWidget *parent = 0);
    tabAll(int,int,administrator*,QWidget *parent = 0);

signals:

public slots:
    void cercaTutti();
    
private:
    QPushButton* ricercaButton;
    QWidget* padre;
    administrator* admin;
    risultatoCognome* risultatoW;
    int risultatox;
    int risultatoy;

    objsearchAdmin* obj;
    objresult* res;
    

};

#endif // TABALL_H
