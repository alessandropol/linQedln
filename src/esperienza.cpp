#include "esperienza.h"


//costruttore


esperienza::esperienza(){}

esperienza::esperienza(const string& az,const data& di,const data& df,const string& ru,const string& des): azienda(az),data_inizio(di),data_fine(df),ruolo(ru),descrizione(des)
{}

esperienza::esperienza(const esperienza & exp)
{
    azienda=exp.get_azienda();
    data_inizio=exp.get_data_inizio();
    data_fine=exp.get_data_fine();
    ruolo=exp.get_ruolo();
    descrizione=exp.get_descrizione();
}




//distruttore
esperienza::~esperienza(){}

//metodi get
string esperienza::get_azienda()const
{
    return azienda;
}

data esperienza::get_data_fine()const
{
    return data_fine;
}

data esperienza::get_data_inizio()const
{
    return data_inizio;
}

string esperienza::get_ruolo()const
{
    return ruolo;
}

string esperienza::get_descrizione()const
{
    return descrizione;
}



//metodi set
void esperienza::set_azienda(string az)
{
    azienda=az;
}

void esperienza::set_data_fine(data df)
{
    data_inizio=df;
}

void esperienza::set_data_inizio(data di)
{
    data_fine=di;
}

void esperienza::set_ruolo(string ru)
{
    ruolo=ru;
}

void esperienza::set_descrizione(string des)
{
    descrizione=des;
}







