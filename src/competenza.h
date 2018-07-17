#ifndef COMPETENZA_H
#define COMPETENZA_H

#include<string>

using std::string;



class competenza
{
private:
    string nome_competenza;
    string descrizione_competenza;
    int livello_competenza;

public:
    competenza(string ="",int =-1,string ="");
    virtual ~competenza();

    string get_nome_competenza()const;
    string get_descrizione_competenza()const;
    int get_livello_competenza()const;

    void set_nome_competenza(string);
    void set_descrizione_competenza(string);
    void set_livello_competenza(int);

};

#endif // COMPETENZA_H
