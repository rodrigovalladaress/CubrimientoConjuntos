#pragma once
#include<stdlib.h>
#include<time.h>
#include "CubrimientoConjuntosGreedy.cpp"
class CubrimientoConjuntosGRASP :
	public CubrimientoConjuntos
{
private:
	int tamLCR;
public:
	CubrimientoConjuntosGRASP(const char*, int);
	~CubrimientoConjuntosGRASP(void);
	vector<int> calcularCubrimiento(void) const;
private:
	int getCandidato(ConjuntoNumeros&, const vector<bool>&) const;
	void postProcesamiento(vector<int>&) const;
	bool sePuedeQuitar(const vector<int>&, int) const;
public:
	int getTamLCR(void) const;
	void setTamLCR(int);
};

