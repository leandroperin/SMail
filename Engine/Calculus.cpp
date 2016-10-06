//---------------------------------------------------------------------------


#pragma hdrstop

#include "Calculus.h"

#define PI 3.1415

//---------------------------------------------------------------------------

#pragma package(smart_init)

double Calculus::RNG() {
	return rand() / ((double) RAND_MAX);
}

double Calculus::uniformCalculation(double a, double b) {
	double u = Calculus::RNG();
	return a + u * (b - a);
}

double Calculus::exponencialCalculation(double y) {
	double u = Calculus::RNG();
	while (u == 1) {
		u = Calculus::RNG();
    }
	return (-1 / y) * log(1 - u);
}

double Calculus::triangularCalculation(double a, double b, double c) {
	double u = Calculus::RNG();
	if (u >= 0 && u <= (b-a)/(c-a)) {
		return a + sqrt(u*(b-a)*(c-a));
	}
	return c - sqrt((1-u)*(c-b)*(c-a));
}

double Calculus::normalCalculation(double a, double b) {
	double u1 = Calculus::RNG();
	while (u1 == 0) {
		u1 = Calculus::RNG();
	}
	double u2 = Calculus::RNG();

	double Z = sqrt(-2 * log(u1)) * cos(2*PI*u2);

	return a + b * Z;
}