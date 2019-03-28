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

//class used to represent product of t1*t2*..
//where t1, t2,... can be any terms

class ProdTerms :
	public Term
{
private:
	std::list<Term*> terms; //list of terms in the product
	std::list<Term*> :: iterator it;
	std::list<Term*> :: iterator its;
	double coeff; //coefficient in front of product
	std::string fullName; //full name of the product term
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
	ProdTerms* nthder(int n); //intermediate function used for taking the derivative
	Term* deriv();
	void clean();
	virtual void setVar(std::string nv);
	virtual std::list<Term*> getTerms();
};

