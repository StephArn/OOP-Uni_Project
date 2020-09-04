#ifndef  TEMAPOO2_MATRICE_H

#define TEMAPOO2_MATRICE_H


#include "Complex.h"
template <class T>
class Matrice
{
protected:
    Complex<T>** v;
    int col, lin;

public:
    explicit Matrice(int col = 0, int lin = 0, Complex<T> nr = Complex<T>(0, 0));

    Matrice(const Matrice<T>& mat);

    virtual ~Matrice();

    friend std::ostream& operator <<(std::ostream&, const Matrice<T>&);

    friend std::istream& operator >>(std::istream&, Matrice<T>&);

    Matrice& operator =(Matrice<T> const& ob);

    virtual int verifica_triunghiulara() = 0;

    virtual void verifica_diagonala() = 0;

    Complex<T> setElem(int i, int j, Complex<T> x);

    int get_lin();
    int get_col();
    Complex<T>** get_mat();



};

#endif // ! TEMAPOO2_MATRICE_H
