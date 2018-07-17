#ifndef EXPCONTAINER_H
#define EXPCONTAINER_H

#include <QWidget>
#include<QLabel>
#include<QPlainTextEdit>
#include<QStackedWidget>
#include<QComboBox>
#include<vector>
#include"esperienza.h"

using std::vector;

class expContainer : public QWidget
{
    Q_OBJECT
public:
    explicit expContainer(QWidget *parent = 0);
    expContainer(vector<esperienza*>*, QWidget *parent = 0);

signals:

public slots:

private:
    QStackedWidget* stack;
    QComboBox *pageComboBox;

    QLabel* dataI;
    QLabel* dataF;
    QLabel* ruolo;
    QLabel* ruololine;
    QLabel* descrizione;
    QPlainTextEdit* descText;



};

#endif // EXPCONTAINER_H
