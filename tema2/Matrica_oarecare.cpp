#include "Matrice_oarecare.h"

std::ostream& operator <<(std::ostream& output, const Matrice_oarecare& mat) {
    for (int i = 0; i < mat.lin; i++) {
        for (int j = 0; j < mat.col; j++)
            output << mat.v[i][j] << " ";
        output << '\n';
    }
    return output;
}
int Matrice_oarecare::verifica_triunghiulara() {
    int i, j, ok1 = 1, ok2 = 1, rez;
    if (lin != col) return 0;
    for (i = 1; i < lin; i++) {
        for (j = 0; j < i; j++) {
            if (v[i][j] != Complex(0, 0)) {
                ok1 = 0;
                break;
            }
            if (ok1 == 0) break;
        }
    }

    for (i = 0; i < lin - 1; i++) {
        for (j = i + 1; j < lin; j++) {
            if (v[i][j] != Complex(0, 0)) {
                ok2 = 0;
                break;
            }
            if (ok2 == 0) break;
        }
    }

    if (ok1 == 1) {
        if (ok2 == 1) rez = 3;
        else rez = 1;
    }
    else if (ok2 == 1) rez = 2;
    else rez = 0;

    return rez;
}

void Matrice_oarecare::verifica_diagonala() {
    int triunghiulara;
    triunghiulara = verifica_triunghiulara();
    if (triunghiulara == 3)
    {
        std::cout << "Matricea este diagonala.";
        return;
    }
    else if (triunghiulara == 2 or triunghiulara == 1)
    {
        std::cout << "Matricea nu este diagonala.";
        return;
    }
    else std::cout << "Matricea nu este nici triunghiulara, nici diagonala.";
}
