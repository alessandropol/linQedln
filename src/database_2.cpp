#include"database_2.h"
#include"business.h"
#include"executive.h"

#include<typeinfo>
#include<vector>
#include<iostream>




#include<QString>

using std::vector;


//costruttore
database_2::database_2(){
    contUtente=new DButente();
    contLingue=new  DBlingue();
    contTitoli=new DBtitoli();
    contCompetenze=new DBcompetenze();
}

//distruttore
database_2::~database_2(){
    delete contUtente;
    delete contLingue;
    delete contTitoli;
    delete contCompetenze;
}



//INSERIMENTO DI UN NUOVO ACCOUNT
void database_2::inserisci(account* a)
{
    this->database::inserisci(a);//inserisce l'account

    //inserimento dati nei database
    basic* b=dynamic_cast<basic*>(a);
    if(b)
    {
        profilo_2 *pf2=dynamic_cast<profilo_2*>(b->get_profilo());
        if(pf2)
        {
            this->inserisciDBLingue(pf2,a);
            this->inserisciDBCompetenze(pf2,a);
            this->inserisciDBTitoli(pf2,a);
            this->inserisciDBUtente(pf2,a);
        }
    }
}



//RICERCA ACCOUNT
objresult database_2::ricercaDB(objsearch* obj)
{
    objresult risultato;

    if(typeid(*obj)==typeid(objsearchLingua))
    {
        objsearchLingua *o=dynamic_cast<objsearchLingua*>(obj);
        if(o)
            risultato.multiresult= ricerca_lingue(o);
    }

    if(typeid(*obj)==typeid(objsearchCompetenze))
    {
        objsearchCompetenze *o=dynamic_cast<objsearchCompetenze*> (obj);
        if(o)
            risultato.multiresult= ricerca_competenze(o);
    }
    if(typeid(*obj)==typeid(objsearchTitolo))
    {
            objsearchTitolo *o=dynamic_cast<objsearchTitolo*> (obj);
            if(o)
                risultato.multiresult= ricerca_titolo(o);
    }
    if(typeid(*obj)==typeid(objsearchUtente))
    {
        objsearchUtente *o=dynamic_cast<objsearchUtente*> (obj);
        if(o)
            risultato.multiresult= ricerca_utente(o);
    }
    if(typeid(*obj)==typeid(objsearch))
        return this->database::ricercaDB(obj);

    return risultato;
}

void database_2::rimuovi(objsearch* obj)//username
{

    //cerco il nomeutente associato
    basic* b=dynamic_cast<basic*>(objsearch::DB->ricercaDB(obj).singleresult);
    if(b)
    {
        profilo_2* pf2=dynamic_cast<profilo_2*>(b->get_profilo());
        //elimino tutte le sue caratteristiche
        if(pf2)
        {
            //tolgo tutte le sue competenze dai db
            vector<competenza*>* Ccomp=pf2->get_competenze();
            vector<competenza*>::iterator itc=Ccomp->begin();
            while(itc!=Ccomp->end())
            {
                objsearchCompetenze objC((*itc)->get_nome_competenza());
                this->elimina_account_contenitore(&objC,b);
                ++itc;
            }

            //tolgo tutte le sue lingue dai db
            vector<lingua*>* Cling=pf2->get_lingue();
            vector<lingua*>::iterator itl=Cling->begin();
            while(itl!=Cling->end())
            {
                objsearchLingua objL((*itl)->get_nome_lingua());
                this->elimina_account_contenitore(&objL,b);
                ++itl;
            }

            //tolgo tutte le sue titoli dai db
            vector<titolodistudio*>* Ctit=pf2->get_titolodistudio();
            vector<titolodistudio*>::iterator itt=Ctit->begin();
            while(itt!=Ctit->end())
            {
                objsearchTitolo objT((*itt)->get_nome_titolo());
                this->elimina_account_contenitore(&objT,b);
                ++itt;
            }
            //lo tolgo dai cognomi
            objsearchUtente objU(pf2->get_datipersonali()->get_cognome());
            this->elimina_account_contenitore(&objU,b);
        }
    }
    //elimino l'account
    this->database::rimuovi(obj);
}



