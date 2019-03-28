#pragma once
#include "Term.h"
#include "ProdTerms.h"

class hyp :
	public Term
{
public:
	hyp(double c, double p, std::string id);
	ProdTerms* deriv();
};

