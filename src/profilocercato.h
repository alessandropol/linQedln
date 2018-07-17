#ifndef PROFILOCERCATO_H
#define PROFILOCERCATO_H

#include <QWidget>
#include"basic.h"

class profiloCercato : public QWidget
{
    Q_OBJECT
public:
    explicit profiloCercato(QWidget *parent = 0);
    profiloCercato(basic*,QWidget *parent = 0);

signals:

public slots:

};

#endif // PROFILOCERCATO_H
