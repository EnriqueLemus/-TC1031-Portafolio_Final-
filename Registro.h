#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Data.h"
#include "DoubleLinkedList.h"
using namespace std;

class Registro{
  private:
    DoubleLinkedList<Data> registros;
    
  public:
    void archivo();
    void archivoOrdenado();
};



void Registro::archivo() {   // Va agregando las fechas ya con el formato correcto
    string min, hora, mes, dia, seg, dirIP, reason;
    int dia_, hora_, min_, seg_;
    
    ifstream lector("bitacora.txt");
    
    while (!lector.eof()){
    getline(lector, mes, ' ');
    getline(lector, dia, ' ');
    getline(lector, hora, ':');
    getline(lector, min, ':');
    getline(lector, seg, ' ');
    getline(lector, dirIP, ' ');
    getline(lector, reason);
    dia_ = stoi(dia);
    hora_ = stoi(hora);
    min_ = stoi(min);
    seg_ = stoi(seg);
    dateTime date(mes, dia_, hora_, min_, seg_);
    Data datos(date, dirIP, reason);
    registros.addLast(datos);
    //cout << "Mes: " << mes << endl;
    //cout << "Dia: " << dia_ << endl;
    }
    cout << "Registro: " << registros.getData(9).getMes() << endl;
    lector.close();
    
      
    
}

void Registro::archivoOrdenado() {
  ofstream escritor("bitacora_ordenada.txt"); // crea el archivo con todos los registros ordenados
    if (escritor.is_open()) {
        for (int i = 0 ; i < registros.getNumElements() ; i++) {
            escritor << registros.getData(i).getMes() << " " << registros.getData(i).getDia() << " " << registros.getData(i).getHora() << ":" << registros.getData(i).getMin() << ":" << registros.getData(i).getSeg() << " " << 
            registros.getData(i).getDireccionIP() << " " << registros.getData(i).getRazon() << endl; 
        }
        escritor.close();
		cout << "\nSe creo la bitacora ordenada en \"bitacora_ordenada.txt\"." << endl;
	}
}

#endif // _REGISTRO__H__