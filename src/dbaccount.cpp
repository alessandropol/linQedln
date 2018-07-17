#include "dbaccount.h"

DBaccount::DBaccount(){}

DBaccount::~DBaccount(){}

//modificato DB3
void DBaccount::inserisci(account *a)
{
    map<string,account*>::iterator it=DB.find(a->get_username());
    if(it==DB.end())
        DB.insert(std::pair<string,account*>(a->get_username(),a));

}

account* DBaccount::ricercaA(string s)
{
    map<string,account*>::iterator it=DB.find(s);

    if(it!=DB.end())
        return it->second;
     return 0;
}

void DBaccount::cancella(string s)
{
    map<string,account*>::iterator it=DB.find(s);
    if(it!=DB.end())
        DB.erase(it);
}

map<string,account*>* DBaccount::get_map()
{
    return &DB;
}

int DBaccount::get_size()const
{
    return DB.size();
}