//inserimento dell'utente nel DBlingue
void database_2::inserisciDBLingue(profilo_2* pf2,account* a)
{
    //recupero il vettore della lingue parlate dell'utente a
    vector<lingua*> *VL=pf2->get_lingue();

    vector<lingua*>::iterator it=VL->begin();
    for(;it!=VL->end();++it)
    {
        lingua* li=(*it);//estraggo una lingua parlata
        contLingue->inserisci(li->get_nome_lingua(),a);//inserisce nel DBlingue KEY=nome_lingua INFO=account*
    }
}


//inserimento dell'utente nel DBcompetenze
void database_2::inserisciDBCompetenze(profilo_2* pf2,account* a)
{
    //vettore delle competenze dell'utente a
    vector<competenza*> *VC=pf2->get_competenze();

    vector<competenza*>::iterator it=VC->begin();
    for(; it != VC->end();++it)
    {
        competenza* cmp=(*it);
        contCompetenze->inserisci(cmp->get_nome_competenza(),a);
    }
}


//inserimento dell'untente nel DBTitoli
void database_2::inserisciDBTitoli(profilo_2 *pf2,account *a)
{
    //vettore dei titoli di studi dell'utente
    vector<titolodistudio*> *VT=pf2->get_titolodistudio();

    vector<titolodistudio*>::iterator it=VT->begin();
    for(;it!=VT->end();++it)
    {
        titolodistudio* ts=(*it);
        contTitoli->inserisci(ts->get_nome_titolo(),a);
    }
}

//inserimento dell'utente nel DButente
void database_2::inserisciDBUtente(profilo_2* pf2,account* a)
{
    dati_personali* dp=pf2->get_datipersonali();
    contUtente->inserisci(dp->get_cognome(),a);

}


//ricerca tutti gli utenti che hanno almeno una COMPETENZA che rispetta l'oggetto di ricerca 'o'
vector<account*> database_2::ricerca_competenze(objsearchCompetenze* o)
{
    //vettore che conterrà il risultato della ricerca
    vector<account*> VA;

    //prelevo la mappa contenente tutti gli utenti che hanno la competenza richiesta
    map<string,account*> * mapCompentenze= contCompetenze->ricercaC(o->nome_competenza);
    if(mapCompentenze)
    {
        map<string,account*>::iterator it=mapCompentenze->begin();

        for(;it!= mapCompentenze->end();++it)
        {
            if(o->livello>0)// se è stata impostata qualche restrizione
            {
                basic *b=dynamic_cast<basic*>((it)->second);
                profilo_2 *pf2=dynamic_cast<profilo_2*>(b->get_profilo());

                //vettore competenze dell'account b
                vector<competenza*>* VC=pf2->get_competenze();
                vector<competenza*>::iterator il=VC->begin();
                for(;il!=VC->end();++il)//copio gli elementi nel vettore che la rispettano
                {
                    competenza* c=(*il);
                    if( (c->get_livello_competenza() >= o->livello) && (c->get_nome_competenza() == o->nome_competenza))
                          VA.push_back(b);
                }
             }
             else//copio semplicemente i valori
                VA.push_back((it)->second);
        }

    }

    return VA;
}

//ricerca tutti gli utenti che hanno almeno un TITOLO che rispetta l'oggetto di ricerca 'o'
vector<account*> database_2::ricerca_titolo(objsearchTitolo* o)
{
    vector<account*> VA;
    map<string,account*>* mapTitolo=contTitoli->ricercaT(o->nome_titolo);
    if(mapTitolo)
    {
        map<string,account*>::iterator it=mapTitolo->begin();

        for(;it!= mapTitolo->end();++it)
        {
            if(o->voto>0)//controllo restrizioni
            {
                basic *b=dynamic_cast<basic*>((it)->second);
                profilo_2 *pf2=dynamic_cast<profilo_2*>(b->get_profilo());
                //vettore lingue dell'account b
                vector<titolodistudio*>* VL=pf2->get_titolodistudio();
                vector<titolodistudio*>::iterator il=VL->begin();
                for(;il!=VL->end();++il)
                {
                    titolodistudio* t=(*il);
                    if(t->get_nome_titolo() == o->nome_titolo && t->get_votofinale() >= o->voto)
                          VA.push_back(b);
                }
             }
             else
                VA.push_back((it)->second);
        }

    }

    return VA;
}

