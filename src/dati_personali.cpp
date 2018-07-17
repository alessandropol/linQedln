#include "dati_personali.h"
#include"objsearch.h"
#include"objsearchutente.h"
#include<vector>
#include"database_2.h"
#include"objresult.h"

using std::vector;

//costruttori
dati_personali::dati_personali( string no, string co, string re, string dom, string na,data dn):nome(no),cognome(co),residenza(re),domicilio(dom),nazionalita(na),datanascita(dn)
{}

dati_personali::dati_personali(const dati_personali& dp)
{
    cognome=dp.get_cognome();
    nome=dp.get_nome();
    nazionalita=dp.get_nazionalita();
    domicilio=dp.get_domicilio();
    residenza=dp.get_residenza();
    datanascita=dp.get_datanascita();
}



//distruttori
dati_personali::~dati_personali(){}




//metodi get
string dati_personali::get_nome()const{
    return nome;
}

string dati_personali::get_cognome()const{
    return cognome;
}

string dati_personali::get_residenza()const{
    return residenza;
}

string dati_personali::get_domicilio()const{
    return domicilio;
}

data dati_personali::get_datanascita()const{
    return datanascita;
}

string dati_personali::get_nazionalita()const{
    return nazionalita;
}




//metodi set
void dati_personali::set_nome(const string n)
{
    nome=n;
}

//attenzione a modificare il cognome
void dati_personali::set_cognome(const string c)
{
    if(!cognome.empty())//se è pieno
    {
        if(cognome!=c)// se non uguale
        {
            database_2* db2=dynamic_cast<database_2*>(objsearch::DB);
            if(db2)
            {
                objsearchUtente obj(cognome);
                objresult risultato=objsearch::DB->ricercaDB(&obj);
                vector<account*>::iterator it=risultato.multiresult.begin();

                for(;it!=risultato.multiresult.end();++it)
                {
                    basic* b=dynamic_cast<basic*>((*it));
                    if(this==b->get_profilo()->get_datipersonali())
                    {
                        db2->elimina_account_contenitore(&obj,b);
                        cognome=c;
                        obj=objsearchUtente(c);
                        db2->aggiungi_account_contenitore(&obj,b);
                    }

                }

            }
        }
    }
    else //se lo sto inzializzando (XMLdatabas)
        cognome=c;

}

void dati_personali::set_residenza(const string r)
{
    residenza=r;
}

void dati_personali::set_datanascita(data d)
{
    datanascita=d;
}

void dati_personali::set_domicilio(const string d)
{
    domicilio=d;
}

void dati_personali::set_nazionalita(const string n)
{
    nazionalita=n;
}
