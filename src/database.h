#ifndef DATABASE_H
#define DATABASE_H

#include<map>
#include<string>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

using std::map;
using std::string;

#include"account.h"
#include"objresult.h"
#include"dbaccount.h"



class objsearch;

class database//non ho la necessità di creare puntatori smart
{
    friend class database_2;
    friend class database_3;
private:
    DBaccount* contAccount; //mappa con KEY=username INFO=account*

    //funzioni per il DB
    //scrittura in file XML
    void XMLscrividatiAccount(QXmlStreamWriter*,account*);

    //letturain file XML
    data XMLleggiData(QXmlStreamReader*,string);//data generica
    account XMLleggiAccount(QXmlStreamReader*);
    map<string,account*>* get_MapAccount();

public:

    database();
    virtual ~database();

    virtual void inserisci(account*);
    virtual void rimuovi(objsearch*);
    virtual objresult ricercaDB(objsearch*);
    


    virtual void scriviDB();
    virtual void leggiDB();

    objresult allAccount();

    int get_size()const;

};

#endif // DATABASE_H
