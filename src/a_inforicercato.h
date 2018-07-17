#ifndef A_INFORICERCATO_H
#define A_INFORICERCATO_H

#include <QWidget>
#include"basic.h"


class a_inforicercato : public QWidget
{
    Q_OBJECT
public:
    explicit a_inforicercato(QWidget *parent = 0);
    a_inforicercato(basic*,QWidget *parent = 0);
signals:

public slots:
    void vediProfilo();


private:
    basic* utente;


};

#endif // A_INFORICERCATO_H
