#pragma once
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::ostream;
class ConjuntoNumeros
{
	vector<bool> conjunto;
	int ultimoElemento;
public:
	ConjuntoNumeros(void);
	ConjuntoNumeros(int);
	ConjuntoNumeros(vector<bool>&);
	~ConjuntoNumeros(void);
	// Devuelve el número de elementos no elegidos por este conjunto
	int numElementosNoElegidos(const ConjuntoNumeros&) const;
	bool esConjuntoCompleto(void) const;

	void imprimirConjunto(void) const;
	friend ostream& operator<<(ostream&, const ConjuntoNumeros&);

	int getUltimoElemento(void) const;
	void setUltimoElemento(int);
	void inicializarUltimoElemento(void);
	int getNumeroElementos(void) const;
	const vector<bool>& getConjunto(void) const;
	void setConjunto(const vector<bool> &);
    bool getElemento(int) const;
	void setElemento(int, bool);
	void addElemento(bool);
};

