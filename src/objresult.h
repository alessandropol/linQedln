#ifndef OBJRESULT_H
#define OBJRESULT_H

#include<string>
#include<vector>


#include"account.h"
class account;

using std::vector;
using std::string;

class objresult
{
public:
    objresult(int =0,account* =0, vector<account*> =vector<account*>());
    objresult(const objresult&);

    account* singleresult;
    vector<account*> multiresult;
    int errore;


};

#endif // OBJRESULT_H
