#ifndef PROFILOWIDGET_H
#define PROFILOWIDGET_H

#include<QWidget>
#include<QTabWidget>
#include<basic.h>
#include"profilo_2.h"
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>



class profiloWidget : public QWidget
{
    Q_OBJECT
public:
    explicit profiloWidget(QWidget *parent = 0);
    profiloWidget(basic*, QWidget *parent = 0);
    void createTab();
    void setPLayout();


signals:

public slots:
    void modExp();
    void modCmp();
    void modLin();
    void modTit();
    void modDati();

private:
    basic* utente;
    QLabel* titoloprofilo;
    QWidget *centralWidget;
    QTabWidget* tabProfilo;
    profilo_2 *pf2;
    profiloWidget* questa;
    QVBoxLayout* layout;
    QHBoxLayout* layoutB;

    QPushButton* datiButton;
    QPushButton* expButton;
    QPushButton* compButton;

    QPushButton* lingButton;
    QPushButton* titButton;







};

#endif // PROFILOWIDGET_H
