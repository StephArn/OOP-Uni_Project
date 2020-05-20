#pragma once

#ifndef TEMAPOO2_MATRICE_OARECARE_H
#define TEMAPOO2_MATRICE_OARECARE_H
#include <iostream>
#include "Matrice.h"

class Matrice_oarecare :public Matrice
{
public:
    explicit Matrice_oarecare(int lin = 0, int col = 0) : Matrice(lin, col) {};

    Matrice_oarecare(const Matrice_oarecare&) = default;

    ~Matrice_oarecare() override = default;

    Matrice_oarecare& operator =(Matrice_oarecare& ob) = default;

    friend std::ostream& operator <<(std::ostream& output, const Matrice_oarecare& mat);

    int verifica_triunghiulara();

    void verifica_diagonala() override;
};

#endif // !TEMAPOO2_MATRICE_OARECARE_H
