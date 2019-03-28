#pragma once
#include <iostream>
#include <list>

//class that defines a term, which can be any expression
class Term
{
private:
	double coeff; //coefficient
	double power; //power
	std::string name; //name of the function (sin, cos, etc. Used only with simple functions)
	std::string var;  //expresion inside the function
	std::string fullName; //full name of the function, which is displayed
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
	virtual void red_coeff(); //set coefficient equal to 1
	virtual std::string getFullName();
	virtual void setVar(std::string s1); //set the expression inside the function to s1
	virtual Term* deriv();
};

