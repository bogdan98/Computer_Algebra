#include "pch.h"
#include "polyterm.h"


polyterm::polyterm(double c, double p) :Term(c, p, "", "x") {
	
}
polyterm* polyterm::deriv() {
	polyterm *t1 = new polyterm(0, 0);
	double c = this->getCoeff();
	double p = this->getPower();
	if (this->getCoeff() == 0) {
		*t1 = polyterm(0, 0);
	}
	else {
		*t1 = polyterm(c*p, p - 1.000);
	}	
	return t1;
}