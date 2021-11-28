#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
using namespace std;
#include "Ip.h"

class Data{
  private:
    string mes, num1, num2, num3, num4,num5,razon;
    string dia,hora,min,seg;
    Ip ip;
  public:
    Data();
    Data(string m, string d, string h, string mi, string s, string n1, string n2, string n3, string n4,string n5, string r, Ip i);

    void setMes(string mes);
    void setDia(string dia);
    void setHora(string hora);
    void setMin(string min);
    void setSeg(string seg);
    void setNum1(string num1);
    void setNum2(string num2);
    void setNum3(string num3);
    void setNum4(string num4);
    void setNum5(string num5);
    void setRazon(string razon);
    void setIp(Ip i);

    string getMes();
    string getDia();
    string getHora(); 
    string getMin();   
    string getSeg();
    string getNum1();
    string getNum2();
    string getNum3();
    string getNum4();
    string getNum5();
    string getRazon();
    Ip getIp();
    string getAll();
};

#endif