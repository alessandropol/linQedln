#ifndef TITCONT_H
#define TITCONT_H

#include <QWidget>
#include<QLabel>
#include<QPlainTextEdit>
#include<QStackedWidget>
#include<QComboBox>

#include<vector>
#include"titolodistudio.h"

using std::vector;

class titcont : public QWidget
{
    Q_OBJECT
public:
    explicit titcont(QWidget *parent = 0);
    titcont(vector<titolodistudio*>*, QWidget *parent = 0);


signals:

public slots:

private:
    QStackedWidget* stack;
    QComboBox *pageComboBox;

    QWidget* wid;
    QLabel* nomeTitolo;
    QLabel* inizio;
    QLabel* fine;
    QLabel* voto;
    QLabel* votoline;


};

#endif // TITCONT_H
