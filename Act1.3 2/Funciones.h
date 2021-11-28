#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Registro.h"
using namespace std;

template <class T>
class Funciones{
  private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;


  public:
  Funciones();
  void swap(T value, int i, int j);
  int part(T value, int first, int last);
  void ordenaQuickrucursivo(T value, int first, int last);
  Node<T>* partition(Node<T> *l, Node<T> *h);
  void ordenaQuickiterativo(vector<T>);
  int busquedaBinaria(T value,int fecha);

};

void swap(vector<vector<string> > &x, int i, int j){
    vector<string> pass;
    pass = x[i];
    x[i] = x[j];
    x[j] = pass;
}


int part(vector<vector <string> > &bitacora, int first, int last){
    int pivot = fechaBuena(bitacora[first]);
    int x = first + 1;

    for(int y = x; y <= last; y++){
        int fechaTemp = fechaBuena(bitacora[y]);
        if(fechaTemp < pivot){
            swap(bitacora, x++, y);
        }
    }
    swap(bitacora, first, x-1);
    return x-1;
}

void ordenaQuickrucursivo(vector<vector<string> > &bitacora, int first, int last){
    if (first < last){
        int pos = part(bitacora, first, last);
        ordenaQuickrucursivo(bitacora, first, pos-1);
        ordenaQuickrucursivo(bitacora, pos+1, last);
    }
}

void ordenaQuickrucursivo(vector<vector<string> > &bitacora){
    ordenaQuickrucursivo(bitacora, 0, bitacora.size() -1);
}



string registroString(vector<string> registro){
    string completo;
    for (int i =0; i < registro.size() - 1 ; i++){
        completo  += registro[i] + " ";
    }
    completo = completo + registro[4];
    return completo;
}

int busquedaBinaria(vector<vector<string> > bitacora, int fecha){
    int inicio = 0;
    int fin = bitacora.size() - 1;

    while(inicio <= fin){
        int mitad = inicio + (fin - inicio) / 2;

        if(fecha == fechaBuena(bitacora[mitad])) {
			return mitad;
		} else if(fecha < fechaBuena(bitacora[mitad])){
            fin = mitad-1;
        }else{
            inicio = mitad + 1;
        }
    }
    return inicio;
}
#endif // _FUNCIONES_H_
