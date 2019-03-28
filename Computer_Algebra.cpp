// Computer_Algebra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "polyterm.h"
#include "trig.h"
#include "hyp.h"
#include "SumTerms.h"

int main()
{
	trig* t1 = new trig(1, 1, "sin");
	polyterm *t2 = new polyterm(1, 1);
	ProdTerms* pt1 = new ProdTerms();
	pt1->add(t2);
	pt1->add(t1);
	trig *func1 = new trig(2, 2, "cos");
	polyterm *func2 = new polyterm(1, 6);
	SumTerms *st1 = new SumTerms(func1);
	SumTerms *st2 = new SumTerms(func2);
	hyp* t3 = new hyp(1, 1, "sinh");
	st1->add(pt1);
	st2->add(st1);
	st2->add(t3);
	((((t3->deriv())->deriv())->deriv()))->display();
	
}