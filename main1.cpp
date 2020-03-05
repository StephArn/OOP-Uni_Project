#include <iostream>
#include <math.h>

using namespace std;

class Numar_Complex
{
    double real,imaginar;
public:
    Numar_Complex();
    Numar_Complex(Numar_Complex &ob){};
    //~Numar_Complex();
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
    inline int modul()
    {
        cout<<sqrt(real*real + imaginar*imaginar);
    }

};

int main()
{

    return 0;
}
