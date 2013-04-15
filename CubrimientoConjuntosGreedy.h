#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "ConjuntoNumeros.cpp"
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

const int NO_HAY_MEJOR_CONJ = -1;

class CubrimientoConjuntos {
private:
  int numConjuntos;
  int maxNumero;
  vector<ConjuntoNumeros> conjuntos;
public:
  CubrimientoConjuntos(const char*);
  ~CubrimientoConjuntos(void);
  vector<int> calcularCubrimiento(void) const;
private:
  // Leer de fichero
  void leerFichero(const char*);
  void crearConjuntos(void);
public:
  void imprimirMatriz(void) const;
  void imprimirConjuntos(void) const;
  int getNumConjuntos(void) const;
  void setNumConjuntos(int);
  int getMaxNumero(void) const;
  void setMaxNumero(int);
  const vector<ConjuntoNumeros>& getConjuntos(void) const;
  const ConjuntoNumeros& getConjunto(int) const;
  void addConjunto(const ConjuntoNumeros&);
  void setElementoConjunto(int, int, bool);
};
