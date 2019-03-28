#include "pch.h"
#include "Term.h"
#include <iostream>
#include <string>

Term::Term() {

}

Term::Term(double c, double p, std::string nn, std::string vv) {
	coeff = c;
	power = p;
	name = nn;
	var = vv;
	setFullName();
}

void Term::setFullName() {
	fullName = "";
	double c = this->getCoeff();
	double p = this->getPower();
	if (c == 1.0000) {
		if (getPower() == 1) {
			fullName = fullName + getName() + "(" + getVar() + ")";
		}
		else if (getPower() != 0){
			fullName = fullName + getName() + "(" + getVar() + ")^" + std::to_string(p);
		}
		else {
			fullName = fullName + std::to_string(c);
		}
	}
	else if (c != 0) {
		if (getPower() == 1) {
			fullName = fullName + std::to_string(c) + "*" + getName() + "(" + getVar() + ")";
		}
		else if (getPower() != 0){
			fullName = fullName + std::to_string(c) + "*" + getName() + "(" + getVar() + ")^" + std::to_string(p);
		}
		else {
			fullName = fullName + std::to_string(c);
		}
	}
}

std::string Term::getName() {
	return name;
}

std::string Term::getVar() {
	return var;
}

double Term::getCoeff() {
	return coeff;
}

double Term::getPower() {
	return power;
}

void Term::display() {
	std::cout << getFullName();
}


void Term::mult(double p) {
	power += p;
	setFullName();
}

void Term::red_coeff() {
	this->coeff = 1;
}

std::string Term::getFullName() {
	setFullName();
	return fullName;
}

void Term::setVar(std::string s1) {
	var = s1;
	setFullName();
}

Term* Term::deriv() {
	Term *res = new Term();
	return res;
}
