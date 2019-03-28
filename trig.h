#pragma once
#include <list>
#include "Term.h"
#include "ProdTerms.h"

class trig :
	public Term
{
public:
	trig(double cc, double pp, std::string nn);
	ProdTerms* deriv();
};