//ricerca tutti gli utenti per COGNOME e che rispetta l'oggetto di ricerca 'o'
vector<account*> database_2::ricerca_utente(objsearchUtente* o)
{
    vector<account*> VA;
    map<string,account*>* mapUtente= contUtente->ricercaU(o->cognome);
    if(mapUtente)
    {
        map<string,account*>::iterator it=mapUtente->begin();

        //std::cout<<o->cognome<<"  "<<  contUtente->get_size()<<std::endl;

        for(;it!= mapUtente->end();++it)
        {
            if(o->nome.size())
            {
                basic *b=dynamic_cast<basic*>((it)->second);
                profilo *pf=b->get_profilo();

                if(o->nome==pf->get_datipersonali()->get_nome())
                      VA.push_back(b);
             }
             else
                VA.push_back((it)->second);
        }

    }

    return VA;
}

//ricerca tutti gli utenti che hanno almeno una LINGUA che rispetta l'oggetto di ricerca 'o'
vector<account*> database_2::ricerca_lingue(objsearchLingua* o)
{
    vector<account*> VA;
    map<string,account*>* mapLingue= contLingue->ricercaL(o->nomeL);//mappa contenente gli utenti che parlano quella lingua
    if(mapLingue)
    {
        map<string,account*>::iterator it=mapLingue->begin();
        for(;it!= mapLingue->end();++it)
        {
            //se ci sono filtri attivi
            if(o->madre_lingua==true || o->livello_scritto>0 || o->livello_orale>0)
            {
                bool testM,testS,testO;
                testM=testS=testO=true;

                basic *b=dynamic_cast<basic*>((it)->second);
                profilo_2 *pf2=dynamic_cast<profilo_2*>(b->get_profilo());
                //vettore lingue dell'account b
                vector<lingua*>* VL=pf2->get_lingue();//contiene tutte le lingue
                vector<lingua*>::iterator il=VL->begin();
                for(;il!= VL->end();++il)
                {
                    lingua* li=(*il);

                    if(li->get_nome_lingua()==o->nomeL)
                    {
                        //controllo se è richiesto madre lingua
                        if(o->madre_lingua)//se lo è controllo
                        {
                           if(li->is_madre_lingua() == true)
                               testM=true;
                           else
                               testM=false;
                        }


                        //controllo livelloscritto
                        if(o->livello_scritto>0)
                        {
                                if(li->get_livello_scritto()>=o->livello_scritto)
                                     testS=true;
                                else
                                      testS=false;
                        }


                       //constrollo livello orale
                       if(o->livello_orale>0)
                       {
                          if(li->get_livello_orale()>=o->livello_orale)
                             testO=true;
                          else
                              testO=false;
                       }

                       if(testM & testS & testO)//basta che una condizione sia vera
                            VA.push_back(b);
                     }
                 }
             }
             else
                 VA.push_back((it)->second);
         }

    }
        return VA;
  }






//scrivi DB su file
void database_2::scriviDB()
{
    QFile file("database");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QXmlStreamWriter writer (&file);
            writer.setAutoFormatting(true);

            writer.writeStartDocument();
            writer.writeStartElement("database");

            map<string,account*>* mapA=this->get_MapAccount();
            map<string,account*>::iterator it=mapA->begin();
            for(;it!=mapA->end();++it)
            {
                account *a= (*it).second;
                //scrivi dati account
                writer.writeStartElement("account");
                database::XMLscrividatiAccount(&writer,a);

                //controllo che non sia un semplice account
                basic *b=dynamic_cast<basic*> (a);
                if(b)
                {
                    //tipo account
                    writer.writeTextElement("tipo_acount",QString::fromStdString((b->get_tipoaccount())));
                    //dati personali
                    XMLscriviDatipersonali(&writer,b);
                    //se ha un profilo_2
                    profilo_2* p2=dynamic_cast<profilo_2*>(b->get_profilo());
                    if(p2)
                    {
                        //elemento ESPERIENZE
                        XMLscriviEsperienze(&writer,p2);
                       //elemento COMPETENZE
                        XMLscriviCompetenze(&writer,p2);
                       //elemento LINGUA
                        XMLscriviLingua(&writer,p2);
                       //elemento TITOLO DI STUDIO
                        XMLscriviTitolo(&writer,p2);
                       //elemento RETE AMICI
                        XMLscriviAmici(&writer,b);

                   }
                }
                writer.writeEndElement(); //chiudo il tag Utente
            }
            writer.writeEndElement(); //chiudo tag Database
            writer.writeEndDocument(); //chiudo documento xml
   }
   file.close(); //chiudo il file
}

