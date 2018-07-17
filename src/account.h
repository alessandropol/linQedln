#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

#include"data.h"
#include"objsearch.h"
#include"objresult.h"

class objresult;

using std::string;

class account
{
private:

    string username; //non esistone 2 username uguali
    string mail;
    string password;
    data data_iscrizione;

public:
    account(const string ="-1",const string ="-1", const string ="-1",const data& =data());
    account(const account&);
    virtual ~account();

    virtual objresult ricerca(objsearch*);

    string get_username() const;
    string get_mail() const;
    string get_password() const;
    data get_dataiscrizione() const;

    void set_username(const string); //non credo bisogni svilupparla
    void set_mail(const string);
    void set_password(const string);
    void set_data_iscrizione(const data);

    bool operator==(const account&)const;
};
#endif // ACCOUNT_H
