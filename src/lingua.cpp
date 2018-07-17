#include "lingua.h"

//construttori

lingua::lingua(string nl,bool ml,int ls,int lo):nome_lingua(nl),madre_lingua(ml),livello_scritto(ls),livello_orale(lo)
{
}


//distruttore
lingua::~lingua(){}


//metodi get
string lingua::get_nome_lingua()const
{
    return nome_lingua;
}

bool lingua::is_madre_lingua()const
{
    return madre_lingua;
}

int lingua::get_livello_scritto()const
{
    return livello_scritto;
}

int lingua::get_livello_orale()const
{
    return livello_orale;
}



//metodi set
void lingua::set_livello_orale(int lo)
{
    livello_orale=lo;
}

void lingua::set_livello_scritto(int ls)
{
    livello_scritto=ls;
}

void lingua::set_madre_lingua(bool b)
{
    madre_lingua=b;
}

void lingua::set_nome_lingua(string nl)
{
    nome_lingua=nl;
}


