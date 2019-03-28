#pragma once
#include <iostream>
#include <list>

class Term
{
private:
	double coeff;
	double power;
	std::string name;
	std::string var;
	std::string fullName;
public:
	Term();
	Term(double c, double p, std::string nn, std::string vv);
	std::string getName();
	virtual double getCoeff();
	double getPower();
	std::string getVar();
	virtual void display();
	virtual void setFullName();
	void mult(double p);
	virtual void red_coeff();
	//bool isEqual(Term *t);
	virtual std::string getFullName();
	virtual void setVar(std::string s1);
	virtual Term* deriv();
};

