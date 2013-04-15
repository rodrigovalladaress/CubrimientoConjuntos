#include "LCR.h"


LCR::LCR(/*int tamLCR*/) {
	//setTamLCR(tamLCR);
	//srand(time(NULL));
}

LCR::~LCR(void) {
	listaCand.clear();
}

int LCR::

int LCR::getTamLCR(void) const {
	return tamLCR;
}

void LCR::setTamLCR(int tamLCR_) {
	tamLCR = tamLCR_;
}