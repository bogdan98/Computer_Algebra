#pragma once
#include "Term.h"
#include <list>

//simplest function - x to some power multiplied by a coefficient
class polyterm :
	public Term
{
public:
	polyterm(double c, double p);
	polyterm* deriv();
};

