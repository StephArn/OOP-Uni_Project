#ifndef TEMAPOO2_COMPLEX_H
#define TEMAPOO2_COMPLEX_H

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

    friend std::istream& operator >> (std::istream& in, Complex& nr);
    friend std::ostream& operator << (std::ostream& out, Complex& nr);

    friend Complex operator+(Complex a, Complex b);
    friend Complex operator*(Complex a, Complex b);
    friend Complex operator*(int a, Complex b);

    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);

    void setReal(float r);
    void setImaginar(float i);
    float getReal();
    float getImaginar();
};

#endif //! TEMAPOO2_COMPLEX_H
