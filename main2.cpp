#include <iostream>
#include <cmath>

using namespace std;

class Numar_Complex
{
    new double real,imaginar;
public:
    Numar_Complex();
    Numar_Complex(Numar_Complex &ob){};
    friend void set();
    friend Numar_Complex get();
    friend Numar_Complex +();
    friend Numar_Complex *();
    friend Numar_Complex /();
    
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
    int modul()
    {
        cout<<sqrt(real*real + imaginar*imaginar);
    }
    ~Numar_Complex();

};
Numar_Complex set(){
    
}
Numar_Complex get(){
    return 
}

Numar_Complex +(){
    
}

Numar_Complex *(){
    
}

Numar_Complex /(){
    
}
int main()
{

    return 0;
}