#pragma once
#include "Term.h"
#include "SumTerms.h"
#include "polyterm.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <list>
#include <math.h>
#include <stdio.h>

class ProdTerms :
	public Term
{
private:
	std::list<Term*> terms;
	std::list<Term*> :: iterator it;
	std::list<Term*> :: iterator its;
	double coeff;
	std::string fullName;
public:
	ProdTerms();
	std::list<Term*> getList();
	void addCoeff(double delta);
	void multCoeff(double t);
	double getCoeff();
	virtual void add(Term *t);
	virtual void red_coeff();
	void setFullName();
	virtual std::string getFullName();
	virtual void display();
	ProdTerms* nthder(int n);
	Term* deriv();
	void clean();
	virtual void setVar(std::string nv);
	virtual std::list<Term*> getTerms();
};

