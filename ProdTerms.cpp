#include "pch.h"
#include "ProdTerms.h"
#include <string>

ProdTerms::ProdTerms() {
	coeff = 1;
}

std::list<Term*> ProdTerms::getList() {
	return terms;
}

void ProdTerms::addCoeff(double delta) {
	coeff += delta;
}

double ProdTerms::getCoeff() {
	return coeff;
}

void ProdTerms::setFullName() {
	fullName = "";
    if (coeff == 1.0000) {
		for (it = terms.begin(); it != terms.end(); it++) {
			if (!((*it)->getFullName()).empty() && ((std::to_string(1.000)).compare((*it)->getFullName())) != 0) {
				fullName = fullName + (*it)->getFullName() + "*";
			}
		}
		if (!fullName.empty()) {
			fullName.pop_back();
		}
	}
	else if (coeff != 0) {
		fullName = std::to_string(coeff);
		for (it = terms.begin(); it != terms.end(); it++) {
			if (!((*it)->getFullName()).empty() && ((std::to_string(1.000)).compare((*it)->getFullName())) != 0) {
				fullName = fullName + "*" + (*it)->getFullName();
			}
		}
	}
}

void ProdTerms::clean() {
	for (it = terms.begin(); it != terms.end(); it++) {
		coeff *= ((*it)->getCoeff());
		(*it)->red_coeff();
	}
}

void ProdTerms::add(Term *t1) {
	if ((std::to_string(1.000)).compare(t1->getFullName()) != 0) {
		terms.push_back(t1);
	}
	clean();
}


void ProdTerms::display() {
	std::cout << getFullName();
}

std::string ProdTerms::getFullName() {
	setFullName();
	return fullName;
}

void ProdTerms::multCoeff(double t) {
	coeff *= t;
}

ProdTerms* ProdTerms::nthder(int n) {
	ProdTerms* li = new ProdTerms();
	li->addCoeff(coeff - 1);
	int i = 0;
	for ((this->it) = terms.begin(); (this->it) != terms.end(); (this->it)++) {
		if (i == n) {
			li->add((*(this->it))->deriv());
		}
		else {
			li->add(*(this->it));
		}
		i++;
	}
	return li;
}

Term* ProdTerms::deriv() {
	polyterm *func = new polyterm(1, 1);
	SumTerms *res = new SumTerms(func);
	int i = 0;
	for (its = (terms).begin(); its != (terms).end(); its++) {
		res->add(this->nthder(i));
		i++;
	}
	return res;
}

void ProdTerms::red_coeff() {
	this->coeff = 1;
}

void ProdTerms::setVar(std::string nv) {
	for (it = terms.begin(); it != terms.end(); it++) {
		(*it)->setVar(nv);
	}
}

std::list<Term*> ProdTerms::getTerms() {
	return terms;
}