//Luis Enrique Lemus Martinez A01639698
//Actividad Integral 2.3 de Conceptos Básicos y Algoritmos Fundamentales


#include <string>
#include <iostream>
//#include "Node.h"
//#include "Stack.h"
#include "DoubleLinkedList.h"
#include "Registro.h"
using namespace std;


int main() {

Registro regis;
regis.archivo();
regis.sort();
regis.registroArchivo();
  
  

string mes,mes2,dia,dia2,hora,hora2,min,min2,seg,seg2;
//Se pide la primera fecha
cout<<"Buscar fecha"<<endl;
cout<<"Mes (Escribir solo las primeras 3 letras y la primera mayuscula, Ejemplo: Aug): "<<endl;
cin>>mes;
cout<<"Dia (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>dia;
cout<<"Hora (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>hora;
cout<<"Minutos (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>min;
cout<<"Segundos (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>seg;
dateTime fecha1(mes,stoi(dia), stoi(hora), stoi(min), stoi(seg));
int busqueda1;
busqueda1=regis.busquedaBinaria(fecha1);

//Se pide la segunda fecha
cout<<"Segunda fecha a buscar"<<endl;
cout<<"Mes (Escribir solo las primeras 3 letras y la primera mayuscula, Ejemplo: Aug): "<<endl;
cin>>mes2;
cout<<"Dia (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>dia2;
cout<<"Hora (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>hora2;
cout<<"Minutos (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>min2;
cout<<"Segundos (Con dos digitos, Ejemplo: 06 ó 21): "<<endl;
cin>>seg2;
dateTime fecha2(mes2,stoi(dia2), stoi(hora2), stoi(min2), stoi(seg2));
int busqueda2;
busqueda2=regis.busquedaBinaria(fecha2);

regis.archivoBusqueda(busqueda1, busqueda2);
cout<<"Se ha creado el archivo con la busqueda en resultado_busqueda.txt"<<endl;  
}