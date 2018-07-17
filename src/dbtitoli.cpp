#include "dbtitoli.h"

DBtitoli::DBtitoli(){}

DBtitoli::~DBtitoli(){}

//inserimento di un nuovo utente nella mappa2, se non esiste la creo
void DBtitoli::inserisci(string nomeT, account *a)
{
    //cerco la mappa contenente gli utenti che hanno quel titolo
    map<string, map<string,account*> >::iterator it= DB.find(nomeT);

    //se esiste già la mappa inserisco il nuovo utente con chiave la username dell'utente
    if(it!=DB.end())
    {
        map<string,account*> *ML= &((it)->second); //prelievo l'indirizzo di memoria dove è salvata la mappa
        ML->insert(std::pair<string,account*>(a->get_username(),a)); //modifico direttamente quella mappa
    }
    else //se non esiste
    {
        map<string,account*> ML;//creo la mappa2
        ML.insert(std::pair<string,account*>(a->get_username(),a));//inserisco l'utente copiando la nuova mappa di copia

        DB.insert(std::pair<string, map<string,account*> >(nomeT,ML));//inserisco mappa2 nella mappa1
    }
}

//ricerca degli utenti che hanno quel titolo
map<string,account*>* DBtitoli::ricercaT(string nomeT)
{
    map<string, map<string,account*> >::iterator it=DB.find(nomeT);
    if(it!=DB.end())
        return &(it->second);
    return 0;
}

//cancella degli utenti che hanno quel titolo
void DBtitoli::cancella(string nomeT)
{
    DB.erase(DB.find(nomeT));
}


int DBtitoli::get_size()const
{
    return DB.size();
}

void DBtitoli::rimuovi_utente(string tit, account *a)
{
    //trova la mappa di utenti su quel titolo (che contiene a)
    map<string, map<string,account*> >::iterator it= DB.find(tit);
    if(it!=DB.end())//se trovato
    {
        //estrai la mappa
        map<string,account*> *ML= &((it)->second);
        ML->erase(ML->find(a->get_username()));//trova l'utente con l'username e poi lo elimina
        if(ML->empty())
            DB.erase(it);
    }

}


