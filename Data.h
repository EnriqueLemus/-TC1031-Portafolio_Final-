#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
#include <string>
#include "dateTime.h"

class Data {

  public:
    Data();
    Data(dateTime fecha, std::string dirIP, std::string reason);
    std::string mes;
    std::string dia;
    std::string hora;
    std::string min;
    std::string seg;
    std::string direccionIP;
    std::string razon;
    dateTime fecha;
    std::string getMes();
    std::string getDia();
    std::string getHora();
    std::string getMin();
    std::string getSeg();
    std::string getDireccionIP();
    std::string getRazon();
    dateTime getFecha();
};

Data::Data(){
  dateTime f = fecha;
  direccionIP = " ";
  razon = " ";
}

Data::Data(dateTime fecha, std::string dirIP, std::string reason) {
  direccionIP = dirIP;
  razon = reason;
  fecha = fecha;
}

std::string Data::getMes() {
  return mes;
}

std::string Data::getDia() {
  return dia;
}

std::string Data::getHora() {
  return hora;
}

std::string Data::getMin() {
  return min;
}

std::string Data::getSeg() {
  return seg;
}

std::string Data::getDireccionIP() {
  return direccionIP;
}

std::string Data::getRazon() {
  return razon;
}

dateTime Data::getFecha() {
  return fecha;
}

#endif // _DATA_H_