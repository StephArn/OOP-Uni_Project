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
    friend Numar_Complex operator+(Numar_Complex&,Numar_Complex&);
    friend Numar_Complex operator*(Numar_Complex&,Numar_Complex&);
    friend Numar_Complex operator/(Numar_Complex&,Numar_Complex&);
    
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

Numar_Complex operator+(Numar_Complex&a,Numar_Complex&b)
{
    Numar_Complex sum;
    sum.real= a.real + b.real;
    sum.imaginar= a.imaginar + b.imaginar;
    return sum;
}

Numar_Complex operator*(Numar_Complex&a,Numar_Complex&b)
{
    Numar_Complex prod;
    prod.real= a.real*b.real - a.imaginar*b.imaginar;
    prod.imaginar= a.real*b.imaginar + b.real*a.imaginar;
    return prod;
}

Numar_Complex operator/(Numar_Complex&a,Numar_Complex&b)
{
    Numar_Complex cat;
    cat.real = (a.real*b.real + a.imaginar*b.imaginar) / (b.real*b.real+b.imaginar*b.imaginar);
    cat.imaginar = (b.real*a.imaginar - a.real*b.imaginar) / (b.real*b.real+b.imaginar*b.imaginar);
    return cat;
}

int main()
{

    return 0;
}