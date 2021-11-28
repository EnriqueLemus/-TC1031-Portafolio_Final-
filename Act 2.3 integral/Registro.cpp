#include <fstream>
#include "Registro.h"
#include <iostream>
using namespace std;


Registro::Registro() {}

void Registro::archivo() {
  string mes, dia, hora, minuto, segundo, ip, razon;
  ifstream in("bitacora.txt");
  while(getline(in, mes, ' ')){
    getline(in, dia, ' ');
    getline(in,hora,':');
    getline(in,minuto,':');
    getline(in,segundo,' ');
    getline(in,ip,' ');
    getline(in,razon);
    dateTime timedt (mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo));
    Data timeLine (mes, dia, hora, minuto, segundo,ip, razon, timedt);
    lista.addLast(timeLine);
  }
  in.close();
}

int Registro::getNumRecords() {
  return lista.getNumElements();
}

void Registro::registroArchivo(){
  ofstream archivo;
  archivo.open("bitacora_ordenada.txt", ios::out);//creamos el archivo
  for (int i=0 ; i < lista.getNumElements() ; i++){
    archivo<<lista.getData(i).getAll()<<endl;
  }
  archivo.close();
  cout<<"La bitacora ordenada ha sido creada en bitacora_ordenada.txt"<<endl;
}

void Registro::imprimirRegistro() {
  lista.printList();
}


void Registro::sort(){
  lista.quickSort();
}


//Complejidad O(log n)
  int Registro::busquedaBinaria(dateTime k) {
    int low = 0;
    int high = lista.getNumElements() - 1;
    while (low <= high) {
      int m = low + (high - low) / 2;
      if (k.getDate() == lista.getData(m).getFecha().getDate()) return m;
      else if (k.getDate() < lista.getData(m).getFecha().getDate())
        high = m - 1;
      else
        low = m + 1;
  }
  return -1;
  }





void Registro::archivoBusqueda(int inicio, int fin){
ofstream archivo;
archivo.open("resultado_busqueda.txt", ios::out);//creamos el archivo
for (int i = inicio ; i < fin ; i++){
  archivo<<lista.getData(i).getAll()<<endl;
  cout<<lista.getData(i).getAll()<<endl;
}
archivo.close();
}