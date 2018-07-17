#include "profilo.h"


//costruttore
profilo::profilo(dati_personali* p):datipersonali(p)
{}

profilo::profilo(const profilo& p)
{
    datipersonali=new dati_personali(*p.get_datipersonali());
}



//distruttore
profilo::~profilo()
{
    delete(datipersonali);
}


//metodi get
dati_personali* profilo::get_datipersonali()const
{
    return datipersonali;
}





//metodi set
void profilo::set_dati_personali(dati_personali *p)
{
    datipersonali=p;
}


