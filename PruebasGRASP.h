#pragma once
#include <fstream>
#include <vector>
//#include <intrin.h>
#include "tiempo.cc"
#include "CubrimientoConjuntosGRASP.cpp"
#include "tiempo.cc"
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

const int NUM_EJECUCIONES_DISTINTO_LCR = 5;
const int NUM_EJECUCIONES_MISMO_LCR = 30;
const int DIV_LCR = 3;
const unsigned INF = 999999;


const string NOMBRE_FICHERO_SALIDA = "out.txt";
const string CABECERA_TABLA = "Problema;n;m;|LCR|;Ejec.;|J|;J;Tiempo";
const string LETRA_PROBLEMA = "Q";
const string SEPARADOR = ";";
const string CPU = "Intel(R) Core(TM) i7-2640M CPU @ 2.80GHz 2.80 GHz";

class PruebasGRASP
{
private:
	vector<string> nombresFicheros;
	long long tiempo;
	long long sumaTiempos;
public:
	PruebasGRASP(void);
	~PruebasGRASP(void);
	void realizarPruebas(void);
	void cargarFicheroBase(const char*);
private:
	unsigned getNumFicheros(void) const;
	const char* getNombreFichero(int) const;
	void addNombreFichero(const string&);
	
	void recalcularSumaTiempos(long long);
	void clearSumaTiempos(void);
	long long getSumaTiempos(void);
	double getMediaTiempo(void);
};

