#include <iostream>

class Complex
{
	float real, imaginar;
public:
    // constructor de initializare:
    explicit Complex(float re = 0, float im = 0);

    // constructor de copiere:
    Complex(const Complex& ob);

    //destuctor:
    ~Complex();

    //supraincarcare =:
    Complex& operator=(const Complex&);

    friend istream& operator >> (istream & in, Complex & nr);
    friend ostream& operator << (ostream & out, Complex & nr);
};
