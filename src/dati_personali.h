#ifndef DATI_PERSONALI_H
#define DATI_PERSONALI_H

#include<string>
#include"data.h"
using std::string;

class dati_personali
{
private:
    string nome;
    string cognome;
    string residenza;
    string domicilio;
    string nazionalita;
    data datanascita;

public:

    dati_personali(string ="", string ="", string ="", string ="",string ="",data =data());
    dati_personali(const dati_personali&);
    ~dati_personali();

    string get_nome()const;
    string get_cognome()const;
    string get_residenza()const;
    string get_domicilio()const;
    string get_nazionalita()const;
    data get_datanascita()const;

    void set_nome(const string); //meglio svilupparlo dopo
    void set_cognome(const string); //potenziato
    void set_residenza(const string);
    void set_domicilio(const string);
    void set_nazionalita(const string);
    void set_datanascita(data);

};

#endif // DATI_PERSONALI_H
