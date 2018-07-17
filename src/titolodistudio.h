#ifndef TITOLODISTUDIO_H
#define TITOLODISTUDIO_H

#include"data.h"
#include<string>


using std::string;

class titolodistudio
{
private:
    string nome_titolo;
    data inizio_studi;
    data fine_studi;
    float votofinale;

public:
    titolodistudio(string ="",data =data(),data =data(),float =-1);
    virtual ~titolodistudio();

    string get_nome_titolo()const;
    data get_inizio_studi()const;
    data get_fine_studi()const;
    float get_votofinale()const;

    void set_nome_titolo(string);
    void set_inzio_studi(data);
    void set_fine_studi(data);
    void set_votofinale(float);


};

#endif // TITOLODISTUDIO_H
