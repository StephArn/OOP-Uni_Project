#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Numar_Complex {
    double real, imaginar;

public:
    // constructor de initializare:
    Numar_Complex(double ri, double ii)
    {
        real = ri;
        imaginar = ii;
    }
    // constructor de copiere:
    Numar_Complex(const Numar_Complex& ob)
    {
        this->real = ob.real;
        this->imaginar = ob.imaginar;
    }

    void setReal(double r)
    {
        real = r;
    }

    void setImaginar(double i)
    {
        imaginar = i;
    }

    double getReal()
    {
        return real;
    }

    double getImaginar()
    {
        return imaginar;
    }

    friend Numar_Complex operator+(Numar_Complex a, Numar_Complex b);
    friend Numar_Complex operator*(Numar_Complex a, Numar_Complex b);
    friend Numar_Complex operator*(double a, Numar_Complex b);
    friend Numar_Complex operator/(Numar_Complex a, Numar_Complex b);
    friend istream& operator>>(istream& in, Numar_Complex& nr);
    friend ostream& operator<<(ostream& out, Numar_Complex& nr);

    void afisare()
    {
        double a, b;
        if (imaginar == 0) {
            cout << real;
        }
        if (real == 0)
            if (imaginar > 0)
                cout << "i*" << imaginar;
            else
                cout << "-i*" << (-1) * imaginar;
        else if (imaginar > 0)
            cout << real << " + i*" << imaginar;
        else if (imaginar < 0)
            cout << real << " - i*" << (-1) * imaginar;
    }
    double modul()
    {
        return std::sqrt(real * real + imaginar * imaginar);
    }

    Numar_Complex sqrt()
    {
        Numar_Complex rad2(0, 0);
        rad2.real = std::sqrt(
            (std::sqrt((this->real) * (this->real) + (this->imaginar) * (this->imaginar))
                + this->real)
            / 2);

        if (imaginar < 0) {
            rad2.imaginar = (-1) * std::sqrt((std::sqrt((this->real) * (this->real)
                                                  + (this->imaginar) * (this->imaginar))
                                                 - this->real)
                                       / 2);
        }
        else
            rad2.imaginar = std::sqrt(
                (std::sqrt((this->real) * (this->real) + (this->imaginar) * (this->imaginar))
                    - this->real)
                / 2);

        return rad2;
    }
    //destuctor:
    ~Numar_Complex();
};

Numar_Complex::~Numar_Complex()
{
}

istream& operator>>(istream& in, Numar_Complex& nr)
{
    in >> nr.real >> nr.imaginar;
    return in;
}

ostream& operator<<(ostream& out, Numar_Complex& nr)
{
    nr.afisare();
    return out;
}

Numar_Complex operator+(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex sum(0, 0);
    sum.setReal((a.getReal()) + b.getReal());
    sum.setImaginar((a.getImaginar()) + b.getImaginar());
    return sum;
}

Numar_Complex operator*(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex prod(0, 0);
    if (a.getImaginar() == 0) {
        prod.setReal((a.getReal()) * b.getReal());
        prod.setImaginar((a.getReal()) * b.getImaginar());
    }
    else if (b.getImaginar() == 0) {
        prod.setReal((a.getReal()) * b.getReal());
        prod.setImaginar(b.getReal() * (a.getImaginar()));
    }
    else {
        prod.setReal((a.getReal()) * b.getReal() - a.getImaginar() * b.getImaginar());
        prod.setImaginar((a.getReal()) * b.getImaginar() + b.getReal() * (a.getImaginar()));
    }
    return prod;
}

Numar_Complex operator*(double a, Numar_Complex b)
{
    Numar_Complex prodi(0, 0);
    prodi.setReal(b.getReal() * a);
    prodi.setImaginar(b.getImaginar() * a);
    return prodi;
}
Numar_Complex operator/(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex cat(0, 0);
    cat.setReal(((a.getReal()) * b.getReal() + (a.getImaginar()) * b.getImaginar())
        / (b.getReal() * b.getReal() + b.getImaginar() * b.getImaginar()));
    cat.setImaginar((b.getReal() * (a.getImaginar()) - (a.getReal()) * b.getImaginar())
        / (b.getReal() * b.getReal() + b.getImaginar() * b.getImaginar()));
    return cat;
}

int main()
{
    Numar_Complex a(0, 0), b(0, 0), c(0, 0), r(0, 0), delta(0, 0), sol1(0, 0), sol2(0, 0);
    cin >> a;
    cin >> b;
    cin >> c;
    delta = b * b + (-4.0) * a * c;
    r = delta.sqrt();
    sol1 = ((-1.0) * (b + r)) / (2.0 * a);
    sol2 = ((-1.0) * b + r) / (2.0 * a);
    cout << "Prima solutie: ";
    sol1.afisare();
    cout << endl;
    cout << "A doua solutie: ";
    sol2.afisare();
    return 0;
}