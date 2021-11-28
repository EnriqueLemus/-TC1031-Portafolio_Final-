#include "Ip.h"
#include <iostream>
using namespace std;

Ip::Ip(){} 

Ip::Ip(int n1, int n2, int n3, int n4){
  numero1=n1;
  numero2=n2;
  numero3=n3;
  numero4=n4;
}

string Ip::getIP1(){
  string n1=to_string(numero1);
  string p1=".";
  string n2=to_string(numero2);
  string p2=".";
  string n3=to_string(numero3);
  string p3=".";
  string n4=to_string(numero4);
  string fin= n1+=p1+=n2+=p2+=n3+=p3+=n4;
  return(fin);
}

int Ip::getIP2(){
  return ((this->numero1*(256^3))+(this->numero2*(256^2))+(this->numero3*(256^1))+(this->numero4*(256^0)));
}