//legge i dati dal DB
void database_2::leggiDB()
{
    map<string, vector<string> > aux_amici;//mappa per associare gli amici ad ogni utente

    QFile file("database");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QXmlStreamReader reader(&file);
        while(!reader.atEnd() && !reader.hasError())
        {
            while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "database"))
            {
                if(reader.tokenType() == QXmlStreamReader::StartElement && reader.name() == "account")
                {
                        //leggo info account
                        account nuovoA=this->XMLleggiAccount(&reader);
                        string tipo_account;

                        //leggo il tipo_account
                        while(reader.name() != "tipo_acount")
                        {
                            reader.readNext();
                        }
                        reader.readNext();
                        tipo_account=reader.text().toString().toStdString();


                        //creo profilo_2 nello heap passando come di copia parametri vettori salvati nello stack che puntano ad oggetti allocati nello heap
                        profilo_2* pf2=new profilo_2(XMLleggiDatipersonali(&reader),XMLleggiEsperienze(&reader),XMLleggiCompetenze(&reader),XMLleggiLingue(&reader),XMLleggiTitolo(&reader));


                        //memorizzo in un vettore stringa i nomi dei suoi amici
                        vector<string> VA=XMLleggiAmici(&reader);
                        //associo il vettore amici con lo username dell'utente creato
                        aux_amici.insert(std::pair<string,vector<string> >(nuovoA.get_username(),VA));

                        //creo l'utente vero e proprio


                        if(tipo_account=="basic")
                        {
                              basic* ba=new basic(pf2,nuovoA,"basic");
                              this->inserisci(ba);//inserisco il nuovo utente nei database
                        }
                        if(tipo_account=="business")
                        {
                              business* bu=new business(pf2,nuovoA,"business");
                              this->inserisci(bu);
                        }
                        if(tipo_account=="executive")
                        {
                              executive* ex=new executive(pf2,nuovoA,"executive");
                              this->inserisci(ex);
                        }
                        //nuovoA.set_username("aa");
                }
                reader.readNext();
           }
            reader.readNext();
       }
      reader.clear();
      file.close();
   }
    //associo "fisicamente" gli amici ai rispettivi utenti
    associa_amici(aux_amici);
 }



//scrittura DATIPERSONALI su XML
void database_2::XMLscriviDatipersonali(QXmlStreamWriter* writer,basic* b)
{
    dati_personali* dp=b->get_profilo()->get_datipersonali();
    //elemento DATI_PERSONALI
    writer->writeStartElement("dati_personali");
    writer->writeTextElement("nome",QString::fromStdString((dp->get_nome())));
    writer->writeTextElement("cognome",QString::fromStdString(dp->get_cognome()));
    writer->writeTextElement("residenza",QString::fromStdString(dp->get_residenza()));
    writer->writeTextElement("domicilio",QString::fromStdString(dp->get_domicilio()));
    writer->writeTextElement("nazionalita",QString::fromStdString(dp->get_nazionalita()));
    writer->writeStartElement("data_nascita");
    writer->writeTextElement("giorno",QString::number(dp->get_datanascita().get_giorno()));
    writer->writeTextElement("mese",QString::number(dp->get_datanascita().get_mese()));
    writer->writeTextElement("anno",QString::number(dp->get_datanascita().get_anno()));
    writer->writeEndElement();
    writer->writeEndElement();//endElement DATI_PERSONALI

}

