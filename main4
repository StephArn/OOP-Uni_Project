#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Numar_Complex
{
    double real,imaginar;
public:
    Numar_Complex(double ri, double ii)
    {
        real=ri;
        imaginar=ii;
    }
    Numar_Complex(const Numar_Complex &ob)
    {
        real=ob.real;
        imaginar=ob.imaginar;
    }
    
    void setReal(double r)
    {
    real=r;
    }
    
    void setImaginar(double i)
    {
    imaginar=i;
    }
    
    double getReal()
    {
        return real;
    }
    double getImaginar()
    {
        return imaginar;
    }
    Numar_Complex operator+(Numar_Complex a);
    Numar_Complex operator*(Numar_Complex a);
    Numar_Complex operator/(Numar_Complex a);
    
    void afisare()
    {
       if (imaginar == 0)
            cout<<real;
       if(real == 0)
            if (imaginar > 0)
                    cout<<"i*"<<imaginar;
            else cout<<"-i*"<<(-1)*imaginar;
       else
            if (imaginar > 0)
                    cout<<real<<" + i*"<<imaginar;
            else cout<<real<<" - i*"<<imaginar;
    }
    double modul()
    {
        cout<<sqrt(real*real + imaginar*imaginar);
    }
    
    ~Numar_Complex();

};

istream&operator>>(istream &in, Numar_Complex&nr)
{
    in>>nr.real>>nr.imaginar;
    return in;
}

ostream&operator<<(ostream &out,Numar_Complex&nr)
{
    nr.afisare();
    return out;
}

Numar_Complex Numar_Complex::operator+(Numar_Complex a)
{
    Numar_Complex sum;
    sum.real = (this->real) + a.real;
    sum.imaginar = (this->imaginar) + a.imaginar;
    return sum;
}

Numar_Complex Numar_Complex::operator*(Numar_Complex a)
{
    Numar_Complex prod;
    prod.real = (this->real)*a.real - (this->imaginar)*a.imaginar;
    prod.imaginar = (this->real)*a.imaginar + a.real*(this->imaginar);
    return prod;
}

Numar_Complex Numar_Complex::operator/(Numar_Complex a)
{
    Numar_Complex cat;
    cat.real = ((this->real)*a.real + (this->imaginar)*a.imaginar) / (a.real*a.real+a.imaginar*a.imaginar);
    cat.imaginar = (a.real*(this->imaginar) - (this->real)*a.imaginar) / (a.real*a.real+a.imaginar*a.imaginar);
    return cat;
}

int main()
{

    return 0;
}