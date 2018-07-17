#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H



#include<string>

#include"account.h"
#include"objsearch.h"
#include"objresult.h"

using std::string;


class administrator : public account
{
private:
    string nome;
    string cognome;
    string ruolo;

public:
    administrator(const account&, string ,string ,string);
    virtual ~administrator();

    void set_nome(string);
    void set_cognome(string);
    void set_ruolo(string);

    string get_cognome()const;
    string get_nome()const;
    string get_ruolo()const;

    virtual void inserisci_account(account*);
    virtual objresult ricerca(objsearch*);
    virtual void elimina_account(account*);
    virtual void cambia_tipologia(account*,string);

};

#endif // ADMINISTRATOR_H
