#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "GeneradorFicheros.h"

using namespace std;

const int numFicheros = 10;

const string nombreInfFicheros = "inBase.txt";
const string nombreBase = "in";
const string extension = ".txt";

// m = elementos del problema
// n = subconjuntos del problema

const int m[] = {10, 30, 50, 50,  300, 300, 500, 300, 500, 800};
const int n[] = {10, 30, 30, 100, 100, 300, 300, 800, 800, 800};

string convertInt(int number)
{
	stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}
/*
int main() {
	string nombreFichero;
	GeneradorFicheros generador;
	ofstream ficheroInformacion(nombreInfFicheros);
	if(ficheroInformacion.fail())
		cout << "Error al escribir el fichero " << nombreInfFicheros << endl;
	else {
		ficheroInformacion << numFicheros << endl;
		for(int i = 0; i < numFicheros; i++) {
			nombreFichero = nombreBase;
			nombreFichero.append(convertInt(i + 1));
			nombreFichero.append(extension);
			ficheroInformacion << nombreFichero << endl;
			cout << "Generando fichero " << nombreFichero << endl;
			generador.generarFichero(m[i], n[i], nombreFichero.data());
		}
	}
}*/