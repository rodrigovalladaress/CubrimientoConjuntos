#include "CubrimientoConjuntosGreedy.h"

CubrimientoConjuntos::CubrimientoConjuntos(const char* nombreEntrada) {
	leerFichero(nombreEntrada);
}

CubrimientoConjuntos::~CubrimientoConjuntos(void) {
	conjuntos.clear();
}

vector<int> CubrimientoConjuntos::calcularCubrimiento(void) const {
	int mejorConj = 0;
	int maxElemNoElegidos;
	vector<int> conjuntosEnLaSolucion;
	vector<bool> conjuntosUtilizados;
	ConjuntoNumeros conjuntoSolucion(getMaxNumero()); // Inicialmente vacío
	for(int j = 0; j < getNumConjuntos(); j++) {
		conjuntosUtilizados.push_back(false);
	}
	while((mejorConj != NO_HAY_MEJOR_CONJ) && (!conjuntoSolucion.esConjuntoCompleto())) {
		maxElemNoElegidos = 0;
		mejorConj = NO_HAY_MEJOR_CONJ;
		for(int i = 0; i < getNumConjuntos(); i++) {
			// Si el conjunto actual no está en la solución y el número de elementos a añadir es mayor que el mejor conjunto
			// actualmente
			if((!conjuntosUtilizados[i]) && (getConjunto(i).numElementosNoElegidos(conjuntoSolucion) > maxElemNoElegidos)) {
				maxElemNoElegidos = getConjunto(i).numElementosNoElegidos(conjuntoSolucion);
				mejorConj = i;
			}
		}
		// Añadir elementos a la solución
		if(mejorConj != NO_HAY_MEJOR_CONJ) {
			conjuntosEnLaSolucion.push_back(mejorConj);
			conjuntosUtilizados[mejorConj] = true;
			for(int i = 0; i < getMaxNumero(); i++) {
				if((!conjuntoSolucion.getElemento(i)) && (getConjunto(mejorConj).getElemento(i))) {
					conjuntoSolucion.setElemento(i, true);
				}
			}
		}
	}
	return conjuntosEnLaSolucion;
}

void CubrimientoConjuntos::leerFichero(const char* nombreEntrada) {
	
	int i = 0; // Conjunto número i
	int j = 0; // Elemento j del conjunto i
	int decimaParteLectura;
	int iteradorGlobal = 0; // Indica cuando imprimir un punto para saber cuánto ha cargado el fichero
	int auxiliar;
	bool auxiliarBool;
	ifstream ficheroEntrada;
	ficheroEntrada.open(nombreEntrada);
	if(ficheroEntrada.fail())
		cout << "Error al leer " << nombreEntrada << endl;
	else {
		cout << "Leyendo fichero " << nombreEntrada;
		ficheroEntrada >> auxiliar;
		setMaxNumero(auxiliar);
		ficheroEntrada >> auxiliar;
		setNumConjuntos(auxiliar);
		crearConjuntos();
		decimaParteLectura = (getMaxNumero() * getNumConjuntos()) / 10;
		while((j < getMaxNumero()) && (!ficheroEntrada.eof())) {
			ficheroEntrada >> auxiliarBool;
			if(auxiliarBool) {
				setElementoConjunto(i, j, true);
			}
			i++;
			if(i == getNumConjuntos()) {
				i = 0;
				j++;
			}
			iteradorGlobal++;
			if(iteradorGlobal == decimaParteLectura) {
				cout << ".";
				iteradorGlobal = 0;
			}
		}
	}
	cout << endl;
	ficheroEntrada.close();
}

void CubrimientoConjuntos::crearConjuntos(void) {
	vector<bool> conjuntoVacio;
	ConjuntoNumeros conjuntoNumeros;
	for(int i = 0; i < getMaxNumero(); i++) {
		conjuntoVacio.push_back(false);
	}
	conjuntoNumeros.setConjunto(conjuntoVacio);
	for(int i = 0; i < getNumConjuntos(); i++) {
		addConjunto(conjuntoNumeros);
	}
}

void CubrimientoConjuntos::imprimirMatriz(void) const {
	for(int j = 0; j < getMaxNumero(); j++) {
		for(int i = 0; i < getNumConjuntos(); i++) {
			cout << getConjunto(i).getElemento(j) << " ";
		}
		cout << endl;
	}
}

void CubrimientoConjuntos::imprimirConjuntos(void) const {
	for(int i = 0; i < getNumConjuntos(); i++) {
		cout << "P" << i + 1 << " = {";
		getConjunto(i).imprimirConjunto();
		cout << "}" << endl;
	}
}

int CubrimientoConjuntos::getNumConjuntos(void) const {
	return numConjuntos;
}

void CubrimientoConjuntos::setNumConjuntos(int numConjuntos_) {
	numConjuntos = numConjuntos_;
}

int CubrimientoConjuntos::getMaxNumero(void) const {
	return maxNumero;
}

void CubrimientoConjuntos::setMaxNumero(int maxNumero_) {
	maxNumero = maxNumero_;
}

const vector<ConjuntoNumeros>& CubrimientoConjuntos::getConjuntos(void) const {
	return conjuntos;
}

const ConjuntoNumeros& CubrimientoConjuntos::getConjunto(int i) const {
	return getConjuntos()[i];
}

void CubrimientoConjuntos::addConjunto(const ConjuntoNumeros& conjunto_) {
	conjuntos.push_back(conjunto_);
}

void CubrimientoConjuntos::setElementoConjunto(int i, int j, bool v) {
	conjuntos[i].setElemento(j, v);
}