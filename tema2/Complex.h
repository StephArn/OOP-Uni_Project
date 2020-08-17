#ifndef TEMAPOO2_COMPLEX_H
#define TEMAPOO2_COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
    float real, imaginar;
public:
    // constructor de initializare:
    explicit Complex(float re = 0, float im = 0);

    // constructor de copiere:
    Complex(const Complex& ob) = default;

    //destuctor:
    ~Complex() = default;

    //supraincarcare =:
    Complex& operator=(const Complex&) = default;

    friend istream& operator >> (istream& in, Complex& nr);
    friend ostream& operator << (ostream& out, Complex& nr);

    friend Complex operator+(Complex a, Complex b);
    friend Complex operator*(Complex a, Complex b);
    friend Complex operator*(float a, Complex b);

    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);

    void setReal(float r);
    void setImaginar(float i);
    float getReal();
    float getImaginar();
};

#endif //! TEMAPOO2_COMPLEX_H
