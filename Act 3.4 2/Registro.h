#ifndef _REGISTRO_H
#define _REGISTRO_H

#include <vector>
#include "Data.h"
#include "Ip.h"
#include "maxHeap.h"

#include <iostream>
using namespace std;

class Registro {
  private:
    vector<Data> bitacora;

  public:
  
    Registro();
    void archivo();
    int getNumRecords();
    void registroArchivo();
    void imprimirRegistro();
    void heapify(vector<Data> &vec, int n, int i);
    void heapSort();
    MaxHeap<int> contador();
  
};

#endif // _REGISTRO_H