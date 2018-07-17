#ifndef BUSINESS_H
#define BUSINESS_H

#include"basic.h"
#include<string>


using std::string;


class business : public basic
{
public:

    business(profilo*, const account&,string="business");
    virtual ~business();

    objresult ricerca(objsearch*);//un busines può cercare per username,COGNOME,COMPETENZE

};

#endif // BUSINESS_H
