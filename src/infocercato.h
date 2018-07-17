#ifndef INFOCERCATO_H
#define INFOCERCATO_H

#include <QWidget>

#include"basic.h"
#include<QCheckBox>

class infocercato : public QWidget
{
    Q_OBJECT
public:
    explicit infocercato(QWidget *parent = 0);
    infocercato(basic*,basic*,bool,QWidget *parent = 0);

signals:

public slots:
    void ARfriend();

private:
    QCheckBox* check;
    basic* utenteINLog;
    basic* utenteCercato;


};

#endif // INFOCERCATO_H
