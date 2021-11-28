#include "Data.h"
#include <string>
#include <iostream>
using namespace std;

Data::Data(){
  mes="Mes";
  dia="0";
  hora="0";
  min="0";
  seg="0";
  ip="0";
  razon="Razon";
  dateTime t(mes,stoi(dia), stoi(hora),stoi(min),stoi(seg));
  fechaHora=t;
}

Data::Data(string m, string d, string h, string mi, string s, string ip, string r, dateTime t){
  this->mes=m;
  this->dia=d;
  this->hora=h;
  this->min=mi;
  this->seg=s;
  this->ip=ip;
  this->razon=r;
  this->fechaHora=t;
}

void Data::setMes(string mes){
  this->mes = mes;
}

void Data::setIp(string ip){
  this->ip = ip;
}

void Data::setRazon(string razon){
  this->razon = razon;
}

void Data::setDia(string dia){
  this->dia= dia;
}

void Data::setHora(string hora){
  this->hora = hora;
}

void Data::setSeg(string seg){
  this->seg = seg;
}

void Data::setMin(string min){
  this->min = min;
}

void Data::setFecha(dateTime t) {
  this->fechaHora = t;
}

string Data::getMes(){
  return this->mes;
}

string Data::getIp(){
  return this->ip;
}

string Data::getRazon(){
  return this->razon;
}

string Data::getDia(){
  return this->dia;
}

string Data::getHora(){
  return this->hora;
}

string Data::getMin(){
  return this->min;
}

string Data::getSeg(){
  return this->seg;
}

dateTime Data::getFecha() {
  return this->fechaHora;
}

string Data::getAll() {
  string timeR = this->mes + " " + this->dia + " " +
  this->hora + ":" + this->min + ":" + this->seg + " " + this->ip + " " + this->razon;
  return timeR;
}