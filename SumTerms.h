#pragma once
#include "ProdTerms.h"
#include <iostream>

class SumTerms:
	public Term
{
private:
	std::list<Term*> terms;
	std::list<Term*> ::iterator it;
	//std::list<SumTerms*> sterms;
	//std::list<SumTerms*> ::iterator its;
	Term *func;
	std::string fullName;
	std::string varName;
public:
	SumTerms(Term *h);
	virtual void add(Term *pp);
	virtual void display();
	virtual void red_coeff();
	virtual double getCoeff();
	virtual double getPower();
	void setFullName();
	//bool isEqual(ProdTerms *pt);
	void addCoeff(double delta);
	virtual std::string getFullName();
	std::list<Term*> getTerms();
    Term* deriv();
	virtual void setVar(std::string st);
	virtual std::string getVar();
};

