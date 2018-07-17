#ifndef DATA_H
#define DATA_H

#include<QDate>

class data
{
private:
       int giorno,mese,anno;
public:
    data(int =-1,int =-1,int =-1);
    data(const data&);
    data(const QDate&);
    virtual ~data();

    int get_giorno()const;
    int get_mese()const;
    int get_anno()const;

    void set_giorno(int);
    void set_mese(int);
    void set_anno(int);

    bool operator!=(const data&)const;
    bool operator==(const data&)const;
};

#endif // DATA_H
