//Luis Enrique Lemus Martinez A01639698
//Actividad Integral 3.4 BST

#include <iostream>
#include "Registro.h"
#include <iostream>
using namespace std;

int main(){
  Registro regis;
  MaxHeap<int> numRepsIp(17000);
  regis.archivo();
  regis.heapSort();
  regis.registroArchivo();
  numRepsIp = regis.contador();
} 