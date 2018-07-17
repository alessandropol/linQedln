#include "business.h"

#include"objsearchcompetenze.h"
#include"objsearchtitolo.h"
#include"objsearchutente.h"
#include"database_2.h"
#include<iostream>

//costruttore
business::business(profilo* p,const account& a,string s):basic(p,a,s)
{
}


//distruttore
business::~business()
{

}

objresult business::ricerca(objsearch* o)
{
    //può cercare per cognome e competenza
    if(typeid(*o)==typeid(objsearchCompetenze) || typeid(*o)==typeid(objsearchUtente))
       return objsearch::DB->ricercaDB(o);
    else
       return objresult(2);
}
