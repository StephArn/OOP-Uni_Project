#pragma once
#include <iostream>
#include "Matrice.h"
#include "Complex.h"
#ifndef TEMAPOO2_MATRICE_OARECARE_H
#define TEMAPOO2_MATRICE_OARECARE_H

template <class T>
class Matrice_oarecare :public Matrice<T>
{
public:
    explicit Matrice_oarecare(int lin = 0, int col = 0) : Matrice<T>(lin, col) {};

    Matrice_oarecare(const Matrice_oarecare<T>&) = default;

    ~Matrice_oarecare() override = default;

    Matrice_oarecare<T>& operator =(Matrice_oarecare<T>& ob) = default;

    friend std::ostream& operator <<(std::ostream& output, const Matrice_oarecare<T>& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala() override;
};

#endif // !TEMAPOO2_MATRICE_OARECARE_H
