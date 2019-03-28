#include "pch.h"
#include "trig.h"
#include <string>
#include <stdio.h>


trig::trig(double cc, double pp, std::string id) : Term(cc, pp, id, "x") {
	
}

ProdTerms* trig::deriv() {
	ProdTerms *res = new ProdTerms();
	std::string id = this->getName();
	double p = this->getPower();
	double c = this->getCoeff();
	int x;
	int y;
	x = id.compare("cos");
	y = id.compare("sin");
	if (x == 0){
		trig *t1 = new trig(-c*p, p - 1, "cos");
		trig *t2 = new trig(1, 1, "sin");
		if (p != 1) {
			res->add(t1);
		}
		res->add(t2);
	}
	else if (y == 0) {
		trig *t1 = new trig(c*p, p-1, "sin");
		trig *t2 = new trig(1, 1, "cos");
		if (p != 1) {
			res->add(t1);
		}
		res->add(t2);
	}
	return res;
}
