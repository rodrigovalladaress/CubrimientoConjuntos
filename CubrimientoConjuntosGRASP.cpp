#include "CubrimientoConjuntosGRASP.h"


CubrimientoConjuntosGRASP::CubrimientoConjuntosGRASP(const char* nombreEntrada, int tamLCR) : CubrimientoConjuntos(nombreEntrada)
{
	setTamLCR(tamLCR);
	srand((unsigned)time(NULL));
}


CubrimientoConjuntosGRASP::~CubrimientoConjuntosGRASP(void) {}

vector<int> CubrimientoConjuntosGRASP::calcularCubrimiento(void) const {
	int conjCandidato = 0;
	vector<int> conjuntosEnLaSolucion;
	vector<bool> conjuntosUtilizados;
	ConjuntoNumeros conjuntoSolucion(getMaxNumero()); // Inicialmente vacío
	for(int j = 0; j < getNumConjuntos(); j++) {
		conjuntosUtilizados.push_back(false);
	}
	while((conjCandidato != NO_HAY_MEJOR_CONJ) && (!conjuntoSolucion.esConjuntoCompleto())) {
		conjCandidato = getCandidato(conjuntoSolucion, conjuntosUtilizados);
		if(conjCandidato != NO_HAY_MEJOR_CONJ) {
			conjuntosEnLaSolucion.push_back(conjCandidato);
			conjuntosUtilizados[conjCandidato] = true;
			// Combinar conjuntos
			for(int i = 0; i < getMaxNumero(); i++) {
				if((!conjuntoSolucion.getElemento(i)) && (getConjunto(conjCandidato).getElemento(i))) {
					conjuntoSolucion.setElemento(i, true);
				}
			}
		}
	}
	//postProcesamiento(conjuntosEnLaSolucion);
	return conjuntosEnLaSolucion;
}

int CubrimientoConjuntosGRASP::getCandidato(ConjuntoNumeros& conjuntoSolucion, const vector<bool>& conjuntosUtilizados) const {
	vector<int> candidatosOrdenados;
	vector<int> lcr;
	int j;
	int index;
	for(int i = 0; i < getNumConjuntos(); i++) {
		candidatosOrdenados.push_back(i);
	}
	// Ordenar conjuntos
	for(int i = 1; i < getNumConjuntos(); i++) {
		index = candidatosOrdenados[i];
		j = i - 1;
		while ((j >= 0) && (getConjunto(candidatosOrdenados[j]).numElementosNoElegidos(conjuntoSolucion) > 
			getConjunto(candidatosOrdenados[index]).numElementosNoElegidos(conjuntoSolucion))) {
				candidatosOrdenados[j + 1] = candidatosOrdenados[j];
				j--;
		}
		candidatosOrdenados[j + 1] = index;
	}
	j = getNumConjuntos() - 1;
	while((j >= 0) && (lcr.size() != (unsigned)getTamLCR())) {
		if((!conjuntosUtilizados[candidatosOrdenados[j]]) && (getConjunto(candidatosOrdenados[j]).numElementosNoElegidos(conjuntoSolucion) > 0)) {
			lcr.push_back(candidatosOrdenados[j]);
		}
		j--;
	}
	if(lcr.size() > 0)
		return lcr[rand() % lcr.size()];
	else
		return NO_HAY_MEJOR_CONJ;
}

void CubrimientoConjuntosGRASP::postProcesamiento(vector<int>& conjuntosEnLaSolucion) const {
	//int candidatoAQuitar; usar para no comprobar todas las soluciones
	for(unsigned i = 0; i < conjuntosEnLaSolucion.size(); i++) { // ¿No comprobarlas todas?
		if(sePuedeQuitar(conjuntosEnLaSolucion, i)) {
			conjuntosEnLaSolucion.erase(conjuntosEnLaSolucion.begin() + i);
		}
	}
}

bool CubrimientoConjuntosGRASP::sePuedeQuitar(const vector<int>& conjuntosEnLaSolucion, int posConjunto) const {
	int e = 0; // Iterador por elementos
	unsigned c = 0; // Iterador por conjuntos
	bool estaEnOtroConjunto;
	while(e <= getConjunto(posConjunto).getUltimoElemento()) {
		estaEnOtroConjunto = false;
		c = 0;
		while((!estaEnOtroConjunto) && (c < conjuntosEnLaSolucion.size())) {
			if(conjuntosEnLaSolucion[c] != posConjunto) {
				estaEnOtroConjunto = getConjunto(conjuntosEnLaSolucion[c]).getElemento(e);
			}
			c++;
		}
		if((!estaEnOtroConjunto)) {
			return false;
		}
		e++;
	}
	return true;
}

int CubrimientoConjuntosGRASP::getTamLCR(void) const {
	return tamLCR;
}

void CubrimientoConjuntosGRASP::setTamLCR(int tamLCR_) {
	tamLCR = tamLCR_;
}