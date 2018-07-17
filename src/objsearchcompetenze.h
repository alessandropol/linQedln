#ifndef OBJSEARCHCOMPETENZE_H
#define OBJSEARCHCOMPETENZE_H

#include<string>
#include"objsearch.h"

using std::string;

class objsearchCompetenze : public objsearch
{
public:
    string nome_competenza;
    int livello;

    objsearchCompetenze(string ="", int =-1);
    virtual ~objsearchCompetenze();

};

#endif // OBJSEARCHCOMPETENZE_H
