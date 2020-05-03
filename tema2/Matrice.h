#ifndef  TEMAPOO2_MATRICE_H

#define TEMAPOO2_MATRICE_H


#include "Complex.h"
class Matrice
{
protected:
    Complex **v;
    int lin, col;

public:
    explicit Matrice(int col = 1, int lin = 1, Complex nr = Complex(0, 0));

    Matrice(const Matrice& mat);

    virtual ~Matrice();

    friend std::ostream& operator <<(std::ostream& output, const Matrice& mat);

    friend std::istream& operator >>(std::istream& input, Matrice& mat);

    virtual void verifica(Matrice& matrice);

    //Matrice& operator =(Matrice mat);

};

#endif // ! TEMAPOO2_MATRICE_H
