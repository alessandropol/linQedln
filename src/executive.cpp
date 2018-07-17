#include "executive.h"
#include"database_2.h"
#include<iostream>

//costruttore
executive::executive(profilo* p,  const account& a, string s):basic(p,a,s)
{
}

//distruttore
executive::~executive()
{}


objresult executive::ricerca(objsearch* o)
{
       return objsearch::DB->ricercaDB(o);
}
