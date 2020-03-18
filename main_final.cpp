#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Numar_Complex {
    double real, imaginar;

public:
    // constructor de initializare:
    Numar_Complex(double re=0, double im=0)
    {
        real = re;
        imaginar = im;
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

    ostream& afisare(ostream& out)
    {
        double a, b;
        if (imaginar == 0)
            cout << real;

        else if (real == 0)
                cout << imaginar << "i";

        else
        {
            cout << real <<" ";
            if(imaginar > 0) cout<<"+";
            cout<<imaginar<<"*i";
        }
        return out;
    }
    double modul()
    {
        return std::sqrt(real * real + imaginar * imaginar);
    }

    Numar_Complex sqrt()
    {
        Numar_Complex rad2;
        double m=modul();
        rad2.real = std::sqrt((m + this->real) / 2);

        if (imaginar < 0) {
            rad2.imaginar = -1 * std::sqrt((m - this->real) / 2);
        }
        else
            rad2.imaginar = std::sqrt((m - this->real) / 2);

        return rad2;
    }
    //destuctor:
    ~Numar_Complex();
};

Numar_Complex::~Numar_Complex() = default;

istream& operator>>(istream& in, Numar_Complex& nr)
{
    in >> nr.real >> nr.imaginar;
    return in;
}

ostream& operator<<(ostream& out, Numar_Complex& nr)
{
    return nr.afisare(out);
}

Numar_Complex operator+(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex sum;
    sum.setReal(a.real + b.real);
    sum.setImaginar(a.imaginar + b.imaginar);
    return sum;
}

Numar_Complex operator*(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex prod;
    if (a.imaginar == 0) {
        prod.setReal(a.real * b.real);
        prod.setImaginar(a.real * b.imaginar);
    }
    else if (b.imaginar == 0) {
        prod.setReal(a.real * b.real);
        prod.setImaginar(b.real * a.imaginar);
    }
    else {
        prod.setReal(a.real * b.real - a.imaginar * b.imaginar);
        prod.setImaginar(a.real * b.imaginar + b.real * a.imaginar);
    }
    return prod;
}

Numar_Complex operator*(double a, Numar_Complex b)
{
    return Numar_Complex(b.real * a, b.imaginar * a);
}
Numar_Complex operator/(Numar_Complex a, Numar_Complex b)
{
    Numar_Complex cat;
    cat.setReal((a.real * b.real + a.imaginar * b.imaginar)
        / (b.real * b.real + b.imaginar * b.imaginar));
    cat.setImaginar((b.real * a.imaginar - a.real * b.imaginar)
        / (b.real * b.real + b.imaginar * b.imaginar));
    return cat;
}

int main()
{
    Numar_Complex a, b, c, r, delta, sol1, sol2;
    cin >> a;
    cin >> b;
    cin >> c;
    delta = b * b +(-4.0) * a * c;
    r = delta.sqrt();
    sol1 = (-1.0 * (b + r)) / (2.0 * a);
    sol2 = (-1.0 * b + r) / (2.0 * a);
    cout << "Prima solutie: " << sol1 << endl;
    cout << "A doua solutie: "<< sol2;

    return 0;
}
