#ifndef OBJSEARCHTITOLO_H
#define OBJSEARCHTITOLO_H

#include<string>

#include"objsearch.h"

using std::string;


class objsearchTitolo : public objsearch
{
public:
    string nome_titolo;
    float voto;

    objsearchTitolo(string ="",float =-1);
};

#endif // OBJSEARCHTITOLO_H
