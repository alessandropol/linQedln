#include "basic.h"
#include"objsearch.h"
#include"objsearchutente.h"
#include"database_2.h"
#include<algorithm>
#include<iostream>





//costruttore
basic::basic(profilo* p, const account& a, string s): account(a), profilo_utente(p),tipo_account(s){
}

//distruttore
basic::~basic()
{
    if(this->get_profilo())
    {
        //elimino ogni sua traccia dai DB
        objsearch o(this->get_username());
        objsearch::DB->rimuovi(&o);

        //elimino il suo profilo con tutto il resto dallo heap
        delete(this->get_profilo());
    }
}

objresult basic::ricerca(objsearch* o)
{
    if(typeid(*o) == typeid(objsearchUtente))
    {
       return objsearch::DB->ricercaDB(o);
    }
    return objresult(2);
}


//aggiungere eccezione nel caso ci siano doppioni
void basic::add_friend(account* s)
{
    bool trovato=false;
    vector<account*>::iterator it=rete_amici.begin();
    for(;it!=rete_amici.end() && trovato==0; ++it)
    {
        if((*it)->get_username()==s->get_username())
        trovato=true;
    }
    if(!trovato)
       rete_amici.push_back(s);
}

account* basic::find_friend(account *a)
{
    vector<account*>::iterator it= std::find( vector<account*>::iterator(rete_amici.begin()), vector<account*>::iterator(rete_amici.end()),a);
    if(it!=rete_amici.end())
       return (*it);
    else
       return 0;
}

void basic::delete_friend(account *a)
{
    vector<account*>::iterator it= std::find( vector<account*>::iterator(rete_amici.begin()), vector<account*>::iterator(rete_amici.end()),a);
    if(it!=rete_amici.end())
    {
       rete_amici.erase(it);
    }
}

int basic::size_friend()const
{
    return rete_amici.size();
}

void basic::set_reteamici(const vector<account*>& va)
{
    rete_amici.clear();;
    rete_amici=va;
}



//metodi get
profilo* basic::get_profilo()const
{
    return profilo_utente;
}

string basic::get_tipoaccount()const
{
    return tipo_account;
}

vector<account*> * basic::get_reteamici()
{
    return &rete_amici;
}



//metodo set

void basic::set_tipoaccount(const string s)
{
    tipo_account=s;
}

void basic::set_profilo(profilo* pf)
{
    profilo_utente=pf;
}

void basic::aggiungi_lingua(const lingua & li)
{
    lingua *nuova=new lingua(li);//creo la lingua
    profilo_2 *pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
       pf2->aggiungi_lingua(nuova);// la inserisco nel profilo dell'utente
       database_2 *db=dynamic_cast<database_2*>(objsearch::DB);
       objsearchLingua obj(nuova->get_nome_lingua());
       db->aggiungi_account_contenitore(&obj,this);//la inserisco tra i parametri del database
    }
}

void basic::aggiungi_esperienza(const esperienza& exp)
{
    esperienza *nuova=new esperienza(exp);//creo la lingua
    profilo_2 *pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    pf2->aggiungi_esperienza(nuova);// la inserisco nel profilo dell'utente
}

void basic::aggiungi_competenza(const competenza& cmp)
{
    competenza *nuova=new competenza(cmp);
    profilo_2 *pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
        pf2->aggiungi_competenza(nuova);
        database_2 *db=dynamic_cast<database_2*>(objsearch::DB);
        objsearchCompetenze obj(nuova->get_nome_competenza());
        db->aggiungi_account_contenitore(&obj,this);

    }
}

void basic::aggiungi_titolo(const titolodistudio& it)
{
    titolodistudio *nuova=new titolodistudio(it);
    profilo_2 *pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
        pf2->aggiungi_titolo(nuova);
        database_2 *db=dynamic_cast<database_2*>(objsearch::DB);
        objsearchTitolo obj(nuova->get_nome_titolo());
        db->aggiungi_account_contenitore(&obj,this);
    }

}

void basic::cancella_competenza(string nomeC)
{
    profilo_2* pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
        database_2 *db2=dynamic_cast<database_2*>(objsearch::DB);
        if(db2)
        {
            objsearchCompetenze obj(nomeC);
            db2->elimina_account_contenitore(&obj,this);//cnacello la competenza nei database
        }
        pf2->cancella_cmp(nomeC);//cancella la competenza nel proprio profilo (e dal heap)
    }
}

void basic::cancella_lingua(string nomeL)
{
    profilo_2* pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
        database_2 *db2=dynamic_cast<database_2*>(objsearch::DB);
        if(db2)
        {
            objsearchLingua obj(nomeL);
            db2->elimina_account_contenitore(&obj,this);//cnacello la competenza nei database
        }
        pf2->cancella_lin(nomeL);//cancella la competenza nel proprio profilo

    }
}


void basic::cancella_esperienza(string nomee)
{
    profilo_2* pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
        pf2->cancella_exp(nomee);//cancella l'esperienza nel proprio profilo
}

void basic::cancella_titolo(string nomet)
{
    profilo_2* pf2=dynamic_cast<profilo_2*>(this->get_profilo());
    if(pf2)
    {
        database_2 *db2=dynamic_cast<database_2*>(objsearch::DB);
        if(db2)
        {
            objsearchTitolo obj(nomet);
            db2->elimina_account_contenitore(&obj,this);//cnacello la competenza nei database
        }
        pf2->cancella_tit(nomet);//cancella la competenza nel proprio profilo

    }
}
