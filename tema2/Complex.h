#ifndef TEMAPOO2_COMPLEX_H
#define TEMAPOO2_COMPLEX_H
#include <iostream>

using namespace std;

template <class T>
class Complex
{
    T real, imaginar;
public:
    // constructor de initializare:
    explicit Complex(T re = 0, T im = 0);

    // constructor de copiere:
    Complex(const Complex<T>& ob) = default;

    //destuctor:
    ~Complex() = default;

    //supraincarcare =:
    Complex<T>& operator=(const Complex<T>&) = default;
    friend istream& operator >> (istream& in, Complex<T>& nr);
    friend ostream& operator << (ostream& out, Complex<T>& nr);
    friend Complex<T> operator+(Complex<T> a, Complex<T> b);
    friend Complex<T> operator*(Complex<T> a, Complex<T> b);
    friend Complex<T> operator*(T a, Complex<T> b);

    friend bool operator==(const Complex<T>& a, const Complex<T>& b);
    friend bool operator!=(const Complex<T>& a, const Complex<T>& b);

    void setReal(T r);
    void setImaginar(T i);
    float getReal();
    float getImaginar();
};

#endif //! TEMAPOO2_COMPLEX_H
