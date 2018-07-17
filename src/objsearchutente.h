#ifndef OBJSEARCHUTENTE_H
#define OBJSEARCHUTENTE_H


#include<string>

#include"objsearch.h"
using std::string;


class objsearchUtente : public objsearch
{
public:
    string nome;
    string cognome;

    objsearchUtente(string ="", string ="");
    virtual ~objsearchUtente();
};

#endif // OBJSEARCHUTENTE_H
