#ifndef RISULTATOCOGNOME_H
#define RISULTATOCOGNOME_H

#include <QWidget>
#include<QTableWidget>
#include<QSignalMapper>
#include<QLabel>
#include<QHeaderView>
#include<QScrollBar>
#include<QPushButton>
#include<QLineEdit>

#include"profiloricerca.h"

#include<vector>
#include"objresult.h"
#include"basic.h"
#include"profiloricerca.h"
#include"a_profiloricerca.h"
#include<QPushButton>



using std::vector;

class risultatoCognome : public QWidget
{
    Q_OBJECT
public:
    explicit risultatoCognome(QWidget *parent = 0);
    risultatoCognome(int,int,account*,objresult*,QWidget *parent = 0);

signals:
     void clicked(const QString &text);

public slots:
    void clickedSlot(QString);
    void chiudi();

private:
    QWidget* padre;
    QTableWidget* table;
    QSignalMapper *signalMapper;
    objresult* risultato;
    account* utente;
    profiloRicerca*  pr;
    a_profiloRicerca* prA;
    basic* utenteCercato;

};

#endif // RISULTATOCOGNOME_H
