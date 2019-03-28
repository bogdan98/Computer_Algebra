#pragma once
#include "Term.h"
#include <list>
class polyterm :
	public Term
{
public:
	polyterm(double c, double p);
	polyterm* deriv();
};