//scrittura ESPERIENZE su XML
void database_2::XMLscriviEsperienze(QXmlStreamWriter* writer,profilo_2* p2)
{
    writer->writeStartElement("ESPERIENZE");

    vector<esperienza*>* VE=p2->get_esperienze();
    vector<esperienza*>::iterator itE=VE->begin();
    for(;itE!=VE->end();++itE)
    {
        esperienza *esp=(*itE);
        writer->writeStartElement("esperienza");

        writer->writeTextElement("azienda",QString::fromStdString(esp->get_azienda()));

        writer->writeStartElement("data_inizio");
        writer->writeTextElement("giorno",QString::number(esp->get_data_inizio().get_giorno()));
        writer->writeTextElement("mese",QString::number(esp->get_data_inizio().get_mese()));
        writer->writeTextElement("anno",QString::number(esp->get_data_inizio().get_anno()));
        writer->writeEndElement();

        writer->writeStartElement("data_fine");
        writer->writeTextElement("giorno",QString::number(esp->get_data_fine().get_giorno()));
        writer->writeTextElement("mese",QString::number(esp->get_data_fine().get_mese()));
        writer->writeTextElement("anno",QString::number(esp->get_data_fine().get_anno()));
        writer->writeEndElement();

        writer->writeTextElement("ruolo",QString::fromStdString(esp->get_ruolo()));
        writer->writeTextElement("descrizione",QString::fromStdString(esp->get_descrizione()));

        writer->writeEndElement();//endelement esperienza
   }
   writer->writeEndElement();//endElement ESPERIENZE
}

//scrittura COMPETENZE su XML
void database_2::XMLscriviCompetenze(QXmlStreamWriter* writer, profilo_2* p2)
{
    writer->writeStartElement("COMPETENZE");

    vector<competenza*> *VC=p2->get_competenze();
    vector<competenza*>::iterator itC= VC->begin();
    for(;itC!=VC->end();++itC)
    {
        competenza *cmp=(*itC);
        writer->writeStartElement("competenza");

        writer->writeTextElement("nome_competenza",QString::fromStdString(cmp->get_nome_competenza()));
        writer->writeTextElement("descrizione_competenza",QString::fromStdString(cmp->get_descrizione_competenza()));
        writer->writeTextElement("livello_competenza",QString::number(cmp->get_livello_competenza()));

        writer->writeEndElement();//endelement competenza

    }
    writer->writeEndElement();//endElement COMPETENZA
}

//scrittura LINGUE su XML
void database_2::XMLscriviLingua(QXmlStreamWriter* writer, profilo_2* p2)
{
    writer->writeStartElement("LINGUE");

    vector<lingua*>* VL=p2->get_lingue();
    vector<lingua*>::iterator itL=VL->begin();
    for(;itL!=VL->end();++itL)
    {
        lingua *lin=(*itL);
        writer->writeStartElement("lingua");

        writer->writeTextElement("nome_lingua", QString::fromStdString(lin->get_nome_lingua()));
        writer->writeTextElement("madre_lingua", QString::number(lin->is_madre_lingua()));
        writer->writeTextElement("livello_scritto",QString::number(lin->get_livello_scritto()));
        writer->writeTextElement("livello_orale",QString::number(lin->get_livello_orale()));

        writer->writeEndElement();//endelement lingua
    }
    writer->writeEndElement();//endElement LINGUA
}
//scrittura TITOLO DI STUDIO su XML
void database_2::XMLscriviTitolo(QXmlStreamWriter* writer, profilo_2* p2)
{
    writer->writeStartElement("TITOLO_DI_STUDIO");

    vector<titolodistudio*> *VT=p2->get_titolodistudio();
    vector<titolodistudio*>::iterator itS=VT->begin();
    for(;itS!=VT->end();++itS)
    {
        titolodistudio *ti=(*itS);
        writer->writeStartElement("titolo");
        writer->writeTextElement("nome_titolo",QString::fromStdString(ti->get_nome_titolo()));

        writer->writeStartElement("inizio_studi");
        writer->writeTextElement("giorno",QString::number(ti->get_inizio_studi().get_giorno()));
        writer->writeTextElement("mese",QString::number(ti->get_inizio_studi().get_mese()));
        writer->writeTextElement("anno",QString::number(ti->get_inizio_studi().get_anno()));
        writer->writeEndElement();

        writer->writeStartElement("fine_studi");
        writer->writeTextElement("giorno",QString::number(ti->get_fine_studi().get_giorno()));
        writer->writeTextElement("mese",QString::number(ti->get_fine_studi().get_mese()));
        writer->writeTextElement("anno",QString::number(ti->get_fine_studi().get_anno()));
        writer->writeEndElement();

        writer->writeTextElement("voto_finale",QString::number(ti->get_votofinale()));
        writer->writeEndElement();//endelement titolo
    }
    writer->writeEndElement();//endelement TITOLO DI STUDIO
 }

