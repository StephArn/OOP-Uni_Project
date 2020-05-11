#pragma once
#include <iostream>
#include "Matrice.h"
#ifndef TEMAPOO2_MATRICE_OARECARE_H
#define TEMAPOO2_MATRICE_OARECARE_H
class Matrice_oarecare :public Matrice
{
	int lin, col;
    explicit Matrice_oarecare(int col = 1, int lin = 1) : Matrice(col, lin) {};

    Matrice_oarecare(const Matrice_oarecare&) = default;

    ~Matrice_oarecare() = default;

    Matrice_oarecare& operator =(Matrice_oarecare& ob) = default;

    friend std::ostream& operator <<(std::ostream& output, const Matrice_oarecare& mat);

    friend std::istream& operator >>(std::istream& input, Matrice_oarecare& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala() override;
};

#endif // !TEMAPOO2_MATRICE_OARECARE_H
