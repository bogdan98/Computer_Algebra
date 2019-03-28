#include "pch.h"
#include "SumTerms.h"
#include <typeinfo>

SumTerms::SumTerms(Term *h) : Term::Term(){
	func = h;
}

double SumTerms::getCoeff() {
	return func->getCoeff();
}

double SumTerms::getPower() {
	return func->getPower();
}

std::list<Term*> SumTerms::getTerms() {
	return terms;
}

void SumTerms::add(Term *pt) {
	terms.push_back(pt);
}


void SumTerms::setFullName() {
	varName = "";
	int len = terms.size();
	it = terms.begin();
	for (it; it != terms.end(); it++) {
		if (!(((*it)->getFullName())).empty()) {
			varName = varName + ((*it)->getFullName()) + "+";
		}		
	}

	if (!varName.empty()) {
		varName.pop_back();
	}


	func->setVar(varName);
	fullName = func->getFullName();
}


void SumTerms::display() {
	std::cout << getFullName();
}

void SumTerms::addCoeff(double d) {

}

std::string SumTerms::getFullName() {
	this->setFullName();
	return fullName;
}

void SumTerms::red_coeff() {
	func->red_coeff();
}

void SumTerms::setVar(std::string nv) {
	for (it = terms.begin(); it != terms.end(); it++) {
		(*it)->setVar(nv);
	}
}

std::string SumTerms::getVar() {
	return (this->varName);
}

Term* SumTerms::deriv() {
	this->setFullName();
	polyterm* fn = new polyterm(1, 1);
	SumTerms *a = new SumTerms(fn);
	Term *b = (this->func)->deriv();
	b->setVar(this->getVar());
	std::list<Term*> trms = this->getTerms();
	std::list<Term*> ::iterator nt;
	for (nt = terms.begin(); nt != terms.end(); nt++) {
		a->add((*nt)->deriv());
	}
	ProdTerms *res = new ProdTerms();
	res->add(a);
	res->add(b);
	return res;
}