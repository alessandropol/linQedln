#ifndef DBLINGUE_H
#define DBLINGUE_H


#include<map>
#include<string>

#include"account.h"

using std::string;
using std::map;


using std::string;
using std::map;

class DBlingue
{
private:
    //mappa key=nome_lingue(string), info=mappa( key=user_name info=account*)
    map<string, map<string,account*> > DB;
public:
    DBlingue();
    virtual ~DBlingue();

    virtual void inserisci(string, account*);
    virtual map<string,account*>* ricercaL(string);
    virtual void cancella(string);
    int get_size()const;
    void rimuovi_utente(string, account*);



};

#endif // DBLINGUE_H
