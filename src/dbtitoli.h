#ifndef DBTITOLI_H
#define DBTITOLI_H


#include<map>
#include<string>

#include"account.h"


using std::string;
using std::map;


class DBtitoli
{
private:
    map<string, map<string,account*> > DB;  //mappa1: KEY=[nome_titolo_di_studio] INFO=[mappa2]
                                                //mappa2: key=[username] INFO=[account*]
public:

    DBtitoli();
    virtual ~DBtitoli();

    virtual void inserisci(string, account*);
    virtual map<string,account*>* ricercaT(string);
    virtual void cancella(string);
    int get_size()const;
    void rimuovi_utente(string, account*);


};



#endif // DBTITOLI_H
