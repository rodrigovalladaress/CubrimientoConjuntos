#include "PruebasGRASP.cpp"
#include <iostream>
int main() {
	int aux;
	PruebasGRASP pruebasGRASP;
	pruebasGRASP.cargarFicheroBase("inBase.txt");
	pruebasGRASP.realizarPruebas();
	std::cin >> aux;
	return 0;
}