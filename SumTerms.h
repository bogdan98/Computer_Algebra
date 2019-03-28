#pragma once
#include "ProdTerms.h"
#include <iostream>

//class that defines an expression which has the form
//f(t1 + t2 + ..), where t1, t2, etc. are any terms
//i.e. can be simple functions or products or of the form
//f(t1 + t2 + ..)
class SumTerms:
	public Term
{
private:
	std::list<Term*> terms;
	std::list<Term*> ::iterator it;
	Term *func; //defines f from f(t1 + t2 + ...)
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
	void addCoeff(double delta);
	virtual std::string getFullName();
	std::list<Term*> getTerms();
    Term* deriv();
	virtual void setVar(std::string st);
	virtual std::string getVar();
};

