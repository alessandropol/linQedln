#ifndef LINGUA_H
#define LINGUA_H

#include<string>
using std::string;


class lingua
{
private:
    string nome_lingua;
    bool madre_lingua;
    int livello_scritto;
    int livello_orale;

public:
    lingua(string ="",bool =0,int =-1,int =-1);
    virtual ~lingua();

    string get_nome_lingua()const;
    bool is_madre_lingua()const;
    int get_livello_scritto()const;
    int get_livello_orale()const;

    void set_nome_lingua(string);
    void set_madre_lingua(bool);
    void set_livello_orale(int);
    void set_livello_scritto(int);



};

#endif // LINGUA_H
