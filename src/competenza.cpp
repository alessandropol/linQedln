#include "competenza.h"


//costruttore
competenza::competenza(string nc,int lc,string dc):nome_competenza(nc),descrizione_competenza(dc),livello_competenza(lc)
{}



//distruttore
competenza::~competenza(){}



//metodi get
string competenza::get_nome_competenza()const
{
    return nome_competenza;
}

string competenza::get_descrizione_competenza()const
{
    return descrizione_competenza;
}

int competenza::get_livello_competenza()const
{
    return livello_competenza;
}



//metodi set
void competenza::set_nome_competenza(string s)
{
    nome_competenza=s;
}

void competenza::set_descrizione_competenza(string s)
{
    descrizione_competenza=s;
}

void competenza::set_livello_competenza(int s)
{
    livello_competenza=s;
}

