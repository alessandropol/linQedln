#include "account.h"
#include<iostream>

//costruttore
account::account(const string u,const string m,const string p,const data& d): username(u),mail(m),password(p),data_iscrizione(d) {}

account::account(const account & nA)
{
    username=nA.get_username();
    mail=nA.get_mail();
    password=nA.get_password();
    data_iscrizione=nA.get_dataiscrizione();
}


account::~account()
{
}



objresult account::ricerca(objsearch* a)
{
    return objresult();
}


//metodi GET
string account::get_username() const
{
    return username;
}

string account::get_mail() const
{
    return mail;
}

string account::get_password() const
{
    return password;
}

data account:: get_dataiscrizione() const
{
    return data_iscrizione;
}



//metodi SET
void account::set_mail(const string m)
{
    mail=m;
}

void account::set_username(const string s)
{
    username=s;
}

void account::set_data_iscrizione(const data d)
{
    data_iscrizione=d;
}

void account::set_password(const string p)
{
    password=p;
}

bool account::operator==(const account& ac)const
{
    if(ac.get_username()==username)
        return true;
    return false;

}