//scrittura lista AMICI su XML
void database_2::XMLscriviAmici(QXmlStreamWriter* writer, basic* b)
{
    writer->writeStartElement("rete_amici");

    vector<account*> *RA=b->get_reteamici();
    vector<account*>::iterator itR=RA->begin();
    for(;itR!=RA->end();++itR)
        writer->writeTextElement("amico",QString::fromStdString((*itR)->get_username()));

    writer->writeEndElement();//endelement rete amici
}


//legge i datipersonali dal file XML
dati_personali* database_2::XMLleggiDatipersonali(QXmlStreamReader* reader)
{
    //alloco nello heap i dati personali
    dati_personali* dp=new dati_personali();

    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "dati_personali"))//finche il tokentype non è di chiousura ed il nome del token non è dati_personali
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            if(reader->name() == "nome")
            {
                 reader->readNext();
                 dp->set_nome(reader->text().toString().toStdString());
            }

            if(reader->name() == "cognome")
            {
                 reader->readNext();
                 dp->set_cognome(reader->text().toString().toStdString());
            }

            if(reader->name() == "residenza")
            {
                 reader->readNext();
                 dp->set_residenza(reader->text().toString().toStdString());
            }

            if(reader->name() == "domicilio")
            {
                 reader->readNext();
                 dp->set_domicilio(reader->text().toString().toStdString());
            }

            if(reader->name() == "nazionalita")
            {
                 reader->readNext();
                 dp->set_nazionalita(reader->text().toString().toStdString());
            }

            if(reader->name() == "data_nascita")
            {
                reader->readNext();
                data data_nascita=XMLleggiData(reader,"data_nascita");
                dp->set_datanascita(data_nascita);
            }
        }
        reader->readNext();
    }

    return dp;
}


//funzione che legge tutte le esperienze di un utente da file xml e le salva in un vettore allocato dinamicamente
vector<esperienza*> database_2::XMLleggiEsperienze(QXmlStreamReader* reader)
{
    vector<esperienza*> VE;
    esperienza* exp=0;
    string nome,descrizione,ruolo;
    data inizio,fine;

    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "ESPERIENZE"))
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "esperienza"))
            {
                if(reader->tokenType() == QXmlStreamReader::StartElement)
                {

                    if(reader->name() == "azienda")
                    {
                        reader->readNext();
                        nome=reader->text().toString().toStdString();
                    }

                    if(reader->name() == "data_inizio")
                    {
                        inizio=XMLleggiData(reader,"data_inizio");
                    }

                    if(reader->name() == "data_fine")
                    {
                        fine=XMLleggiData(reader,"data_fine");
                    }

                    if(reader->name() == "ruolo")
                    {
                        reader->readNext();
                        ruolo=reader->text().toString().toStdString();
                    }

                    if(reader->name() == "descrizione")
                    {
                        reader->readNext();
                        descrizione=reader->text().toString().toStdString();
                    }
               }
                else
                {
                if(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "ESPERIENZE")
                      return VE;
                }
               reader->readNext();
           }
           if(nome.size())
           {
               exp=new esperienza(nome,inizio,fine,ruolo,descrizione);
               VE.push_back(exp);
           }
        }
        reader->readNext();
    }

    return VE;
}


