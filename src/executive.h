#ifndef EXECUTIVE_H
#define EXECUTIVE_H


#include"basic.h"
#include"objsearch.h"

#include<string>
#include<vector>

using std::string;
using std::vector;



class executive : public basic
{

public:
    executive(profilo*, const account& ,string="executive");
    virtual ~executive();

    objresult ricerca (objsearch*);

};
#endif // EXECUTIVE_H

