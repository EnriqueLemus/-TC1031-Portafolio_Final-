//Luis Enrique Lemus Martinez A01639698
//Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Funciones.h"
#include "Registro.h"
using namespace std;


int main(){
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
    
    ordenaQuickrucursivo(bitacora); //Ordena todo el documento

    ofstream escritor("bitacora_ordenada.txt"); //crea el archivo con todos los registros ordenados
    if (escritor.is_open()) {
        for (int i = 0 ; i < bitacora.size() ; i++) {
            escritor << registroString(bitacora[i]) << "\n";
        }
        escritor.close();
		cout << "\nSe creo la bitacora ordenada en \"bitacora_ordenada.txt\"." << endl;
	}

    cout << "\nBusqueda de registros"<<endl; //Se le pide al usuario que ingrese las fechas iniciales para empezar con la busqueda
    cout<<"Favor de ingresar la fecha inicial así: (7 de Junio = 07 06)"<<endl;
    string mesInicial, diaInicial;
    cout << "Dia: ";
    cin >> diaInicial;
    cout << "Mes: ";
    cin >> mesInicial;
    int fechaInicial = stoi(mesInicial + diaInicial + "000000");

    cout<<"Favor de ingresar la fecha final"<<endl;
    string mesFin, diaFin;
    cout << "Dia: ";
    cin >> diaFin;
    cout << "Mes: ";
    cin >> mesFin;
    int fechaFin = stoi(mesFin + diaFin + "235959");

    int posInicial = busquedaBinaria(bitacora, fechaInicial); //Busqueda de la fecha inicial ingresada
    int posFin = busquedaBinaria(bitacora, fechaFin); //Busqueda de la fecha final del dia ingresado

    cout << "Los registros de la fecha inicial a la fecha final son: ";
    cout << endl;
    for (int i = posInicial ; i < posFin ; i++) {
        cout << registroString(bitacora[i]) <<endl;
    }
    
    
}