//funzione per leggere le competenze
vector<competenza*> database_2::XMLleggiCompetenze(QXmlStreamReader* reader)
{
    vector<competenza*> VC;

    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "COMPETENZE"))
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            competenza* cmp=new competenza();
            while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "competenza"))
            {
                if(reader->tokenType() == QXmlStreamReader::StartElement)
                {
                     if(reader->name() == "nome_competenza")
                      {
                        reader->readNext();
                        cmp->set_nome_competenza(reader->text().toString().toStdString());
                      }
                      if(reader->name() == "descrizione_competenza")
                      {
                         reader->readNext();
                         cmp->set_descrizione_competenza(reader->text().toString().toStdString());
                      }
                      if(reader->name() == "livello_competenza")
                      {
                         reader->readNext();
                         cmp->set_livello_competenza(reader->text().toInt());
                      }
                }
                else
                {
                if(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "COMPETENZE")
                      return VC;
                }
               reader->readNext();
           }

           VC.push_back(cmp);
        }
        reader->readNext();
    }
    return VC;
}

//funzione per leggere le LINGUE
vector<lingua*> database_2::XMLleggiLingue(QXmlStreamReader* reader)
{
    vector<lingua*> VL;

    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "LINGUE"))
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            lingua* li=new lingua();
            while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "lingua"))
            {
                if(reader->tokenType() == QXmlStreamReader::StartElement)
                {
                    if(reader->name() == "nome_lingua")
                    {
                        reader->readNext();
                        li->set_nome_lingua(reader->text().toString().toStdString());
                    }
                    if(reader->name() == "madre_lingua")
                    {
                        reader->readNext();
                        li->set_madre_lingua(reader->text().toInt());
                    }
                    if(reader->name() == "livello_scritto")
                    {
                        reader->readNext();
                        li->set_livello_scritto(reader->text().toInt());
                    }
                    if(reader->name() == "livello_orale")
                    {
                        reader->readNext();
                        li->set_livello_orale(reader->text().toInt());
                    }
                }
                else
                {
                if(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "LINGUE")
                      return VL;
                }
                reader->readNext();
            }
            VL.push_back(li);
        }
        reader->readNext();
   }
   return VL;
}

//funzione per leggere i TITOLIDISTUDIO
vector<titolodistudio*> database_2::XMLleggiTitolo(QXmlStreamReader* reader)
{
    vector<titolodistudio*> VT;

    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "TITOLO_DI_STUDIO"))
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            titolodistudio* tis=new titolodistudio();
            while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "titolo"))
            {
                if(reader->tokenType() == QXmlStreamReader::StartElement)
                {
                    if(reader->name() == "nome_titolo")
                    {
                        reader->readNext();
                        tis->set_nome_titolo(reader->text().toString().toStdString());
                    }

                    if(reader->name() == "inizio_studi")
                    {
                        data inizio_studi=XMLleggiData(reader,"inizio_studi");
                        tis->set_inzio_studi(inizio_studi);
                    }

                    if(reader->name() == "fine_studi")
                    {
                        data fine_studi=XMLleggiData(reader,"fine_studi");
                        tis->set_fine_studi(fine_studi);
                    }

                    if(reader->name() == "voto_finale")
                    {
                        reader->readNext();
                        tis->set_votofinale(reader->text().toInt());
                    }
               }
                else
                {
                if(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "TITOLO_DI_STUDIO")
                      return VT;
                }
               reader->readNext();
            }
            VT.push_back(tis);
        }
        reader->readNext();
    }
   return VT;
}



//leggi gli amici di un utente e li inserisce in un vettore
vector<string> database_2::XMLleggiAmici(QXmlStreamReader* reader)
{
    vector<string> VA;
    while(!(reader->tokenType() == QXmlStreamReader::EndElement && reader->name() == "rete_amici"))
    {
        if(reader->tokenType() == QXmlStreamReader::StartElement)
        {
            if(reader->name() == "amico")
            {
                reader->readNext();
                VA.push_back(reader->text().toString().toStdString());
            }
        }
        reader->readNext();
    }
    return VA;
}


