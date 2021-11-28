#include <fstream>
#include "Registro.h"
#include <iostream>
using namespace std;

Registro::Registro() {
  bitacora.clear();
}

void Registro::archivo() {
  string mes, dia, hora, minuto, segundo, n1,n2,n3,n4,n5, razon;
  ifstream in("bitacoraHeap.txt");
  if (!in.is_open()){
      cout << "El archivo no se pudo abrir" << endl;
    }
  while(getline(in, mes, ' ')){
    getline(in, dia, ' ');
    getline(in,hora,':');
    getline(in,minuto,':');
    getline(in,segundo,' ');
    getline(in,n1,'.');
    getline(in,n2,'.');
    getline(in,n3,'.');
    getline(in,n4,':');
    getline(in,n5,' ');
    getline(in,razon);
    Ip timedt (stoi(n1), stoi(n2), stoi(n3), stoi(n4));
    Data timeLine (mes, dia, hora, minuto, segundo,n1,n2,n3,n4,n5, razon, timedt);
    bitacora.push_back(timeLine);
  }
  in.close();
}

int Registro::getNumRecords() {
  return bitacora.size();
}

void Registro::registroArchivo(){
  ofstream archivo;
  archivo.open("bitacora_ordenada.txt", ios::out);//Creamos el archivo.
  if(archivo.fail()){  //Excepción en dado que el archivo falle
    cout<<"Fallo al crear el archivo"<<endl;
    exit(1);
  }
  for(int i=0;i<bitacora.size();i++){
    archivo<<bitacora[i].getAll()<<endl;
  }
  archivo.close();
}

void Registro::imprimirRegistro() {
  for (int i=0; i < bitacora.size(); i++) {
    cout << bitacora[i].getAll() << std::endl;
  }
}

//-GeeksforGeeks HeapSort.
void Registro::heapify(vector<Data> &vec, int n, int i)
{
  int largest = i; // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1    
  int r = 2 * i + 2; // right = 2*i + 2
 // If left child is larger than root
  if (l < n && vec[l].getIp().getIP2() > vec[largest].getIp().getIP2())
    largest = l;
  // If right child is larger than largest so far
  if (r < n && vec[r].getIp().getIP2() > vec[largest].getIp().getIP2())
    largest = r;
 
  // If largest is not root
  if (largest != i) {
    swap(vec[i], vec[largest]);
 // Recursively heapify the affected sub-tree
    heapify(vec, n, largest);
  }
}

//-GeeksforGeeks HeapSort. 
// main function to do heap sort
void Registro::heapSort()
{
  // Build heap (rearrange array)
  int n= bitacora.size();
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(bitacora, n, i);
 
  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    swap(bitacora[0], bitacora[i]);
 
    //call max heapify on the reduced heap
    heapify(bitacora, i, 0);
    }
}



MaxHeap<int> Registro::contador(){
  MaxHeap<int> contador(17000);
  vector<Ip> reg(17000);
  vector<int> reg2(17000);
  int cont=1;
  for(int i=0; i<=bitacora.size()-1 ; i++){
    if(bitacora[i].getIp().getIP1()==bitacora[i+1].getIp().getIP1()){
      cont=cont+1;
      i++;
    }
    else{
      reg.push_back(bitacora[i].getIp());
      reg2.push_back(cont);
      contador.push(cont);
      cont=1;
      i++;
    }
  }
  Ip temp;
  int l=0;
  for(int j=0; j<=contador.getSize(); j++){
    int k=0;
    for (k=0; k<=reg2.size(); k++){
      if(reg2[k]==contador.getData(j)){
        Ip temp;
        reg[l]=temp;
        reg[l]=reg[k];
        reg[k]=temp;
        l++;
        j++;
        k++;
      }
      else{k++;}
    }
  }

  for(int i=0;i<5;i++){
    cout<<reg[i].getIP1()<<" ";
    cout<<"Accesos totales: "<<contador.getData(i)<<endl;
  }

  ofstream archivo;
  archivo.open("ips_con_mayor_acceso.txt", ios::out); // Creamos el archivo
  if(archivo.fail()){ //Excepción en dado que el archivo falle
    cout<<"Fallo al crear el archivo"<<endl;
    exit(1);
  }
  for(int i=0;i<5;i++){
    archivo<<reg[i].getIP1()<<" ";
    archivo<<"Accesos totales: "<<contador.getData(i)<<endl;
    
  }
  archivo.close();

  return contador;
}
