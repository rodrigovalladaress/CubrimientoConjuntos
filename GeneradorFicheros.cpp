#include "GeneradorFicheros.h"


GeneradorFicheros::GeneradorFicheros(void) {
	srand((unsigned)time(NULL));
}

GeneradorFicheros::~GeneradorFicheros(void) {}

void GeneradorFicheros::generarFichero(int maxNumero, int numConjuntos, const char* nombreFichero) {
	vector<vector<bool>> matrizBinaria;
	ofstream ficheroSalida(nombreFichero);
	if(ficheroSalida.fail())
		cout << "Error al escribir " << nombreFichero << endl;
	else {
		ficheroSalida << maxNumero << " " << numConjuntos << endl;
		matrizBinaria = generarMatrizBinaria(maxNumero, numConjuntos);
		for(int i = 0; i < maxNumero; i++) {
			for(int j = 0; j < numConjuntos; j++) {
				ficheroSalida << matrizBinaria[i][j] << " ";
			}
			ficheroSalida << endl;
		}
	}
	ficheroSalida.close();
}

vector<vector<bool>> GeneradorFicheros::generarMatrizBinaria(int maxNumero, int numConjuntos) {
	int numFilas = maxNumero;
	int numCols = numConjuntos;
	int probMaxima = maxNumero;
	int probActual = probMaxima;
	int decrecProb = (numConjuntos * numConjuntos) / (maxNumero * maxNumero);
	int col;
	int valorProbabil;
	vector<vector<bool>> matrizBinaria;
	vector<bool> filaCero;
	/* Empezar con una matriz inicialmente vacía. Ir fila por fila, elijiendo una columna aleato-
	   riamente. Poner ese elemento del conjunto a 1 con una probabilidad del 100%. Elegir otra 
	   columna al azar. Colocar un 1 con una probabilidad del 100% - DEC. Así sucesivamente hasta
	   haber elegido numCols columnas al azar.
	*/
	for(int i = 0; i < numCols; i++) {
		filaCero.push_back(false);
	}
	for(int i = 0; i < numFilas; i++) {
		matrizBinaria.push_back(filaCero);
	}
	for(int i = 0; i < numFilas; i++) {
		probActual = probMaxima;
		for(int j = 0; j < numCols; j++) {
			col = rand() % numCols;
			valorProbabil = rand() % probMaxima;
			if(valorProbabil <= probActual) {
				matrizBinaria[i][col] = true;
			}
			probActual -= decrecProb;
		}
	}
	return matrizBinaria;
}