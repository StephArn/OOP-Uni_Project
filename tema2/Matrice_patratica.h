#pragma once
#include <iostream>
#include "Matrice.h"
#include "Complex.h"
#ifndef TEMAPOO2_MATRICE_PATRATICA_H
#define TEMAPOO2_MATRICE_PATRATICA_H

template <class T>

class Matrice_patratica : public Matrice<T>
{

public:
    explicit Matrice_patratica(int lin = 0, int col = 0) : Matrice<T>(lin, col) {};

    Matrice_patratica(const Matrice_patratica<T>&) = default;

    ~Matrice_patratica<T>() override = default;

    Matrice_patratica<T>& operator=(const Matrice_patratica<T>&) = default;

    friend std::ostream& operator <<(std::ostream& output, Matrice_patratica<T>& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala()override;

    friend Complex<T> det(Matrice_patratica<T>& matrix, int n);

};



#endif // !TEMAPOO2_MATRICE_PATRATICA_H