//associo ad ogni username(string) i suoi amici (vector)
void database_2::associa_amici(map<string, vector<string> > aux)
{
    map<string,account*>* mapA=this->get_MapAccount();
    map<string,account*>::iterator it=mapA->begin();

    for(;it!= mapA->end();++it)//per ogni utente presente nel DBaccount
    {
        basic *b=dynamic_cast<basic*>( (it)->second );//estrai il primo utente
        if(b)
        {
            vector<string> VS=aux.find(b->get_username())->second; //estreai il vettore amici in base allo username di b
            vector<string>::iterator at=VS.begin();
            for(;at!=VS.end();++at)//per tutti gli amici presenti nel vettore
            {
                 objsearch obj((*at));
                 b->add_friend(  (this->ricercaDB( &(obj)).singleresult    ));
            }
        }
    }
}

void database_2::elimina_indice(objsearch *obj)
{
    if(typeid(*obj)==typeid(objsearchLingua))
    {
        objsearchLingua *o=dynamic_cast<objsearchLingua*>(obj);
        if(o)
            contLingue->cancella(o->nomeL);
    }

    if(typeid(*obj)==typeid(objsearchCompetenze))
    {
        objsearchCompetenze *o=dynamic_cast<objsearchCompetenze*> (obj);
        if(o)
            contCompetenze->cancella(o->nome_competenza);
    }
    if(typeid(*obj)==typeid(objsearchTitolo))
    {
            objsearchTitolo *o=dynamic_cast<objsearchTitolo*> (obj);
            if(o)
                contTitoli->cancella(o->nome_titolo);
    }
    if(typeid(*obj)==typeid(objsearchUtente))
    {
        objsearchUtente *o=dynamic_cast<objsearchUtente*> (obj);
        if(o)
            contUtente->cancella(o->cognome);
    }
    if(typeid(*obj)==typeid(objsearch))
        return this->database::rimuovi(obj);
}

void database_2::elimina_account_contenitore(objsearch* obj, account *a)
{
    if(typeid(*obj)==typeid(objsearchLingua))
    {
        objsearchLingua *o=dynamic_cast<objsearchLingua*>(obj);
        if(o)
            contLingue->rimuovi_utente(o->nomeL,a);
    }

    if(typeid(*obj)==typeid(objsearchCompetenze))
    {
        objsearchCompetenze *o=dynamic_cast<objsearchCompetenze*> (obj);
        if(o)
            contCompetenze->rimuovi_utente(o->nome_competenza,a);
    }
    if(typeid(*obj)==typeid(objsearchTitolo))
    {
            objsearchTitolo *o=dynamic_cast<objsearchTitolo*> (obj);
            if(o)
                contTitoli->rimuovi_utente(o->nome_titolo,a);
    }
    if(typeid(*obj)==typeid(objsearchUtente))
    {
        objsearchUtente *o=dynamic_cast<objsearchUtente*> (obj);
        if(o)
            contUtente->rimuovi_utente(o->cognome,a);
    }
}

void database_2::aggiungi_account_contenitore(objsearch* obj, account *a)
{
    if(typeid(*obj)==typeid(objsearchLingua))
    {
        objsearchLingua *o=dynamic_cast<objsearchLingua*>(obj);
        if(o)
            contLingue->inserisci(o->nomeL,a);
    }

    if(typeid(*obj)==typeid(objsearchCompetenze))
    {
        objsearchCompetenze *o=dynamic_cast<objsearchCompetenze*> (obj);
        if(o)
            contCompetenze->inserisci(o->nome_competenza,a);
    }
    if(typeid(*obj)==typeid(objsearchTitolo))
    {
            objsearchTitolo *o=dynamic_cast<objsearchTitolo*> (obj);
            if(o)
                contTitoli->inserisci(o->nome_titolo,a);
    }
    if(typeid(*obj)==typeid(objsearchUtente))
    {
        objsearchUtente *o=dynamic_cast<objsearchUtente*> (obj);
        if(o)
            contUtente->inserisci(o->cognome,a);
    }
}

int database_2::get_sizeAccount()const
{
    return database::get_size();
}

int database_2::get_sizeTitoli()const
{
    return contTitoli->get_size();
}

int database_2::get_sizeLingue()const
{
    return contLingue->get_size();
}

int database_2::get_sizeUtenti()const
{
    return contUtente->get_size();
}

int database_2::get_sizeCompetenze()const
{
    return contCompetenze->get_size();
}

