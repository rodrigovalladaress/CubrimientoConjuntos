#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
using std::ofstream;
using std::cout;
using std::endl;
using std::vector;

const int PROB_MAXIMA = 100;
// Decrecimiento de la probabilidad de colocar un 1 en la matriz binaria
const int DEC = 20;

class GeneradorFicheros
{
public:
	GeneradorFicheros(void);
	~GeneradorFicheros(void);
	void generarFichero(int, int, const char*);
private:
	vector<vector<bool> > generarMatrizBinaria(int, int);
};