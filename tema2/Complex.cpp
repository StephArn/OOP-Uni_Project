#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(float re = 0, float im = 0)
{
	real = re;
	imaginar = im;
}

Complex::Complex(const Complex& ob) = default;

Complex::~Complex() = default;

Complex& Complex::operator=(const Complex&) = default;

istream& operator>>(istream& in, Complex& nr)
{
	in >> nr.real >> nr.imaginar;
	return in;
}

ostream& operator<<(ostream& out, Complex& nr)
{
	out<<nr.real<<nr.imaginar;
	return out;
}
