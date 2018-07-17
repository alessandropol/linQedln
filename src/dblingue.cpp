#include "dblingue.h"


DBlingue::DBlingue(){}
DBlingue::~DBlingue(){}

void DBlingue::inserisci(string nomeL, account *a)
{
    //cerco la mappa contenente gli utenti che hanno quella lingua
    map<string, map<string,account*> >::iterator it= DB.find(nomeL);

    //se esiste già la mappa inserisco il nuovo utente con chiave la username dell'utente
    if(it!=DB.end())
    {
        map<string,account*> *ML= &((it)->second);
        ML->insert(std::pair<string,account*>(a->get_username(),a));
    }
    else //se non esiste
    {
        map<string,account*> ML;//creo la mappa2
        ML.insert(std::pair<string,account*>(a->get_username(),a));//inserisco l'utente

        DB.insert(std::pair<string, map<string,account*> >(nomeL,ML));//inserisco mappa2 nella mappa1
    }
}

map<string,account*>* DBlingue::ricercaL(string nomeL)
{
    map<string, map<string,account*> >::iterator it=DB.find(nomeL);
    if(it!=DB.end())
        return &(it->second);
    return 0;
}

void DBlingue::cancella(string nomeL)
{
    DB.erase( DB.find(nomeL)   );


}

int DBlingue::get_size()const
{
    return DB.size();
}

void DBlingue::rimuovi_utente(string nomeL, account *a)
{
    //trova la mappa di utente su quella lingua (che contiene l'utente)
    map<string, map<string,account*> >::iterator it= DB.find(nomeL);
    if(it!=DB.end())//se trovat
    {
        //estrai la mappa
        map<string,account*> *ML= &((it)->second);
        ML->erase(ML->find(a->get_username()));//trova l'utente con l'username e poi lo elimina
        if(ML->empty())
            DB.erase(it);
    }
}

