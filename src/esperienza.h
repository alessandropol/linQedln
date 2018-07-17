#ifndef ESPERIENZA_H
#define ESPERIENZA_H

#include<string>
#include"data.h"

using std::string;

class esperienza
{
private:
    string azienda;
    data data_inizio;
    data data_fine;
    string ruolo;
    string descrizione;

public:
    esperienza();
    esperienza(const string& ="",const data& =data(),const data& =data(),const string& ="",const string& ="");
    esperienza(const esperienza&);
    virtual ~esperienza();

    string get_azienda()const;
    string get_ruolo()const;
    string get_descrizione()const;
    data get_data_fine()const;
    data get_data_inizio()const;

    void set_azienda(string);
    void set_data_inizio(data);
    void set_data_fine(data);
    void set_ruolo(string);
    void set_descrizione(string);




};

#endif // ESPERIENZA_H
