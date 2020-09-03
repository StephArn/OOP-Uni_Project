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
    template <class A>
    friend istream& operator >> (istream& in, Complex<A>& nr);
    template <class B>
    friend ostream& operator << (ostream& out, Complex<B>& nr);
    template <class C>
    friend Complex<C> operator+(Complex<C> a, Complex<C> b);
    template <class D>
    friend Complex<D> operator*(Complex<D> a, Complex<D> b);
    friend Complex<T> operator*(T a, Complex<T> b);

    friend bool operator==(const Complex<T>& a, const Complex<T>& b);
    friend bool operator!=(const Complex<T>& a, const Complex<T>& b);

    void setReal(T r);
    void setImaginar(T i);
    float getReal();
    float getImaginar();
};

#endif //! TEMAPOO2_COMPLEX_H
