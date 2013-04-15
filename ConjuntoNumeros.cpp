#include "ConjuntoNumeros.h"

ConjuntoNumeros::ConjuntoNumeros(void)
{
	inicializarUltimoElemento();
}

ConjuntoNumeros::ConjuntoNumeros(int maxElementos) {
	for(int i = 0; i < maxElementos; i++) {
		addElemento(false);
	}
	inicializarUltimoElemento();
}

ConjuntoNumeros::ConjuntoNumeros(vector<bool>& conjunto) {
	setConjunto(conjunto);
	inicializarUltimoElemento();
}

int ConjuntoNumeros::numElementosNoElegidos(const ConjuntoNumeros& conjuntoSolucion) const {
	int numNoElegidos = 0;
	for(int i = 0; i < getNumeroElementos(); i++) {
		if((getElemento(i) == true) && (conjuntoSolucion.getElemento(i) == false)) {
			numNoElegidos++;
		}
	}
	return numNoElegidos;
}

ConjuntoNumeros::~ConjuntoNumeros(void)
{
	conjunto.clear();
}

bool ConjuntoNumeros::esConjuntoCompleto(void) const {
	for(int i = 0; i < getNumeroElementos(); i++) {
		if(!getElemento(i)) {
			return false;
		}
	}
	return true;
}

void ConjuntoNumeros::imprimirConjunto(void) const {
	if(getUltimoElemento() != -1) {
		for(int i = 0; i <= getUltimoElemento(); i++) {
			if(getElemento(i) == true) {
				cout << i + 1;
				if(i != getUltimoElemento())
					cout << ", ";
			}
		}
	}
}

ostream& operator<<(ostream &out, const ConjuntoNumeros& conj) {
	out << "{";
	if(conj.getUltimoElemento() != -1) {
		for(int i = 0; i <= conj.getUltimoElemento(); i++) {
			if(conj.getElemento(i) == true) {
				out << i + 1;
				if(i != conj.getUltimoElemento())
					out << ", ";
			}
		}
	}
	out << "}";
	return out;
}

int ConjuntoNumeros::getUltimoElemento(void) const {
	return ultimoElemento;
}

void ConjuntoNumeros::setUltimoElemento(int ultimoElemento_) {
	ultimoElemento = ultimoElemento_;
}

void ConjuntoNumeros::inicializarUltimoElemento(void) {
	setUltimoElemento(-1);
	for(int i = 0; i < getNumeroElementos(); i++) {
		if(getElemento(i) == true) {
			setUltimoElemento(i);
		}
	}
}

int ConjuntoNumeros::getNumeroElementos(void) const {
	return conjunto.size();
}

const vector<bool>& ConjuntoNumeros::getConjunto(void) const {
	return conjunto;
}

void ConjuntoNumeros::setConjunto(const vector<bool>& conjunto_) {
	conjunto = conjunto_;
	inicializarUltimoElemento();
}
bool ConjuntoNumeros::getElemento(int i) const {
	return getConjunto()[i];
}

void ConjuntoNumeros::setElemento(int i, bool v) {
	conjunto[i] = v;
	inicializarUltimoElemento();
}

void ConjuntoNumeros::addElemento(bool v) {
	conjunto.push_back(v);
	inicializarUltimoElemento();
}

