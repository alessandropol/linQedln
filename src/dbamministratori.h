#ifndef DBAMMINISTRATORI_H
#define DBAMMINISTRATORI_H

#include"account.h"

#include<map>
#include<string>

using std::map;
using std::string;

class DBamministratori
{
private:
    map<string,account*> DB;
public:
    DBamministratori();
    virtual ~DBamministratori();

    virtual void inserisci(account*);//inserisce nuovo admin
    virtual account* ricercaADM(string);// ricerca admin
    virtual void cancella(string);// cancella admin
    int get_size()const;

    map<string,account*>* get_map();

};

#endif // DBAMMINISTRATORI_H
