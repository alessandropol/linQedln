#ifndef PROFILO_H
#define PROFILO_H

#include"dati_personali.h"
#include<string>


using std::string;

class profilo
{
private:
    dati_personali* datipersonali;

public:
    profilo(dati_personali* =0);
    profilo(const profilo&);
    virtual ~profilo();

    dati_personali* get_datipersonali() const;
    void set_dati_personali(dati_personali*);
};

#endif // PROFILO_H
