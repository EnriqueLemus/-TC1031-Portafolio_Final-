#ifndef _REGISTRO_H_
#define _REGISTRO_H_


#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;


template <class T>
class Registro{
  private:
  Node<T>* head;
  Node<T>* tail;
  int numElements;
  public:
  void swap(T value, int i, int j);
  string diaCorrect(T value);
  string numMes(T value);
  string quitaPuntos(T value);
  int fechaBuena(T value);  
  string registroString(T value);
  vector<T>regis(T value);
};


string diaCorrect(vector<string> registro){
    if(registro[1].size() >  1){
        return registro[1];
    }else{
        return "0" + registro[1];
    }
}

string numMes(vector<string> registro){
    if(registro[0] == "Jan"){
        return "01";
    }else if (registro[0] == "Feb"){
        return "02";
    }else if (registro[0] == "Mar"){
        return "03";
    }else if (registro[0] == "Apr"){
        return "04";
    }else if (registro[0] == "May"){
        return "05";
    }else if (registro[0] == "Jun"){
        return "06";
    }else if (registro[0] == "Jul"){
        return "07";
    }else if (registro[0] == "Aug"){
        return "08";
    }else if (registro[0] == "Sep"){
        return "09";
    }else if (registro[0] == "Oct"){
        return "10";
    }else if (registro[0] == "Nov"){
        return "11";
    }else{
        return "12";
    }
}

string quitaPuntos(vector<string> registro){
    return registro[2].substr(0, 2) + registro[2].substr(3, 2) + registro[2].substr(6, 2);
}

int fechaBuena(vector<string> registro){
    string mes, dia, hora;
    mes = numMes(registro);
    dia = diaCorrect(registro);
    hora = quitaPuntos(registro);

    string conc = mes + dia + hora;
    int fecha = stoi(conc);

    return fecha;
}

/*
vector<string>regis(bitacora){
    vector<vector<string> > bitacora;
    vector<string> registro;
    ifstream lector("bitacora.txt");
    string linea, mes, hora, direccionIP, razon, dia;
    int size = 0;
    while (getline(lector, linea))  //Va agregando las fechas ya con el formato correcto
    {
        registro.clear();

        stringstream ss(linea);
        getline(ss, mes, ' ');
        registro.push_back(mes);
        getline(ss, dia, ' ');
        registro.push_back(dia);
        getline(ss, hora, ' ');
        registro.push_back(hora);
        getline(ss, direccionIP, ' ');
        registro.push_back(direccionIP);
        getline(ss, razon, '\n');
        registro.push_back(razon);
        bitacora[size];
        bitacora.push_back(registro);
        size++;
    }

    lector.close(); 
    return bitacora; 

}; */

#endif // _REGISTRO__H__