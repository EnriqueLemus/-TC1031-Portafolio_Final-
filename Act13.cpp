//Luis Enrique Lemus Martinez A01639698
//Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<vector<string> > &x, int i, int j){
    vector<string> pass;
    pass = x[i];
    x[i] = x[j];
    x[j] = pass;
}

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

void ordenaQuick(vector<vector<string> > &bitacora, int first, int last){
    if (first < last){
        int pos = part(bitacora, first, last);
        ordenaQuick(bitacora, first, pos-1);
        ordenaQuick(bitacora, pos+1, last);
    }
}

void ordenaQuick(vector<vector<string> > &bitacora){
    ordenaQuick(bitacora, 0, bitacora.size() -1);
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

    ordenaQuick(bitacora); //Ordena todo el documento

    ofstream escritor("bitacora_ordenada.txt"); //crea el archivo con todos los registros ordenados
    if (escritor.is_open()) {
        for (int i = 0 ; i < bitacora.size() ; i++) {
            escritor << registroString(bitacora[i]) << "\n";
        }
        escritor.close();
		cout << "\nSe creo la bitacora ordenada en \"bitacora_ordenada.txt\"." << endl;
	}

    cout << "\nBusqueda de registros"<<endl; //Se le pide al usuario que ingrese las fechas iniciales para empezar con la busqueda
    cout<<"Favor de ingresar la fecha inicial así: (3 de Febrero = 03 02)"<<endl;
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
