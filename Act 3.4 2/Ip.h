#ifndef _IP_H_
#define _IP_H_

#include <iostream>
using namespace std;

class Ip {
  public:
    int numero1,numero2,numero3,numero4;
    Ip();
    Ip(int n1, int n2, int n3, int n4);
    string getIP1();
    int getIP2();
};


#endif