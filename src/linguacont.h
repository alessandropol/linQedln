#ifndef LINGUACONT_H
#define LINGUACONT_H

#include <QWidget>
#include<QLabel>
#include<QPlainTextEdit>
#include<QStackedWidget>
#include<QComboBox>
#include<QCheckBox>

#include"lingua.h"
#include<vector>

using std::vector;


class linguacont : public QWidget
{
    Q_OBJECT
public:
    explicit linguacont(QWidget *parent = 0);
    linguacont(vector<lingua*>*,QWidget *parent = 0);

signals:

public slots:

private:
    QStackedWidget* stack;
    QComboBox *pageComboBox;
    QWidget* wid;
    QLabel* nomeLingua;
    QLabel* madreL;
    QCheckBox* madreCH;
    QLabel* livScritto;
    QLabel* livScrittoline;
    QLabel* livOrale;
    QLabel* livOraleline;

};

#endif // LINGUACONT_H
