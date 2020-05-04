#pragma once
#include <iostream>
#include "Matrice.h"
#include "Complex.h"
#ifndef TEMAPOO2_MATRICE_PATRATICA_H
#define TEMAPOO2_MATRICE_PATRATICA_H



class Matrice_patratica : public Matrice {
    int dim;
public:
    explicit Matrice_patratica(int dim = 1);

    Matrice_patratica(const Matrice_patratica&);

    ~Matrice_patratica();

    Matrice_patratica& operator=( Matrice_patratica&);

    friend std::ostream& operator <<(std::ostream& output, const Matrice_patratica& mat);

    friend std::istream& operator >>(std::istream& input, Matrice_patratica& mat);

    int verifica_triunghiulara() override;

    void verifica_diagonala()override;

    Complex det(Matrice_patratica,int);
};



#endif // !TEMAPOO2_MATRICE_PATRATICA_H

