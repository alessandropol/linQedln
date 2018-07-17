#include "dbcompetenze.h"

DBcompetenze::DBcompetenze(){}

DBcompetenze::~DBcompetenze(){}

void DBcompetenze::inserisci(string nomeC, account *a)
{
    //cerco la mappa con chiave=nomeCompetenza
    map<string, map<string,account*> >::iterator it= DB.find(nomeC);

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

        DB.insert(std::pair<string, map<string,account*> >(nomeC,ML));//inserisco mappa2 nella mappa1
    }
}

map<string,account*>* DBcompetenze::ricercaC(string nomeC)
{
    map<string, map<string,account*> >::iterator it=DB.find(nomeC);
    if(it!=DB.end())
        return &(it->second);
    return 0;
}

void DBcompetenze::cancella(string nomeC)
{
    DB.erase(DB.find(nomeC));
}

int DBcompetenze::get_size()const
{
    return DB.size();
}

void DBcompetenze::rimuovi_utente(string cmp, account *a)
{
    //trova la mappa di utenti su quella competenza (che contiene a)
    map<string, map<string,account*> >::iterator it= DB.find(cmp);
    if(it!=DB.end())//se trovato
    {
        //estrai la mappa
        map<string,account*> *ML= &((it)->second);
        ML->erase(ML->find(a->get_username()));//trova l'utente con l'username e poi lo elimina
        if(ML->empty())
            DB.erase(it);
    }

}
