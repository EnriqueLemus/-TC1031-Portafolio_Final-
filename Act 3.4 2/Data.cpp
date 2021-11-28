#include "Data.h"
#include  <string>
#include  <iostream>
using namespace std;

Data::Data(){
  mes="Mes";
  dia="0";
  hora="0";
  min="0";
  seg="0";
  num1="0";
  num2="0";
  num3="0";
  num4="0";
  num5="0";
  razon="Razon";
  Ip i(stoi(num1), stoi(num2), stoi(num3), stoi(num4));
  ip=i;
}

Data::Data(string m, string d, string h, string mi, string s, string n1, string n2, string n3, string n4,string n5, string r, Ip i){
  this->mes=m;
  this->dia=d;
  this->hora=h;
  this->min=mi;
  this->seg=s;
  this->num1=n1;
  this->num2=n2;
  this->num3=n3;
  this->num4=n4;
  this->num5=n5;
  this->razon=r;
  this->ip=i;
}

void Data::setMes(string mes){
  this->mes = mes;
}

void Data::setNum1(string num1){
  this->num1 = num1;
}

void Data::setNum2(string num2){
  this->num2 = num2;
}

void Data::setNum3(string num3){
  this->num3 = num3;
}

void Data::setNum4(string num4){
  this->num4 = num4;
}

void Data::setNum5(string num5){
  this->num5 = num5;
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

void Data::setIp(Ip i) {
  this->ip = i;
}

string Data::getMes(){
  return this->mes;
}

string Data::getNum1(){
  return this->num1;
}

string Data::getNum2(){
  return this->num2;
}

string Data::getNum3(){
  return this->num3;
}

string Data::getNum4(){
  return this->num4;
}

string Data::getNum5(){
  return this->num5;
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

Ip Data::getIp() {
  return this->ip;
}

string Data::getAll() {
  string timeR = this->mes + " " + this->dia + " " +
  this->hora + ":" + this->min + ":" + this->seg + " " + this->num1+"."+this->num2+"."+this->num3+"."+this->num4+":"+this->num5 + " " + this->razon;
  return timeR;
}