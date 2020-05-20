#pragma once
#include <iostream>
#include "Matrice.h"
#include "Complex.h"
#ifndef TEMAPOO2_MATRICE_PATRATICA_H
#define TEMAPOO2_MATRICE_PATRATICA_H



class Matrice_patratica : public Matrice
{

public:
    explicit Matrice_patratica(int lin = 0, int col = 0) : Matrice(lin, col) {};

    Matrice_patratica(const Matrice_patratica&) = default;

    ~Matrice_patratica() override = default;

    Matrice_patratica& operator=(const Matrice_patratica&) = default;

    friend std::ostream& operator <<(std::ostream& output, Matrice_patratica& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala()override;

    friend Complex det(Matrice_patratica& matrix, int n);

};



#endif // !TEMAPOO2_MATRICE_PATRATICA_H
