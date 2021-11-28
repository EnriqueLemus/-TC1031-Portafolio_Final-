#ifndef _DATA_H
#define _DATA_H
#include <iostream>
#include "dateTime.h"
using namespace std;

class Data{
  private:
    string mes,ip,razon;
    string dia,hora,min,seg;
    dateTime fechaHora;

  public:
    Data();
    Data(string m, string d, string h, string mi, string s, string ip, string r, dateTime t);

    void setMes(string mes);
    void setDia(string dia);
    void setHora(string hora);
    void setMin(string min);
    void setSeg(string seg);
    void setIp(string ip);
    void setRazon(string razon);
    void setFecha(dateTime t);

    string getMes();
    string getDia();
    string getHora(); 
    string getMin();   
    string getSeg();
    string getIp();
    string getRazon();
    dateTime getFecha();
    string getAll();
};


#endif