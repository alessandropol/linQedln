#ifndef DBUTENTE_H
#define DBUTENTE_H

#include<map>
#include<string>

#include"account.h"

using std::string;
using std::map;

class DButente
{
private:
    map<string, map<string,account*> > DB; //mappa1: KEY=[cognome] INFO=[mappa2]
                                              //mappa2: key=[username] INFO=[account*]
public:
    DButente();
    virtual ~DButente();

    virtual void inserisci(string, account*); //inserisci  nuovo account in base al congnome
    virtual map<string,account*>* ricercaU(string); //restituisce la mappa contentene tutti gli utenti che hanno il cognome uguale
    virtual void cancella(string); //cancella gli utenti che hanno il cognome="string"
    int get_size()const;
    void rimuovi_utente(string, account*);



};

#endif // DBUTENTE_H
