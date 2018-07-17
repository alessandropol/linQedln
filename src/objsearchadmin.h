#ifndef OBJSEARCHADMIN_H
#define OBJSEARCHADMIN_H

#include"objsearch.h"

#include<string>
using std::string;

class objsearchAdmin : public objsearch
{
public:
    objsearchAdmin(string ="",string ="",string ="",string ="",bool =false);
    virtual ~objsearchAdmin();

    string nome;
    string cognome;
    string ruolo;
    bool tutti;
};

#endif // OBJSEARCHADMIN_H
