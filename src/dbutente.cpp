#include "dbutente.h"

DButente::DButente(){}

DButente::~DButente(){}

#include<iostream>


//inserimento di un nuovo cognome, se esiste lo aggiunge alla mappa, altrimenti crea una nuova mappa
void DButente::inserisci(string Scognome, account *a)
{


    //cerco la mappa contenente gli utenti che hanno quel cognome
    map<string, map<string,account*> >::iterator it= DB.find(Scognome);

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
        DB.insert(std::pair<string, map<string,account*> >(Scognome,ML));//inserisco mappa2 nella mappa1

    }
}

//ricerca della chiave=Scognome, restituisco un puntatore alla mappa2 corrispondente
map<string,account*>* DButente::ricercaU(string Scognome)
{
    map<string, map<string,account*> >::iterator it=DB.find(Scognome);
    if(it!=DB.end())
        return &(it->second);
    return 0;
}

//cancella la mappa2 che hanno la chiave=Scognome
void DButente::cancella(string Scognome)
{
    DB.erase(DB.find(Scognome));
}

int DButente::get_size()const
{
    return DB.size();
}

void DButente::rimuovi_utente(string cog, account *a)
{
    //trova la mappa di utenti su quel cognome (che contiene a)
    map<string, map<string,account*> >::iterator it= DB.find(cog);
    if(it!=DB.end())//se trovato
    {
        //estrai la mappa
        map<string,account*> *ML= &((it)->second);
        ML->erase( ML->find(a->get_username())  );//trova l'utente con l'username e poi lo elimina
        if(ML->empty())
            DB.erase(it);
    }

}

