#include "pch.h"
#include "hyp.h"


hyp::hyp(double cc, double pp, std::string id) : Term(cc, pp, id, "x") {

}

ProdTerms* hyp::deriv() {
	ProdTerms *res = new ProdTerms();
	std::string id = this->getName();
	double p = this->getPower();
	double c = this->getCoeff();
	int x;
	int y;
	x = id.compare("cosh");
	y = id.compare("sinh");
	if (x == 0) {
		hyp *t1 = new hyp(c * p, p - 1, "cosh");
		hyp *t2 = new hyp(1, 1, "sinh");
		if (p != 1) {
			res->add(t1);
		}
		res->add(t2);
	}
	else if (y == 0) {
		hyp *t1 = new hyp(c*p, p - 1, "sinh");
		hyp *t2 = new hyp(1, 1, "cosh");
		if (p != 1) {
			res->add(t1);
		}
		res->add(t2);
	}
	return res;
}

