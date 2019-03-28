#pragma once
#include "Term.h"
#include "ProdTerms.h"

//class used to define operations for hyperbolic functions 
class hyp :
	public Term
{
public:
	hyp(double c, double p, std::string id);
	ProdTerms* deriv();
};

