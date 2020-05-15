#pragma once
#include <iostream>
#include "Matrice.h"
#include "Complex.h"
#ifndef TEMAPOO2_MATRICE_PATRATICA_H
#define TEMAPOO2_MATRICE_PATRATICA_H



class Matrice_patratica : public Matrice {
 
public:
    explicit Matrice_patratica(int col = 1) : Matrice(col, col,Complex(0,0)) {};

    Matrice_patratica(const Matrice_patratica&) = default;

    ~Matrice_patratica() = default;

    Matrice_patratica& operator=(const Matrice_patratica&) =default;

    //friend void swap(Matrice_patratica& a, Matrice_patratica& b);

    friend std::ostream& operator <<(std::ostream& output, Matrice_patratica& mat);

    friend std::istream& operator >>(std::istream& input, Matrice_patratica& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala()override;

    Complex det(Matrice_patratica matrix,int n);

};



#endif // !TEMAPOO2_MATRICE_PATRATICA_H

