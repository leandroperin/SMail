//---------------------------------------------------------------------------

#ifndef CalculusH
#define CalculusH

#include <stdlib>
#include <time.h>
#include <math.h>
//---------------------------------------------------------------------------
class Calculus {
 public:
 	static double RNG();
	static double uniformCalculation(double, double);
	static double exponencialCalculation(double);
	static double triangularCalculation(double, double, double);
	static double normalCalculation(double, double);
};

#endif
