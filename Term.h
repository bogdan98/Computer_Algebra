#pragma once
#include <iostream>
#include <list>

//class that defines a term, which can be any expression
//all the terms (for example trigonometric) extend class term
//if one wants to add their function (for example ln or exp), it can easily be added 
//without worrying about the rest of the code
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
	virtual double getCoeff(); //returns coefficient
	double getPower(); //returns power
	std::string getVar(); //returns expression inside the function
	virtual void display(); //display the expression
	virtual void setFullName(); //set full name using the internal information
	virtual void red_coeff(); //set coefficient equal to 1
	virtual std::string getFullName(); //returns full name of the function
	virtual void setVar(std::string s1); //set the expression inside the function to s1
	virtual Term* deriv(); //returns derivative of the function
};

