#ifndef PAGEADMIN_H
#define PAGEADMIN_H

#include <QWidget>
#include"administrator.h"

class pageAdmin : public QWidget
{
    Q_OBJECT
public:
    explicit pageAdmin(QWidget *parent = 0);
    pageAdmin(administrator*,QWidget *parent = 0);

signals:

public slots:
    void saveDB();

};

#endif // PAGEADMIN_H
