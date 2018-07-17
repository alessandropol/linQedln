#include "dbamministratori.h"


DBamministratori::DBamministratori()
{
}

DBamministratori::~DBamministratori(){}

void DBamministratori::inserisci(account *a)
{
    map<string,account*>::iterator it=DB.find(a->get_username());
    if(it==DB.end())
        DB.insert(std::pair<string,account*>(a->get_username(),a));
}

account* DBamministratori::ricercaADM(string s)
{
    map<string,account*>::iterator it=DB.find(s);
    if(it!=DB.end())
        return (it)->second;
    else
        return 0;
}

void DBamministratori::cancella(string s)
{
    map<string,account*>::iterator it=DB.find(s);
    if(it!=DB.end())
        DB.erase(it);
}

map<string,account*>* DBamministratori::get_map()
{
    return &DB;
}

int DBamministratori::get_size()const
{
    return DB.size();
}

