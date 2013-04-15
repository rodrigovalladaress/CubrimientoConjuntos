#include "PruebasGRASP.h"

PruebasGRASP::PruebasGRASP(void) {

}

PruebasGRASP::~PruebasGRASP(void) {
	nombresFicheros.clear();
}

void PruebasGRASP::realizarPruebas(void) {
	int tamLCR;
	int iteradorGlobal;
	int decimaParteCalculo = NUM_EJECUCIONES_MISMO_LCR / 10;
	unsigned cardinalMejorSol;
	vector<int> mejorSol;
	CubrimientoConjuntosGRASP* aux;
	ofstream ficheroSalida(NOMBRE_FICHERO_SALIDA.data());
	if(ficheroSalida.fail())
		cout << "Error al escribir en " << NOMBRE_FICHERO_SALIDA << endl;
	else {
		ficheroSalida << CABECERA_TABLA << endl;
		for(unsigned i = 0; i < getNumFicheros(); i++) {
			aux = new CubrimientoConjuntosGRASP(getNombreFichero(i), 0);
			for(int j = 0; j < NUM_EJECUCIONES_DISTINTO_LCR; j++) {
				tamLCR = aux->getNumConjuntos() / DIV_LCR + j;
				aux->setTamLCR(tamLCR);
				ficheroSalida << LETRA_PROBLEMA << i + 1 << SEPARADOR << aux->getMaxNumero();
				ficheroSalida << SEPARADOR << aux->getNumConjuntos() << SEPARADOR;
				ficheroSalida << aux->getTamLCR() << SEPARADOR << j + 1 << SEPARADOR;
				cout << "Calculando solución con |LCR| = " << tamLCR;
				iteradorGlobal = 0;
				cardinalMejorSol = INF;
				clearSumaTiempos();
				for(int k = 0; k < NUM_EJECUCIONES_MISMO_LCR; k++) {
					cronomilisec(1);
					vector<int> solucion = aux->calcularCubrimiento();
					recalcularSumaTiempos(cronomilisec(0));
					if(solucion.size() < cardinalMejorSol) {
						cardinalMejorSol = solucion.size();
						mejorSol = solucion;
					}
					iteradorGlobal++;
					if(iteradorGlobal == decimaParteCalculo) {
						cout << ".";
						iteradorGlobal = 0;
					}
				}
				cout << endl;
				ficheroSalida << cardinalMejorSol << SEPARADOR;
				ficheroSalida << "{";
				for(unsigned k = 0; k < mejorSol.size(); k++) {
					ficheroSalida << mejorSol[k];
					if(k != mejorSol.size() - 1) {
						ficheroSalida << ", ";
					}
				}
				ficheroSalida << "}" << SEPARADOR << getMediaTiempo() << SEPARADOR;
			}
			ficheroSalida << endl;
			delete aux;
		}
	}
}

void PruebasGRASP::cargarFicheroBase(const char* nombreFicheroBase) {
	ifstream ficheroBase(nombreFicheroBase);
	string nombreFicheroConjunto;
	int numFicheros;
	int i = 0;
	if(ficheroBase.fail())
		cout << "Error al leer " << nombreFicheroBase << endl;
	else {
		cout << "Cargando fichero " << nombreFicheroBase << endl;
		ficheroBase >> numFicheros;
		cout << "Número de ficheros: " << numFicheros << endl;
		while((!ficheroBase.eof()) && (i < numFicheros)) {
			ficheroBase >> nombreFicheroConjunto;
			addNombreFichero(nombreFicheroConjunto);
			cout << getNombreFichero(i) << endl;
			i++;
		}
	}
}

unsigned PruebasGRASP::getNumFicheros(void) const {
	return nombresFicheros.size();
}

const char* PruebasGRASP::getNombreFichero(int i) const {
	return (const char*)nombresFicheros[i].c_str();
}

void PruebasGRASP::addNombreFichero(const string& nombreFichero) {
	nombresFicheros.push_back(nombreFichero);
}

/////////////////////// Tiempos

void PruebasGRASP::recalcularSumaTiempos(long long tiempo) {
  sumaTiempos += tiempo; 
}

void PruebasGRASP::clearSumaTiempos(void) {
  sumaTiempos = 0;
}

long long PruebasGRASP::getSumaTiempos(void) {
  return sumaTiempos;
}

double PruebasGRASP::getMediaTiempo(void) {
  return (double)getSumaTiempos() / (double)NUM_EJECUCIONES_MISMO_LCR;
}