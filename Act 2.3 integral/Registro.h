#ifndef _REGISTRO_H
#define _REGISTRO_H

#include <vector>
#include "Data.h"
#include "dateTime.h"
#include "DoubleLinkedList.h"
#include "Node.h"

#include <iostream>
using namespace std;

class Registro {
  private:
    DoubleLinkedList<Data> lista;

  public:
    Registro();
    void archivo();
    int getNumRecords();
    void registroArchivo();
    void imprimirRegistro();
    void sort();
    int busquedaBinaria(dateTime k);
    void archivoBusqueda(int inicio, int fin);
};

#endif // _REGISTRO2_H


