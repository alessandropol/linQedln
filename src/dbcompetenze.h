#ifndef DBCOMPETENZE_H
#define DBCOMPETENZE_H

#include<map>
#include<string>

#include"account.h"

using std::string;
using std::map;


class DBcompetenze
{
private:
    map<string, map<string,account*> > DB;
public:
    DBcompetenze();
    virtual ~DBcompetenze();

    virtual void inserisci(string, account*);
    virtual map<string,account*>* ricercaC(string);
    virtual void cancella(string);
    int get_size()const;
    void rimuovi_utente(string, account*);





};

#endif // DBCOMPETENZE_H
